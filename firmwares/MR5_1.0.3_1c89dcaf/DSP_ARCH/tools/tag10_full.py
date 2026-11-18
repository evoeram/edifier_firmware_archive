import struct
from collections import defaultdict

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

# --- identify unknown templates via tag5 descriptors (crc field)
t5 = tlvs[5]
crc_cnt = defaultdict(int)
i = 16
while i + 32 <= len(t5):
    dd = t5[i:i + 32]
    if dd[16:] != b'\0' * 16 or dd[0] > 10 or dd[4] != 0:
        break
    crc = struct.unpack_from('<H', dd, 1)[0]
    crc_cnt[crc] += 1
    i += 32
print('tag5 descriptor counts per crc:')
for crc, c in sorted(crc_cnt.items()):
    print(f'  {crc:04x} {NAMES.get(crc, "?"):9s} x{c}')

# --- parse tag10 with the b==4 extra-byte rule
t10 = tlvs[10]
recs = []
i = 5
while i + 6 <= len(t10):
    crc, prm, port, a, b = struct.unpack_from('<HBBBB', t10, i)
    recs.append((crc, prm, port, a, b, i))
    i += 6
    if b == 4:
        i += 1  # extra pad byte observed after b==4 records
print(f'\ntag10 records parsed: {len(recs)}, consumed to {i} (len {len(t10)})')
for crc, prm, port, a, b, off in recs:
    nm = NAMES.get(crc, hex(crc))
    side = 'R' if prm >= 256 and crc != 0xdccd else ('L' if crc != 0xdccd else '')
    print(f'  @{off:03x} {nm:9s} p={prm:3d} port={port:3d} a={a:3d} b={b} ')
