#!/usr/bin/env python3
"""B3.1 final: apply confidently-identified semantic names + ROM stub names
to disasm/b3_far_targets.json.  Also copies the overlay decompile dump into
source/disasm/.
"""
import io
import json
import shutil

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
FT = SRC + r'\disasm\b3_far_targets.json'

targets = json.load(io.open(FT, encoding='utf-8'))

semantic = {
    '0010db7e': ('os_enter_critical',
                 'per-core nest counters 0x1083dc/0x1083ec inc; '
                 'IRQ mask 0xffe1a8+cnum*0x800 := 6'),
    '0010dbcc': ('os_exit_critical',
                 'counters dec; IRQ mask cleared when nest==0'),
    '0011000c': ('delay_loop',
                 'pure countdown loop (param_1 iterations)'),
}
for k, (nm, why) in semantic.items():
    if k in targets and 'name' not in targets[k]:
        targets[k]['name'] = nm
        targets[k]['via'] = 'semantic-decompile'
        targets[k]['evidence'] = why

# ROM stubs: near label from rom.lst (labels map addr->name)
rom_syms = {}
cur = None
for l in io.open(r'C:\Users\User\AppData\Local\Temp\opencode\sdk\ac701n'
                 r'\ac701n_soundbox-main\sdk\cpu\br28\tools\rom.lst',
                 encoding='utf-8', errors='replace'):
    s = l.rstrip()
    if s and not s[0].isspace() and s.endswith(':'):
        cur = s[:-1]
    elif cur:
        import re as _re
        m = _re.match(r'\s*([0-9a-f]+):', l)
        if m:
            rom_syms.setdefault(int(m.group(1), 16), cur)
            cur = None
rom_addrs = sorted(rom_syms)
import bisect
for k, e in targets.items():
    if e['kind'] != 'rom' or (e.get('via') == 'rom.lst-near'):
        continue
    t = int(k, 16)
    i = bisect.bisect_right(rom_addrs, t) - 1
    if i >= 0:
        a = rom_addrs[i]
        off = t - a
        if off <= 64:
            e['name'] = rom_syms[a] + (f'+{off}' if off else '')
            e['via'] = 'rom.lst-near'
            continue
    e['name'] = 'rom_' + f'{t:x}'
    e['via'] = 'unknown'

named = sum(1 for e in targets.values() if 'name' in e)
print(f'named: {named}/{len(targets)}')
kinds = {}
for e in targets.values():
    kinds[e.get('via', e['kind'])] = kinds.get(e.get('via', e['kind']), 0) + 1
print(kinds)
json.dump(targets, io.open(FT, 'w', encoding='utf-8'), indent=0)

shutil.copy(r'C:\Users\User\AppData\Local\Temp\opencode\decomp_overlay.c',
            SRC + r'\disasm\b3_overlay_decomp.c')
print('decompile dump copied to disasm/b3_overlay_decomp.c')

# top targets summary
top = sorted(targets.items(), key=lambda x: -x[1]['sites'])[:12]
for k, e in top:
    print(f"{k} sites={e['sites']:4d} name={e.get('name', '-'):24s} "
          f"flash={e.get('flash_equiv', '-')}")
