import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
BASE = 0x06000100
code = dec[:0x8eefc]

# find string VAs for EQ node names
targets = {}
for pat in (b'EQDIY', b'EQDIY_2', b'EQDIY_3', b'EQDIY_4', b'EQ17', b'Desk_Acoustic', b'Desk_Acoustic_2',
            b'BassShelf', b'TrebShelf'):
    start = 0
    while True:
        p = dec.find(pat, start)
        if p < 0:
            break
        # string boundary check
        if p > 0 and 0x20 <= dec[p-1] < 0x7f:
            start = p + 1
            continue
        va = BASE + p
        targets[va] = pat.decode()
        start = p + 1

for va, nm in sorted(targets.items()):
    b = struct.pack('<I', va)
    refs = []
    s = 0
    while True:
        q = code.find(b, s)
        if q < 0:
            break
        refs.append(BASE + q)
        s = q + 1
    print(f'{nm:16s} strVA {va:08x} refs: {[hex(r) for r in refs] if refs else "-"}')
