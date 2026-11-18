import math
from collections import Counter
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
B = 4096
print('entropy per 4KB block (file offset: H):')
line = []
for off in range(0, len(data), B):
    blk = data[off:off+B]
    c = Counter(blk)
    n = len(blk)
    H = -sum(v/n*math.log2(v/n) for v in c.values())
    line.append(f'{off//B:3d}:{off:06x}:{H:.2f}')
    if len(line) == 8:
        print('  '.join(line)); line = []
if line: print('  '.join(line))
