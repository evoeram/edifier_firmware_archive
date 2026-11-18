#!/usr/bin/env python3
"""B3.1: reconstruct RAM overlays from the crt0 copy table and resolve all
far call targets (calls outside the XIP flash window).

crt0 (0x06000102..0x0600018c in mr5_app_disasm.txt) contains inline copy
loops:  r4 = ram_dst; r1 = flash_src(VA); r2 = size; rep {[r4++=4]=[r1++=4]}
and BSS zero loops (r3 = dst; r1 = 0).  This script:

  1. parses those loops from the listing,
  2. builds the RAM overlay map (ram range -> flash offset range),
  3. collects every far call target from the listing,
  4. classifies targets: ROM (br28 rom.lst labels) / RAM (copy regions) /
     unknown, and names RAM targets via b3_signatures.json (direct elf_addr
     hits) or via the flash equivalent (b42_funcs.json names).

output: disasm/b3_far_targets.json
"""
import io
import json
import re
import sys

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
ROM_LST = (r'C:\Users\User\AppData\Local\Temp\opencode\sdk\ac701n'
           r'\ac701n_soundbox-main\sdk\cpu\br28\tools\rom.lst')
XIP_BASE = 0x06000100

line_re = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+?)\s*$')
imm_re = re.compile(r'^(?:r\d|ssp|sp) = (-?\d+)$')


def parse_listing():
    insns = []  # (addr, size, text)
    for l in io.open(SRC + r'\disasm\mr5_app_disasm.txt', encoding='utf-8',
                     errors='replace'):
        m = line_re.match(l.rstrip())
        if not m:
            continue
        insns.append((int(m.group(1), 16),
                      len(m.group(2).split()), m.group(3).strip()))
    return insns


def parse_crt0_copies(insns, lo=0x06000102, hi=0x06000200):
    """Extract copy/zero loops.

    Copy:   r4 = ram_dst; r1 = flash_src; r2 = size; rep {[r4++=4]=[r3]}
    Zero:   r3 = ram_dst; r1 = 0;         r2 = size; rep {[r3++=4]=r1}
    Walk back from each '[rX++=4] = rY' and collect immediate loads.
    """
    regions = []
    for i, (a, sz, t) in enumerate(insns):
        if not (lo <= a <= hi):
            continue
        m = re.match(r'\[(r\d)\+\+=4\] = (r\d)$', t)
        if not m:
            continue
        dst_reg = m.group(1)
        loads = {}
        for j in range(i - 1, max(0, i - 20), -1):
            aa, ss, tt = insns[j]
            if aa <= a - 56:
                break
            mm = imm_re.match(tt)
            if mm:
                reg = tt.split(' =')[0]
                loads.setdefault(reg, int(mm.group(1)) & 0xFFFFFFFF)
        if dst_reg not in loads:
            continue
        dst = loads[dst_reg]
        srcs = {r: v for r, v in loads.items() if v >= 0x06000000}
        size = loads.get('r2')
        if srcs:
            sv = max(srcs.values())
            regions.append({'kind': 'copy', 'dst': dst, 'src': sv,
                            'size': size, 'at': f'{a:08x}'})
        else:
            if size:  # zero loop only if a size was loaded nearby
                regions.append({'kind': 'zero', 'dst': dst, 'src': None,
                                'size': size, 'at': f'{a:08x}'})
    return regions


def far_targets(insns):
    tgts = {}
    for a, sz, t in insns:
        m = re.match(r'call (-?\d+)$', t)
        if not m:
            continue
        tgt = (a + sz + int(m.group(1))) & 0xFFFFFFFF
        if tgt < XIP_BASE or tgt >= XIP_BASE + (1 << 24):
            tgts.setdefault(tgt, []).append(a)
    return tgts


def rom_labels(path):
    sym = {}
    cur = None
    for l in io.open(path, encoding='utf-8', errors='replace'):
        s = l.rstrip()
        if s and not s[0].isspace() and s.endswith(':'):
            cur = s[:-1]
        elif cur:
            m = re.match(r'\s*([0-9a-f]+):', l)
            if m:
                sym.setdefault(int(m.group(1), 16), cur)
                cur = None
    return sym


