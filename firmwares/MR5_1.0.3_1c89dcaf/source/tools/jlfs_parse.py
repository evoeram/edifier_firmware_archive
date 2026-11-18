#!/usr/bin/env python3
# Full JLFS parse of decrypted MR5: scan valid entries, dump files with CRC check.
import struct, os, sys

def jl_crc16(data, crc=0):
    for b in data:
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) if crc & 0x8000 else (crc << 1)
            crc &= 0xFFFF
    return crc

src = sys.argv[1] if len(sys.argv) > 1 else r'C:\Users\User\AppData\Local\Temp\opencode\mr5_dec.bin'
outdir = sys.argv[2] if len(sys.argv) > 2 else r'C:\Users\User\AppData\Local\Temp\opencode\mr5_unpack'
d = open(src, 'rb').read()
os.makedirs(outdir, exist_ok=True)

BASE = 2  # first entry offset
entries = []
off = BASE
while off + 32 <= len(d):
    hcrc, hdr = struct.unpack_from('<H30s', d, off)
    if jl_crc16(hdr) != hcrc:
        print(f'@{off:06x}: CRC bad, stop')
        break
    edcrc, eoff, esize, eflags, eresvd, eindex, ename = struct.unpack('<HIIBBH16s', hdr)
    name = ename.split(b'\0')[0].decode('ascii', 'replace')
    print(f'@{off:06x} {name:16s} data_crc={edcrc:04x} off={eoff:08x} size={esize:8d} flags={eflags:02x} rsvd={eresvd:02x} idx={eindex}')
    entries.append((off, name, edcrc, eoff, esize, eflags))
    if eindex != 0:
        print('   (last entry by index)')
        break
    off += 32

# data region candidates: for regular files, data at eoff (absolute in this image?)
print()
for off, name, edcrc, eoff, esize, eflags in entries:
    if name in ('app_area_head',):
        continue
    # try data at absolute eoff
    for label, doff in ((f'abs {eoff:#x}', eoff),):
        if doff + esize <= len(d):
            crc = jl_crc16(d[doff:doff+esize])
            m = 'OK ' if crc == edcrc else 'bad'
            print(f'{name:16s} data@{doff:#08x} size={esize:8d} crc={crc:04x} want={edcrc:04x} {m}')

# dump app.bin if crc ok
for off, name, edcrc, eoff, esize, eflags in entries:
    if name == 'app.bin' and eoff + esize <= len(d):
        blob = d[eoff:eoff+esize]
        if jl_crc16(blob) == edcrc:
            p = os.path.join(outdir, 'app.bin')
            open(p, 'wb').write(blob)
            print(f'\nsaved {p} ({len(blob)} bytes)')
            print('head:', blob[:64].hex(' '))
