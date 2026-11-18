#!/usr/bin/env python3
import re
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
n = len(data)

K = 0x2BC1
R = 2  # block starts at offsets ≡ 2 (mod 32)

def lfsr_stream(seed, ln):
    out = bytearray()
    s = seed
    for _ in range(ln):
        out.append(s & 0xFF)
        s = ((s << 1) & 0xFFFF) ^ (0x1021 if s & 0x8000 else 0)
    return bytes(out)

# decrypt whole file: block bs covers [bs, bs+32); head 0..2 belongs to block starting at -30
pt = bytearray(n)
# leading 2 bytes: block start -30 -> a = (-30-2)>>2 negative; treat: decrypt with block bs=-30 (a=(-32)>>2=-8) hmm
# simpler: decrypt from bs=2; bytes 0..1 decrypt with the block that would start at -30: seed=K^((-32)>>2)? -8 & 0xFFFF...
bs0 = -30
a0 = (bs0 - R) >> 2
ks = lfsr_stream(K ^ (a0 & 0xFFFF), 34)
for i in range(2):
    pt[i] = data[i] ^ ks[30 + i]
bs = R
while bs < n:
    a = (bs - R) >> 2
    ks = lfsr_stream(K ^ (a & 0xFFFF), 32)
    end = min(bs + 32, n)
    for i in range(bs, end):
        pt[i] = data[i] ^ ks[i - bs]
    bs += 32

open(r'C:\Users\User\AppData\Local\Temp\opencode\mr5_dec.bin','wb').write(bytes(pt))
print('decrypted', n, 'bytes')

d = bytes(pt)
print('=== header 0x00-0x50 ===')
for off in range(0, 0x60, 32):
    print(f'{off:04x}', d[off:off+32].hex(' '))
strs = re.findall(rb'[ -~]{5,}', d)
print('=== strings (first 60) ===')
cnt = 0
for s in strs:
    print(hex(d.find(s)), s.decode())
    cnt += 1
    if cnt >= 60: break
