#!/usr/bin/env python3
"""B3.1b: name RAM overlay functions by aligning sdk.elf RAM-region function
code against the flash source ranges of the crt0 copy regions.

For each FUNC symbol with VA in 0x100000..0x140000 of br28 sdk.elf, search
its code (several 24-byte anchor windows) inside the overlay source ranges
in flash.  A unique hit names the flash location; combined with the overlay
map (tools/b3_overlay.py) it names the RAM call target.

updates disasm/b3_far_targets.json in place (adds entries / names).
output also: disasm/b3_overlay_names.json
"""
import io
import json
import struct
import sys

sys.path.insert(0, r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\tools')
from b3_sigs2 import load_elf_funcs

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
XIP_BASE = 0x06000100
SDK_ELF = (r'C:\Users\User\AppData\Local\Temp\opencode\sdk\ac701n'
           r'\ac701n_soundbox-main\sdk\cpu\br28\tools\sdk.elf')

data = open(SRC + r'\decrypted\app_bin_full.bin', 'rb').read()
sigs = json.load(io.open(SRC + r'\disasm\b3_signatures.json', encoding='utf-8'))
targets = json.load(io.open(SRC + r'\disasm\b3_far_targets.json',
                            encoding='utf-8'))

# overlay source ranges (from b3_overlay.py run)
copies = [(1067072, 101201056, 3884), (1086688, 101204940, 44080)]
ranges = []  # flash offsets
for dst, src, size in copies:
    ranges.append((src - XIP_BASE, src - XIP_BASE + size))
print('overlay flash ranges:', [(f'{a:06x}', f'{b:06x}') for a, b in ranges])


def in_ranges(off):
    return any(a <= off < b for a, b in ranges)


funcs = load_elf_funcs(SDK_ELF)
ram = [(a, n, c) for n, a, c in funcs if 0x100000 <= a < 0x140000 and c]
print('sdk.elf RAM-region funcs:', len(ram))

names = {}
already = {int(v['flash_equiv'], 16) for v in targets.values()
           if 'flash_equiv' in v and 'name' in v}
already |= {int(k, 16) for k in sigs}
st_hit = st_multi = st_absent = 0
for va, nm, code in sorted(ram):
    if len(code) < 24:
        continue
    cands = [0] if len(code) < 96 else [0, 24, 48, len(code) // 2]
    found = None
    for ao in cands:
        anchor = code[ao:ao + 24]
        if anchor.count(0) > 12:
            continue
        hits = []
        for a, b in ranges:
            seg = data[a:b]
            start = 0
            while True:
                p = seg.find(anchor, start)
                if p < 0:
                    break
                hits.append(a + p - ao)
                start = p + 2
        if len(hits) == 1 and found is None:
            found = hits[0]
        elif hits:
            found = None
            break
    if found is None:
        st_absent += 1
        continue
    st_hit += 1
    ram_addr = None
    for dst, src, size in copies:
        off = found - (src - XIP_BASE)
        if 0 <= off < size:
            ram_addr = dst + off
    names[f'{found + XIP_BASE:08x}'] = {
        'name': nm, 'elf_addr': f'{va:08x}',
        'ram': f'{ram_addr:08x}' if ram_addr is not None else None}
    if found + XIP_BASE not in already:
        st_multi += 1  # count new names
print(f'aligned: {st_hit}, new (not already known): {st_multi}, absent: {st_absent}')

# apply to targets: match via flash_equiv or ram addr
used = 0
for k, e in targets.items():
    if 'name' in e:
        continue
    fe = int(e['flash_equiv'], 16) if 'flash_equiv' in e else None
    ent = names.get(f'{fe:08x}') if fe else None
    if ent is None:
        for v in names.values():
            if v['ram'] == k:
                ent = v
                break
    if ent:
        off = fe - int(f'{fe:08x}', 16)
        e['name'] = ent['name']
        e['via'] = 'sdk-overlay-align'
        used += 1
print('targets newly named:', used)
json.dump(names, io.open(SRC + r'\disasm\b3_overlay_names.json', 'w',
                         encoding='utf-8'), indent=0)
json.dump(targets, io.open(SRC + r'\disasm\b3_far_targets.json', 'w',
                           encoding='utf-8'), indent=0)
named = sum(1 for e in targets.values() if 'name' in e)
print(f'total named: {named}/{len(targets)}')
