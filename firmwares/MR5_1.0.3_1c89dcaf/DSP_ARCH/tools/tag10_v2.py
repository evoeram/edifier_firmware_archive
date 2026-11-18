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

t10 = tlvs[10]
# instance params per template from tag0 (valid param values)
t0 = tlvs[0]
valid = defaultdict(set)
for i in range(0, len(t0), 4):
    crc, w = struct.unpack_from('<HH', t0, i)
    valid[crc].add(w & 0xff)  # low byte = logical param

pos = 5
out = []
while pos + 6 <= len(t10):
    crc = struct.unpack_from('<H', t10, pos)[0]
    if crc in NAMES and pos + 6 <= len(t10):
        prm, port, a, b = struct.unpack_from('<BBBB', t10, pos + 2)
        out.append((pos, crc, prm, port, a, b))
        pos += 6
        # skip trailing flag byte(s): known pattern - one extra byte after b in {2,4} for some templates
        # determine by checking whether next position starts with a known crc
        if pos + 2 <= len(t10):
            nxt = struct.unpack_from('<H', t10, pos)[0]
            if nxt not in NAMES and pos + 7 <= len(t10):
                nxt7 = struct.unpack_from('<H', t10, pos + 1)[0]
                if nxt7 in NAMES:
                    out.append((pos, None, t10[pos], '-', '-', '-'))
                    pos += 1
    else:
        out.append((pos, None, t10[pos], '-', '-', '-'))
        pos += 1

for pos, crc, prm, port, a, b in out:
    if crc is None:
        print(f'  @{pos:03x} <extra byte> {prm:#x}')
    else:
        print(f'  @{pos:03x} {NAMES[crc]:9s} p={prm:3d} port={port:3d} a={a:3d} b={b}')
print('final pos', hex(pos), 'len', hex(len(t10)))
