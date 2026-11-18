#!/usr/bin/env python3
"""C1.3: dump all gain (type 2/3) and EQ-summary blocks from stream.bin effect_cfg."""
import struct, json, collections

IMG = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\MR5_1.0.3_1c89dcaf_dec.bin'
TAIL = 0x8EFFC
STREAM = 0xc3b4

tail = open(IMG, 'rb').read()[TAIL:]

# TLV walk
tlvs = {}
o = 0
while o + 4 <= len(tail) - STREAM:
    tag, ln = struct.unpack_from('<HH', tail, STREAM + o)
    if ln > len(tail) - STREAM - o:
        break
    tlvs.setdefault(tag, []).append(tail[STREAM + o + 4: STREAM + o + 4 + ln])
    o += 4 + ln

names = {}
for pay in tlvs[2]:
    for i in range(0, len(pay) - 20, 21):
        crc, param = struct.unpack_from('<HB', pay, i + 2)
        nm = pay[i + 5:i + 21].split(b'\0')[0].decode('ascii', 'replace')
        names[(crc, param)] = nm

zone = tlvs[5][0]
descs = []
i = 16
while i + 32 <= len(zone):
    d = zone[i:i + 32]
    if d[16:] != b'\0' * 16 or d[0] > 10 or d[4] != 0:
        break
    crc, param = struct.unpack_from('<HB', d, 1)
    descs.append({'type': d[0], 'crc': crc, 'param': param,
                  'name': names.get((crc, param), '?'),
                  'id_a': struct.unpack_from('<H', d, 5)[0],
                  'id_b': struct.unpack_from('<H', d, 7)[0],
                  'idx': d[9],
                  'block_off': struct.unpack_from('<H', d, 10)[0],
                  'stride': struct.unpack_from('<H', d, 14)[0]})
    i += 32

print(f'descriptors: {len(descs)}')
by_type = collections.Counter(d['type'] for d in descs)
print('types:', dict(by_type))

# unique nodes with their config types
nodes = collections.defaultdict(list)
for d in descs:
    nodes[(d['crc'], d['param'], d['name'])].append((d['type'], d['idx'], d['block_off'], d['stride']))

# ---- type 2 DRC full dump ----
print('\n==== TYPE 2 (DRC, 76B floats) ====')
seen = set()
for d in descs:
    if d['type'] != 2:
        continue
    key = (d['block_off'], d['stride'])
    blk = zone[d['block_off']:d['block_off'] + d['stride']]
    fl = struct.unpack_from('<%df' % (d['stride'] // 4), blk, 0)
    tag = d['name']
    if key in seen:
        print(f'  (same block) {tag} idx={d["idx"]}')
        continue
    seen.add(key)
    print(f'\n{tag} off={d["block_off"]:#x} stride={d["stride"]}:')
    for j, v in enumerate(fl):
        print(f'   [{j:2d}] {v:12.5f}')

# ---- type 3 gains ----
print('\n==== TYPE 3 (gains) ====')
seen = set()
for d in descs:
    if d['type'] != 3:
        continue
    key = (d['block_off'], d['stride'])
    blk = zone[d['block_off']:d['block_off'] + d['stride']]
    n = d['stride'] // 4
    fl = struct.unpack_from('<%df' % n, blk, 0)
    if key in seen:
        print(f'  (same block) {d["name"]} idx={d["idx"]}: {[round(v,2) for v in fl]}')
        continue
    seen.add(key)
    print(f'\n{d["name"]} off={d["block_off"]:#x} stride={d["stride"]}:')
    print('   floats:', [round(v, 4) for v in fl])

# ---- type 1 EQ summary ----
print('\n==== TYPE 1 (EQ) summary: node -> bands ====')
seen = set()
for d in descs:
    if d['type'] != 1:
        continue
    key = (d['block_off'], d['stride'])
    if key in seen:
        continue
    seen.add(key)
    blk = zone[d['block_off']:d['block_off'] + d['stride']]
    cnt = blk[5]
    bands = []
    for k in range(8, 8 + cnt * 16, 16):
        band, btyp, freq = struct.unpack_from('<HHI', blk, k)
        q, = struct.unpack_from('<f', blk, k + 12)
        bands.append((band, btyp, freq, round(q, 3)))
    print(f'{d["name"]} idx={d["idx"]} off={d["block_off"]:#x} count={cnt}: '
          f'{[(b, t, f) for b, t, f, q in bands]}')

# ---- group records ----
print('\n==== group records (after descriptors) ====')
g = zone[i:]
for j in range(0, min(len(g), 0x120), 16):
    row = g[j:j + 16]
    print(f'  +{i+j:05x}: {row.hex(" ")}')

# ---- trailing TLVs ----
print('\n==== trailing TLVs 6/8/10 ====')
for t in (3, 6, 8, 10):
    for pay in tlvs.get(t, []):
        print(f'tag {t} len {len(pay)}: {pay.hex(" ")}')
