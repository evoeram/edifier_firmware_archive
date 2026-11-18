import zlib, glob, os, re

files = glob.glob(r'C:\dev\edifier_firmware_archive\firmwares\*\firmware.bin')
for f in files:
    data = open(f,'rb').read()
    name = os.path.basename(os.path.dirname(f))
    hits = [m.start() for m in re.finditer(rb'\x78[\x01\x5e\x9c\xda]', data)]
    good = []
    for off in hits:
        d = zlib.decompressobj()
        try:
            out = d.decompress(data[off:off+200000])
            if len(out) > 64:
                good.append((off, len(out), out[:32].hex()))
        except Exception:
            pass
    print(name, 'hits', len(hits), 'inflate_ok', len(good))
    for g in good[:10]:
        print('   ', hex(g[0]), g[1], g[2])
