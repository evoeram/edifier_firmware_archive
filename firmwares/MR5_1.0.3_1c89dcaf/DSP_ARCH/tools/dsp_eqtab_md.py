import struct
import io

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
OUT = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\DSP_ARCH\EQ_TABLES.md'

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

TYP = {0: 'bypass', 1: 'lowpass1', 2: 'peaking', 3: 'lowshelf', 4: 'highshelf',
       5: 'bandpass', 6: 'notch', 7: 'lowshelf2', 8: 'highshelf2'}

seen = set()
lines = []
lines.append('# MR5 1.0.3 — таблицы коэффициентов EQ (stream.bin, tag 5)\n')
lines.append('Источник: `stream.bin` (ресурсный хвост, TLV tag 5), блоки типа 1 (stride 200).')
lines.append('Формат блока: шапка 8 Б + count × 16 Б `{band u16 | type u16 | freq f32 | gain f32 | Q f32}`.')
lines.append('Типы фильтров (по `audio_eq_tab_check` 06065808, switch 0..8):\n')
lines.append('| тип | фильтр |')
lines.append('|---|---|')
for k in range(9):
    lines.append(f'| {k} | {TYP[k]} |')
lines.append('')
lines.append('Каждая запись = один «слот» EQ-узла; в графе узел применяет выбранный слот по индексу (idx).\n')

for dsc in descs:
    if dsc['type'] != 1:
        continue
    key = (dsc['name'], dsc['boff'], dsc['stride'])
    if key in seen:
        continue
    seen.add(key)
    blk = zone[dsc['boff']:dsc['boff'] + dsc['stride']]
    cnt = blk[5]
    parts = []
    for k in range(8, 8 + cnt * 16, 16):
        band, btyp = struct.unpack_from('<HH', blk, k)
        freq, gain, q = struct.unpack_from('<fff', blk, k + 4)
        parts.append(f'band{band} {TYP.get(btyp, btyp)}@{freq:.0f}Гц {gain:+.1f}дБ Q{q:.2f}')
    lines.append(f"## {dsc['name']} (idx={dsc['idx']}, off={dsc['boff']:#06x})\n")
    for p_ in parts:
        lines.append(f'- {p_}')
    lines.append('')

io.open(OUT, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')
print('written', OUT, len(lines), 'lines')
