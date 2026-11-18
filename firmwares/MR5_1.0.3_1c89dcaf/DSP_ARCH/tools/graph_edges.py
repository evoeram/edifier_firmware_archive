import json
import io
from collections import defaultdict

J = json.load(io.open(r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\findings\C1_audio_graph.json', encoding='utf-8'))
names = {(n['crc'], n['param']): n['name'] for n in J['nodes']}
tpl = defaultdict(list)
for n in J['nodes']:
    tpl[n['crc']].append(n['name'])

# edges: (crc, word) sequence — dump in original order with names where possible
NAMES = {27045: 'IIS0_TX*', 29923: 'Vol_*', 42358: 'config42358*', 30324: 'A576*', 30346: '9B3B*',
         6789: 'EQ(737b? no)', }
bycrc = defaultdict(list)
for i, e in enumerate(J['edges']):
    bycrc[e['crc']].append((i, e['word']))

CRCNAMES = {0x6963: 'IIS0_RX', 0x69a5: 'IIS0_TX', 0x737b: 'EQ', 0x74e3: 'digvol', 0x9b3b: 'cfg9b3b',
            0xa248: 'Energy', 0xa576: 'cfgA576', 0xa904: 'GAIN', 0xd06d: 'ADC', 0xd0bc: 'MIC',
            0xda15: 'ChanExpand', 0xdccd: 'DAC', 0xdefe: 'DRC', 0xe62a: 'MIXER', 0xeb56: 'pcspk',
            0xf975: 'A2DP_RX'}
for crc in sorted(bycrc):
    ws = bycrc[crc]
    print(f"crc {crc:04x} ({CRCNAMES.get(crc,'?'):12s}) n={len(ws):3d} words: "
          + ' '.join(str(w) for _, w in ws[:40]) + (' ...' if len(ws) > 40 else ''))
