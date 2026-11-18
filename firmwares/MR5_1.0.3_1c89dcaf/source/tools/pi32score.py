import re, glob, os

ZONES = [('head 0x206-0x2000', 0x206, 0x2000), ('0x2000-0x10000', 0x2000, 0x10000),
         ('0x10000-0x30000', 0x10000, 0x30000), ('0x30000-0x5C206', 0x30000, 0x5C206),
         ('0x5C206-0x9B800', 0x5C206, 0x9B800), ('tail', 0x9B800, 10**9)]

def stats(data, lo, hi):
    hi = min(hi, len(data))
    n = hi - lo
    seg = data[lo:hi]
    mov32 = len(re.findall(rb'[\xc0-\xcf]\xff', seg))
    pop = len(re.findall(rb'[\x50-\x5f]\x04', seg))
    push = len(re.findall(rb'[\x60-\x6f]\x04', seg))
    movrr = len(re.findall(rb'.\x16', seg)) # word ?? 16 LE: low byte any, high 0x16
    return n, mov32, pop, push, movrr

files = glob.glob(r'C:\dev\edifier_firmware_archive\firmwares\*\firmware.bin')
for f in files:
    data = open(f,'rb').read()
    name = os.path.basename(os.path.dirname(f))
    out = []
    for zn, lo, hi in ZONES:
        n, m32, pop, push, mrr = stats(data, lo, hi)
        out.append(f'{zn.split()[0]}:m32={m32/n*1e4:.1f},pop={pop/n*1e4:.1f},push={push/n*1e4:.1f},mov16={mrr/n*1e4:.1f}')
    print(f'{name:24s}', ' | '.join(out))