def main():
    insns = parse_listing()
    regions = parse_crt0_copies(insns)
    print('crt0 regions:')
    for r in regions:
        print('  ', r)

    tgts = far_targets(insns)
    print(f'far call targets: {len(tgts)}, sites: '
          f'{sum(len(v) for v in tgts.values())}')

    syms = rom_labels(ROM_LST)
    print('rom.lst labels:', len(syms))

    sigs = json.load(io.open(SRC + r'\disasm\b3_signatures.json',
                             encoding='utf-8'))
    # direct RAM matches: elf_addr -> name (flash addr known too)
    ram_direct = {}
    for k, v in sigs.items():
        ea = int(v['elf_addr'], 16)
        if 0x100000 <= ea < 0x140000:
            ram_direct[ea] = {'name': v['name'], 'flash': int(k, 16)}

    b42 = json.load(io.open(SRC + r'\disasm\b42_funcs.json',
                            encoding='utf-8'))
    faddrs = sorted(int(k, 16) for k in b42)

    import bisect
    import csv

    # Ghidra names for flash equivalents (named functions only)
    ghidra_names = {}
    with open(SRC + r'\ghidra_export\functions.csv', encoding='utf-8') as fh:
        for row in csv.DictReader(fh):
            nm = row.get('name', '')
            if nm and not nm.startswith(('FUN_', 'sub_', 'thunk_', 'u_')):
                ghidra_names[int(row['entry'], 16)] = nm

    # byte-matched SDK functions in flash: [(flash_lo, flash_hi, name)]
    matched = []
    for k, v in sigs.items():
        lo = int(k, 16)
        matched.append((lo, lo + v['size'], v['name']))
    matched.sort()
    m_lo = [m[0] for m in matched]

    def name_by_match(va):
        i = bisect.bisect_right(m_lo, va) - 1
        if i >= 0 and va < matched[i][1]:
            off = va - matched[i][0]
            return matched[i][2] + (f'+{off}' if off else '')
        return ghidra_names.get(va)

    def func_at_flash(off):
        va = XIP_BASE + off
        i = bisect.bisect_right(faddrs, va) - 1
        if i >= 0:
            fa = faddrs[i]
            if va < fa + b42[f'{fa:08x}']['size']:
                return fa
        return None

    out = {}
    n_rom = n_ram = n_unk = 0
    ram_sorted = sorted((r for r in regions if r['kind'] == 'copy' and
                         r['size']), key=lambda r: r['dst'])
    for t, sites in sorted(tgts.items()):
        entry = {'sites': len(sites), 'callers': [f'{a:08x}' for a in
                                                  sorted(sites)[:12]]}
        if t in ram_direct:
            entry.update(kind='ram-direct', name=ram_direct[t]['name'],
                         flash_equiv=f"{ram_direct[t]['flash']:08x}")
            n_ram += 1
        else:
            reg = next((r for r in ram_sorted if
                        r['dst'] <= t < r['dst'] + r['size']), None)
            if reg is not None:
                off = reg['src'] - XIP_BASE + (t - reg['dst'])
                va = XIP_BASE + off
                entry.update(kind='ram-overlay',
                             flash_equiv=f'{va:08x}',
                             region=f"{reg['dst']:06x}+{reg['size']}")
                nm = name_by_match(va)
                if nm:
                    entry['name'] = nm
                else:
                    fa = func_at_flash(off)
                    if fa:
                        entry['func_at'] = f'{fa:08x}'
                n_ram += 1
            elif t in syms:
                entry.update(kind='rom', name=syms[t])
                n_rom += 1
            else:
                below = [a for a in sorted(syms) if a <= t]
                near = f"{below[-1]:x}+{t - below[-1]}" if below else '?'
                entry.update(kind='rom', name='rom_' + f'{t:x}',
                             near_label=near)
                n_rom += 1
        out[f'{t:08x}'] = entry
    named = sum(1 for e in out.values() if 'name' in e)
    print(f'ram: {n_ram}, rom: {n_rom}; named: {named}/{len(out)}')
    json.dump(out, io.open(SRC + r'\disasm\b3_far_targets.json', 'w',
                           encoding='utf-8'), indent=0)
    print('wrote', SRC + r'\disasm\b3_far_targets.json')


if __name__ == '__main__':
    main()
