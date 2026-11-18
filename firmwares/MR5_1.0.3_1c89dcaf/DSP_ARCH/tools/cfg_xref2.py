import re
import bisect
import json
import io

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
XIP = 0x06000100
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()

# 1) strings around the jlstream_res_init arg
for base in (0x5fd80, 0x5fdc0, 0x5fa80, 0x5f960):
    chunk = dec[base:base + 0x60]
    asc = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
    print(f'{base:06x}: {asc}')

print()
# 2) listing scan for refs
targets = {
    0x0605faaf: 'flash/res/effect_cfg.bin',
    0x0605fefa: 'flash/res/stream.bin',
    0x06062127: 'stream.bin',
    0x06062153: 'flash/res/',
    0x060722e2: 'cfg_tool.bin',
    0x0605fac8: 'new_cfg_tool',
    0x0605fed9: '1Hc08-ish (res_init arg)',
}
line_re = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)\s*(.*)$')
b42 = json.load(io.open(SRC + r'\disasm\b42_funcs.json', encoding='utf-8'))
faddrs = sorted(int(k, 16) for k in b42)

def func_of(va):
    i = bisect.bisect_right(faddrs, va) - 1
    if i >= 0:
        fa = faddrs[i]
        if va < fa + b42[f'{fa:08x}']['size']:
            return fa
    return None

hits = {}
for l in open(SRC + r'\disasm\mr5_app_disasm.txt', encoding='utf-8', errors='replace'):
    m = line_re.match(l.rstrip())
    if not m:
        continue
    a = int(m.group(1), 16)
    for mm in re.finditer(r'(-?\d{7,})', m.group(3)):
        v = int(mm.group(1)) & 0xFFFFFFFF
        if v in targets:
            hits.setdefault(targets[v], []).append((a, func_of(a)))

for nm in sorted(hits):
    for a, f in hits[nm]:
        print(f'{nm:28s} site {a:08x} func {"%08x" % f if f else "(ovl/none)"}')
