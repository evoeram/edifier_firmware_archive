import zlib, os, sys

f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
n = len(data)
found = []
CH = 4096
for off in range(0, n - 16):
    d = zlib.decompressobj(-15)
    try:
        out = d.decompress(data[off:off+CH])
        if len(out) > 128:
            # verify longer stream
            d2 = zlib.decompressobj(-15)
            out2 = d2.decompress(data[off:off+65536])
            found.append((off, len(out2), out2[:48].hex()))
            print('HIT', hex(off), len(out2), out2[:48].hex(), flush=True)
    except Exception:
        pass
    if off % 100000 == 0:
        print('...', hex(off), flush=True)
print('total hits:', len(found))
