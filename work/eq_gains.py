import struct
d = open(r'firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
TAIL = 0x8EFFC; STREAM = 0xc3b4
tail = d[TAIL:]
o = 0; tlvs = {}
while o + 4 <= len(tail) - STREAM:
    tag, ln = struct.unpack_from('<HH', tail, STREAM + o)
    if ln > len(tail) - STREAM - o:
        break
    tlvs.setdefault(tag, []).append(tail[STREAM + o + 4: STREAM + o + 4 + ln])
    o += 4 + ln
zone = tlvs[5][0]
names = {}
for pay in tlvs[2]:
    for i in range(0, len(pay) - 20, 21):
        crc, param = struct.unpack_from('<HB', pay, i + 2)
        names[(crc, param)] = pay[i + 5:i + 21].split(b'\0')[0].decode('ascii', 'replace')
descs = []; i = 16
while i + 32 <= len(zone):
    dd = zone[i:i + 32]
    if dd[16:] != b'\0' * 16 or dd[0] > 10 or dd[4] != 0:
        break
    crc, param = struct.unpack_from('<HB', dd, 1)
    descs.append({'type': dd[0], 'name': names.get((crc, param), '?'),
                  'boff': struct.unpack_from('<H', dd, 10)[0],
                  'stride': struct.unpack_from('<H', dd, 14)[0],
                  'idx': dd[9]})
    i += 32
TYP = {0: 'byp', 2: 'pk', 3: 't3', 4: 't4', 7: 't7', 8: 't8'}
seen = set()
for dsc in descs:
    if dsc['type'] != 1:
        continue
    key = (dsc['boff'], dsc['stride'])
    if key in seen:
        continue
    seen.add(key)
    blk = zone[dsc['boff']:dsc['boff'] + dsc['stride']]
    cnt = blk[5]
    parts = []
    for k in range(8, 8 + cnt * 16, 16):
        band, btyp, freq = struct.unpack_from('<HHI', blk, k)
        g, q = struct.unpack_from('<ff', blk, k + 8)
        if g != 0.0 or btyp in (3, 4, 7, 8, 0):
            parts.append(f'{TYP.get(btyp, btyp)}@{freq}={g:+.1f}dB(Q{q:.2f})')
    print(f"{dsc['name']:16s} off={dsc['boff']:#06x} idx={dsc['idx']}: " + ' | '.join(parts))
