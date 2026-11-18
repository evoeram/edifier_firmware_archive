#!/usr/bin/env python3
"""B3.1c: chain-aligned naming of RAM overlay targets.

Between consecutive anchor pairs (flash_off <-> sdk.elf VA) where
flash_delta == elf_delta, every sdk.elf symbol lying between the anchors
can be mapped linearly onto the flash overlay image.
"""
import io
import json
import bisect
import sys

sys.path.insert(0, r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\tools')
from b3_sigs2 import load_elf_funcs

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
SDK_ELF = (r'C:\Users\User\AppData\Local\Temp\opencode\sdk\ac701n'
           r'\ac701n_soundbox-main\sdk\cpu\br28\tools\sdk.elf')
XIP_BASE = 0x06000100

names = json.load(io.open(SRC + r'\disasm\b3_overlay_names.json',
                          encoding='utf-8'))
targets = json.load(io.open(SRC + r'\disasm\b3_far_targets.json',
                            encoding='utf-8'))
sigs = json.load(io.open(SRC + r'\disasm\b3_signatures.json', encoding='utf-8'))

# all anchor pairs: flash VA <-> elf VA  (from b3_sigs2 unique matches +
# overlay alignment); keep only RAM-region elf VAs with known flash equiv
pairs = set()
for k, v in sigs.items():
    ea = int(v['elf_addr'], 16)
    if 0x100000 <= ea < 0x140000:
        pairs.add((int(k, 16), ea))
for k, v in names.items():
    if v.get('ram'):
        pairs.add((int(k, 16), int(v['elf_addr'], 16)))
pairs = sorted(pairs)
print('anchor pairs (ram-region):', len(pairs))

# sdk.elf RAM functions sorted by VA
ram = sorted((a, n, len(c)) for n, a, c in load_elf_funcs(SDK_ELF)
             if 0x100000 <= a < 0x140000 and c)
ram_va = [a for a, n, s in ram]

mapped = {}
for (f1, e1), (f2, e2) in zip(pairs, pairs[1:]):
    if f2 <= f1 or e2 <= e1:
        continue
    fd, ed = f2 - f1, e2 - e1
    if fd != ed or fd > 0x8000:
        continue
    # consistent run: map sdk funcs strictly between e1 and e2
    i = bisect.bisect_right(ram_va, e1)
    j = bisect.bisect_left(ram_va, e2)
    for va, nm, sz in ram[i:j]:
        if va + sz <= e2:
            mapped[f'{XIP_BASE + f1 + (va - e1):08x}'] = nm
print('chain-mapped flash VAs:', len(mapped))

used = 0
for k, e in targets.items():
    if 'name' in e or 'flash_equiv' not in e:
        continue
    fe = e['flash_equiv']
    if fe in mapped:
        e['name'] = mapped[fe]
        e['via'] = 'sdk-chain-align'
        used += 1
print('targets newly named:', used)
named = sum(1 for e in targets.values() if 'name' in e)
print(f'total named: {named}/{len(targets)}')
json.dump(mapped, io.open(SRC + r'\disasm\b3_overlay_chain.json', 'w',
                          encoding='utf-8'), indent=0)
json.dump(targets, io.open(SRC + r'\disasm\b3_far_targets.json', 'w',
                           encoding='utf-8'), indent=0)
