import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
BASE = 0x06000100

def rd(va, n):
    o = va - BASE
    return dec[o:o + n]

def cstr(va, maxlen=40):
    o = va - BASE
    e = dec.find(b'\0', o, o + maxlen)
    return dec[o:e].decode('ascii', 'replace')

# 1) gain-node name table used by f_config397392 (0x6061f2c + mode*4)
print('=== gain name table @0x6061f2c:')
for i in range(8):
    p = struct.unpack_from('<I', rd(0x6061f2c + i * 4, 4))[0]
    if 0x06000100 <= p < 0x06090000:
        print(f'  mode {i}: {cstr(p)!r}')
    else:
        print(f'  mode {i}: raw {p:#x}')

# 2) EQ band counts from stream.bin descriptors (reuse TLV parse)
TAIL = 0x8EFFC
STREAM = 0xc3b4
tail = dec[TAIL:]
o = 0
tlvs = {}
while True:
    p = STREAM + o
    if p + 4 > len(tail):
        break
    tag, ln = struct.unpack_from('<HH', tail, p)
    if ln > len(tail) - p - 4:
        break
    tlvs.setdefault(tag, []).append(tail[p + 4:p + 4 + ln])
    o += 4 + ln

names = {}
for pay in tlvs[2]:
    for i in range(0, len(pay) - 20, 21):
        crc, param = struct.unpack_from('<HB', pay, i + 2)
        names[(crc, param)] = pay[i + 5:i + 21].split(b'\0')[0].decode('ascii', 'replace')

zone = tlvs[5][0]
i = 16
seen = {}
while i + 32 <= len(zone):
    dd = zone[i:i + 32]
    if dd[16:] != b'\0' * 16 or dd[0] > 10 or dd[4] != 0:
        break
    crc, param = struct.unpack_from('<HB', dd, 1)
    nm = names.get((crc, param), f'crc{crc:04x}')
    if dd[0] == 1:
        boff, stride = struct.unpack_from('<HH', dd, 10), struct.unpack_from('<H', dd, 14)[0]
        blk = zone[boff[0]:boff[0] + stride]
        cnt = blk[5]
        seen[(nm, param)] = cnt
    i += 32

print('\n=== EQ slots: bands (max 12):')
agg = {}
for (nm, param), cnt in seen.items():
    agg.setdefault(nm, set()).add(cnt)
for nm in sorted(agg):
    print(f'  {nm:18s} bands={sorted(agg[nm])}')

# 3) descriptor types for gain nodes referenced: SET_HP_GAIN slots values
print('\n=== GAIN (type 3) blocks for a904 nodes:')
i = 16
while i + 32 <= len(zone):
    dd = zone[i:i + 32]
    if dd[16:] != b'\0' * 16 or dd[0] > 10 or dd[4] != 0:
        break
    crc, param = struct.unpack_from('<HB', dd, 1)
    nm = names.get((crc, param), '')
    if crc == 0xa904:
        boff = struct.unpack_from('<H', dd, 10)[0]
        stride = struct.unpack_from('<H', dd, 14)[0]
        blk = zone[boff:boff + stride]
        print(f'  {nm:16s} idx={dd[9]:3d} off={boff:#06x} stride={stride:3d} data={blk.hex(" ")}')
    i += 32
