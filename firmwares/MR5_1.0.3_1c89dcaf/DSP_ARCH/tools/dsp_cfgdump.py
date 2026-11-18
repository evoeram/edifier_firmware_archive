import struct
import io

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

names = {}
for pay in tlvs[2]:
    for i in range(0, len(pay) - 20, 21):
        crc, param = struct.unpack_from('<HB', pay, i + 2)
        names[(crc, param)] = pay[i + 5:i + 21].split(b'\0')[0].decode('ascii', 'replace')

zone = tlvs[5][0]
# descriptors
descs = []
i = 16
while i + 32 <= len(zone):
    dd = zone[i:i + 32]
    if dd[16:] != b'\0' * 16 or dd[0] > 10 or dd[4] != 0:
        break
    crc, param = struct.unpack_from('<HB', dd, 1)
    descs.append({'type': dd[0], 'name': names.get((crc, param), f'crc{crc:04x}'),
                  'boff': struct.unpack_from('<H', dd, 10)[0],
                  'stride': struct.unpack_from('<H', dd, 14)[0],
                  'idx': dd[9]})
    i += 32

print('total descs:', len(descs))
seen = set()
for dsc in descs:
    if dsc['type'] == 1:
        continue
    key = (dsc['name'], dsc['boff'], dsc['stride'])
    if key in seen:
        continue
    seen.add(key)
    blk = zone[dsc['boff']:dsc['boff'] + dsc['stride']]
    hexs = blk.hex(' ')
    print(f"T{dsc['type']} {dsc['name']:16s} off={dsc['boff']:#06x} stride={dsc['stride']}: {hexs}")

# group records (type 4/5/7)
print('--- group/pointer records in descriptor stream:')
i = 16
while i + 32 <= len(zone):
    dd = zone[i:i + 32]
    if dd[16:] != b'\0' * 16 or dd[0] > 10 or dd[4] != 0:
        # try group record parse: type | ff*6 | ptr
        if dd[0] in (4, 5, 7):
            ptr = struct.unpack_from('<H', dd, 8)[0]
            print(f"  type={dd[0]} @stream+{i:#x}: ptr={ptr:#06x} raw={dd[:16].hex(' ')}")
        i += 1
        continue
    i += 32
