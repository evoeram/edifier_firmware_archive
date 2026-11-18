import io
import struct
from collections import Counter

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
TAIL = 0x8EFFC
STREAM = 0xc3b4
tail = dec[TAIL:]

# parse TLVs
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
        names[crc] = names[(crc, param)]

print('--- tag0 instances (crc, u16):')
cnt = Counter()
for pay in tlvs[0]:
    for i in range(0, len(pay) - 3, 4):
        crc, w = struct.unpack_from('<HH', pay, i)
        nm = names.get(crc, f'{crc:04x}?')
        cnt[(nm, w)] += 1
for (nm, w), c in sorted(cnt.items()):
    print(f'  {nm:24s} param/inst={w:5d} x{c}')
