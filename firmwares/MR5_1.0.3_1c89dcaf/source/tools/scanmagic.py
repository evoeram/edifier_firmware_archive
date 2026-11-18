import os, zlib, lzma, bz2
base = r"C:\dev\edifier_firmware_archive\firmwares"
magics = {
    'zlib78': [b'\x78\x01', b'\x78\x9c', b'\x78\xda', b'\x78\x5e'],
    'lzma_alone': [b'\x5d\x00\x00'],
    'lz4frame': [b'\x04\x22\x4d\x18'],
    'zstd': [b'\x28\xb5\x2f\xfd'],
    'bz2': [b'BZh'],
    'gzip': [b'\x1f\x8b\x08'],
    'xz': [b'\xfd7zXZ'],
    'lzo': [b'\x89\x4c\x5a\x4f'],
    'lz77jl': [b'\x4a\x4c\x5a', b'JLC', b'JLZ'],
}
for d in sorted(os.listdir(base)):
    p = os.path.join(base, d, 'firmware.bin')
    if not os.path.exists(p): continue
    data = open(p, 'rb').read()
    hits = []
    for name, pats in magics.items():
        for pat in pats:
            start = 0
            while True:
                i = data.find(pat, start)
                if i < 0: break
                # try to decompress a bit
                ok = ''
                if name == 'zlib78':
                    try:
                        do = zlib.decompressobj(-15)
                        out = do.decompress(data[i:i+65536], 2048)
                        if len(out) > 256: ok = f' INFLATE_OK {len(out)}'
                    except Exception: pass
                if name == 'lzma_alone':
                    try:
                        d2 = lzma.LZMADecompressor(format=lzma.FORMAT_ALONE)
                        out = d2.decompress(data[i:i+65536], 4096)
                        if len(out) > 256: ok = f' LZMA_OK {len(out)}'
                    except Exception: pass
                hits.append((name, hex(i), ok))
                start = i + 1
                if len(hits) > 40: break
            if len(hits) > 40: break
    print(f"== {d} ({len(data)} B): {len(hits)} magic hits")
    for h in hits[:24]:
        print('   ', h)
