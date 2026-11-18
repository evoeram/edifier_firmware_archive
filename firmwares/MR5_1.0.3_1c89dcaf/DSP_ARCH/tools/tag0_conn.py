import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
TAIL = 0x8EFFC
STREAM = 0xc3b4
tail = dec[TAIL:]

tlvs = {}
o = 0
while True:
    p = STREAM + o
    if p + 4 > len(tail):
        break
    tag, ln = struct.unpack_from('<HH', tail, p)
    if ln > len(tail) - p - 4:
        break
    tlvs[tag] = tail[p + 4:p + 4 + ln]
    o += 4 + ln

NAMES = {0x6963: 'IIS0_RX', 0x69a5: 'IIS0_TX', 0x737b: 'EQ', 0x74e3: 'digvol', 0x9b3b: 'cfg9b3b',
         0xa248: 'Energy', 0xa576: 'cfgA576', 0xa904: 'GAIN', 0xd06d: 'ADC', 0xd0bc: 'MIC',
         0xda15: 'ChanExp', 0xdccd: 'DAC', 0xdefe: 'DRC', 0xe62a: 'MIXER', 0xeb56: 'pcspk',
         0xf975: 'A2DP_RX', 0x1a85: 'tpl1a85', 0x7de5: 'tpl7de5', 0xd911: 'tpld911',
         0xed7f: 'tpled7f', 0x7674: 'tpl7674', 0x768a: 'tpl768a', 0xba11: 'tplba11',
         0xdc8d: 'tpldc8d', 0x1408: 'tpl1408', 0x1ecd: 'tpl1ecd', 0x8346: 'tpl8346',
         0x8458: 'tpl8458', 0x849a: 'tpl849a', 0xcadc: 'tplcadc', 0xb711: 'tplb711',
         0xd186: 'tpld186'}

t0 = tlvs[0]
insts = []
for i in range(0, len(t0), 4):
    crc, word = struct.unpack_from('<HH', t0, i)
    insts.append((crc, word))
print('tag0 instances:', len(insts))
for i, (crc, w) in enumerate(insts):
    print(f'  [{i:3d}] {NAMES.get(crc, hex(crc)):9s} param={w}')

# tag10 records: {crc u16, param u8, port u8, a u8, b u8}, start after 5-byte header
t10 = tlvs[10]
print('\ntag10 records:')
for i in range(5, len(t10) - 6, 6):
    r = t10[i:i+6]
    crc, prm, port, a, b = struct.unpack('<HBBB', r[0:5]) + (r[5],)
    # a,b as separate bytes
    print(f'  {NAMES.get(crc, hex(crc)):9s} param={prm:3d} port={port:3d} a={a:3d} b={b:3d}  raw={r.hex(" ")}')
