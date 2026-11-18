import struct
import io
from collections import defaultdict

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
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

bycrc = defaultdict(list)
for pay in tlvs[2]:
    for i in range(0, len(pay) - 20, 21):
        crc, param = struct.unpack_from('<HB', pay, i + 2)
        nm = pay[i + 5:i + 21].split(b'\0')[0].decode('ascii', 'replace')
        bycrc[crc].append((param, nm))

print('templates:', len(bycrc))
for crc in sorted(bycrc):
    recs = sorted(bycrc[crc])
    nms = ', '.join(f'{p}:{n}' for p, n in recs)
    print(f'crc {crc:04x}: {len(recs):2d} names -> {nms}')
