#!/usr/bin/env python3
import glob, os, re

K = 0x2BC1
R = 2

def lfsr_stream(seed, ln):
    out = bytearray()
    s = seed
    for _ in range(ln):
        out.append(s & 0xFF)
        s = ((s << 1) & 0xFFFF) ^ (0x1021 if s & 0x8000 else 0)
    return bytes(out)

def decrypt(data):
    n = len(data)
    pt = bytearray(n)
    bs0 = -30
    a0 = (bs0 - R) >> 2
    ks = lfsr_stream(K ^ (a0 & 0xFFFF), 34)
    for i in range(R):
        pt[i] = data[i] ^ ks[30 + i]
    bs = R
    while bs < n:
        a = (bs - R) >> 2
        ks = lfsr_stream(K ^ (a & 0xFFFF), 32)
        end = min(bs + 32, n)
        pt[bs:end] = bytes(c ^ k for c, k in zip(data[bs:end], ks))
        bs += 32
    return bytes(pt)

outdir = r'C:\dev\edifier_firmware_archive\decrypted'
os.makedirs(outdir, exist_ok=True)
for f in glob.glob(r'C:\dev\edifier_firmware_archive\firmwares\*\firmware.bin'):
    name = os.path.basename(os.path.dirname(f))
    if name.startswith('e25HD'):
        print(name, '- другой формат, пропущен'); continue
    data = open(f,'rb').read()
    pt = decrypt(data)
    out = os.path.join(outdir, name + '_dec.bin')
    open(out, 'wb').write(pt)
    strs = re.findall(rb'[ -~]{6,}', pt[:0x400])
    ok = b'app_area_head' in pt[:0x400] or b'app.bin' in pt[:0x400]
    print(f'{name:24s} {"OK" if ok else "???"}  strs: {[s.decode() for s in strs[:6]]}')
