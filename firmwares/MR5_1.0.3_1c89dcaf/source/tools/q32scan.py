import re, os

f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

ZONES = [('hdr+head', 0, 0x2000), ('0x2000-0x10000', 0x2000, 0x10000),
         ('0x10000-0x30000', 0x10000, 0x30000), ('0x30000-0x5C206', 0x30000, 0x5C206),
         ('0x5C206-0x9B800', 0x5C206, 0x9B800), ('tail 0x9B800-end', 0x9B800, len(data))]

def count(pat, lo, hi):
    return len(re.findall(pat, data[lo:hi]))

for name, lo, hi in ZONES:
    n = hi - lo
    calls = count(rb'\xbf\xf3', lo, hi)
    movs = count(rb'[\xc0-\xcf]\xff', lo, hi)
    push = count(rb'\x74\x01', lo, hi)
    pop = count(rb'\x54\x01', lo, hi)
    nop = count(rb'\x00\x00', lo, hi)
    print(f'{name:22s} size={n:7d} call={calls:6d} ({calls/n*1e4:.1f}/10K)  mov32={movs:6d} ({movs/n*1e4:.1f})  push={push:5d} pop={pop:5d} nop00={nop:6d} ({nop/n*1e4:.1f})')
