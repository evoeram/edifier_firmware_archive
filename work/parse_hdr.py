import struct, re, hashlib, os, json

d = open(r'decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
print('size', len(d))
print('magic', d[:16].hex())

# Candidate entry fields seen before each name; scan for names and print surrounding dwords
names = [b'app_area_head', b'app.bin', b'VM', b'PRCT', b'CODE', b'BTIF', b'AUTO']
for n in names:
    for m in re.finditer(re.escape(n) + rb'\x00', d[:0x200]):
        s = m.start()
        print(f'\n== {n.decode()} at 0x{s:x}')
        start = max(0, s - 20)
        chunk = d[start:s + len(n) + 1]
        for i in range(0, len(chunk), 4):
            w = chunk[i:i+4]
            off = start + i
            if len(w) == 4:
                print(f'  0x{off:04x}: {w.hex()}  le=0x{struct.unpack("<I", w)[0]:08x}')

# entropy profile per 4k block
import math
from collections import Counter
print('\nentropy map (4K blocks):')
for off in range(0, len(d), 0x1000):
    c = Counter(d[off:off+0x1000])
    n = min(0x1000, len(d)-off)
    ent = -sum((v/n)*math.log2(v/n) for v in c.values())
    if off < 0x200 or off % 0x4000 == 0:
        print(f'  0x{off:06x}: {ent:.2f}')
