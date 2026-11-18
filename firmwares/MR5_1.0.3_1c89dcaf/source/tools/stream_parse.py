#!/usr/bin/env python3
# C1.2: parse stream.bin — the audio-graph/effect-config resource nested in
# the MR5 resource tail (found at tail hdr@0x9322..: cfg_tool.bin, p11_code.bin,
# stream.bin). stream.bin data: tail+0xc3b4, declared size 0xf17c.
#
# Layout (all little-endian, offsets relative to stream.bin data start):
#   TLV stream: tag:u16 | len:u16 | payload
#     tag 0 (0x2c0): graph edges: 4-byte entries (crc16, u16) — 106/174 crcs
#                    match node names
#     tag 2 (0x516): 62 name records: tag 0x0013 | crc16 | param u8 | name[16]
#     tag 3 (2):     unknown (6c 82)
#     tag 4 (0x1c):  4 x 7-byte refs: 05 00 | crc16 | u16
#     tag 5 (0xe6c2): config store:
#       +0x00: header 16 B (04 00 00 00 ...)
#       +0x10: 246 descriptors x 32 B:
#              {type u8 | crc16 | param u8 | 00 | id_a u16 (0x9660) |
#               id_b u16 (instance seq) | idx u8 | block_off u16 | 00 |
#               stride u16 | 00 | zeros[16]}
#       +0x1ed0: preset/group records (04/05/07 | ff*6.. | ptr u16 | .. )
#       +0x1f94..: value blocks the descriptors point to (block_off, stride):
#              type 1 (EQ, stride 200): header 8 B (00000000 | 0000 | count u16)
#                     + count x 16 B {band u16 | type u16 | freq u32 | pad u32
#                     | Q float}  (freq Hz, Q = 0.7 etc.)
#              type 2 (DRC, stride 76): floats (thresholds/ratios)
#              type 3 (gains, stride 12): 3 floats (e.g. 8.2, -90.0, 0.0 — dB)
#     tag 6/8/10: small trailing TLVs (undecoded)
import io
import json
import struct
import collections

IMG = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\MR5_1.0.3_1c89dcaf_dec.bin'
OUT_MD = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\findings\C1_audio_graph.md'
OUT_JSON = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\findings\C1_audio_graph.json'

TAIL = 0x8EFFC
STREAM = 0xc3b4


def s(o):
    return STREAM + o


def main():
    tail = open(IMG, 'rb').read()[TAIL:]
    out = {'nodes': [], 'edges': [], 'descriptors': [], 'blocks': []}

    # ---- TLV walk ----
    tlvs = {}
    o = 0
    while o + 4 <= len(tail) - STREAM:
        tag, ln = struct.unpack_from('<HH', tail, s(o))
        if ln > len(tail) - STREAM - o:
            break
        tlvs.setdefault(tag, []).append((o, tail[s(o) + 4:s(o) + 4 + ln]))
        o += 4 + ln

    # ---- names (tag 2) ----
    names = {}
    for o, pay in tlvs[2]:
        for i in range(0, len(pay) - 20, 21):
            assert struct.unpack_from('<H', pay, i)[0] == 0x0013
            crc, param = struct.unpack_from('<HB', pay, i + 2)
            nm = pay[i + 5:i + 21].split(b'\0')[0].decode('ascii', 'replace')
            names[(crc, param)] = nm
            out['nodes'].append({'crc': crc, 'param': param, 'name': nm})

    # ---- edges (tag 0) ----
    for o, pay in tlvs[0]:
        for k in range(0, len(pay) - 3, 4):
            crc, w = struct.unpack_from('<HH', pay, k)
            out['edges'].append({'crc': crc, 'word': w})

    # ---- config store (tag 5) ----
    zone = tlvs[5][0][1]
    descs = []
    i = 16
    while i + 32 <= len(zone):
        d = zone[i:i + 32]
        if d[16:] != b'\0' * 16 or d[0] > 10 or d[4] != 0:
            break
        crc, param = struct.unpack_from('<HB', d, 1)
        descs.append({
            'type': d[0], 'crc': crc, 'param': param,
            'name': names.get((crc, param), '?'),
            'id_a': struct.unpack_from('<H', d, 5)[0],
            'id_b': struct.unpack_from('<H', d, 7)[0],
            'idx': d[9],
            'block_off': struct.unpack_from('<H', d, 10)[0],
            'stride': struct.unpack_from('<H', d, 14)[0],
        })
        i += 32
    out['descriptors'] = descs

    # ---- value blocks (dedupe by (block_off, stride, type)) ----
    seen = set()
    for d in descs:
        key = (d['type'], d['block_off'], d['stride'])
        if key in seen:
            continue
        seen.add(key)
        boff, stride = d['block_off'], d['stride']
        if boff == 0 or boff + stride > len(zone):
            continue
        blk = zone[boff:boff + stride]
        entry = {'type': d['type'], 'name': d['name'], 'off': boff,
                 'stride': stride}
        if d['type'] == 1 and stride >= 8:
            cnt = blk[5]
            bands = []
            for k in range(8, 8 + cnt * 16, 16):
                band, btyp, freq = struct.unpack_from('<HHI', blk, k)
                q, = struct.unpack_from('<f', blk, k + 12)
                bands.append({'band': band, 'type': btyp, 'freq_hz': freq,
                              'q': round(q, 4)})
            entry['bands'] = bands
        else:
            entry['hex'] = blk.hex(' ')
            fl = struct.unpack_from('<%df' % (stride // 4), blk, 0)
            entry['floats'] = [round(v, 5) for v in fl]
        out['blocks'].append(entry)

    io.open(OUT_JSON, 'w', encoding='utf-8').write(
        json.dumps(out, ensure_ascii=False, indent=1))

    # ---- markdown report ----
    w = io.open(OUT_MD, 'w', encoding='utf-8')
    w.write('# C1.2 — stream.bin: аудио-граф и конфиги эффектов (2026-11-18)\n\n')
    w.write('`stream.bin` — вложенный том ресурсного хвоста (hdr@tail+0xc394,\n'
            'данные tail+0xc3b4, 61 820 Б). Это содержимое «effect_cfg»:\n'
            'граф узлов + конфиги/коэффициенты. Формат — TLV-поток\n'
            '`tag:u16 | len:u16 | payload` (LE).\n\n')
    w.write('| tag | len | содержимое |\n|---|---|---|\n')
    w.write('| 0 | 0x2c0 | рёбра графа: 174 записи по 4 Б (crc16, u16); 106 crc '
            'совпадают с именами узлов |\n')
    w.write('| 2 | 0x516 | 62 имени: `tag 0x0013 \\| crc16 \\| param u8 \\| '
            'name[16]` |\n')
    w.write('| 3 | 2 | ? (`6c 82`) |\n')
    w.write('| 4 | 0x1c | 4 ссылки `05 00 \\| crc16 \\| u16` |\n')
    w.write('| 5 | 0xe6c2 | хранилище конфигов (см. ниже) |\n')
    w.write('| 6/8/10 | 0x30/0x14/0x242 | хвостовые TLV (не разобраны) |\n\n')
    w.write('## Tag 5 — хранилище конфигов\n\n')
    w.write('- шапка 16 Б (`04 00 …` — версия 4);\n')
    w.write('- **246 дескрипторов × 32 Б** (все ссылаются на известные узлы): '
            '`{type u8 | crc16 | param u8 | 00 | id_a u16 (0x9660) | id_b u16 '
            '(посл. номер) | idx u8 | block_off u16 | 00 | stride u16 | 00 | '
            'нули[16]}`; типы: 1×185 (EQ, stride 200), 2×2 (DRC, stride 76), '
            '3×59 (гейны, stride 12 и др.);\n')
    w.write('- 4+2 групповые записи (`04`/`05`/`07 \\| ff×6 \\| ptr u16 \\| …`);\n')
    w.write('- далее — блоки значений по `block_off`/`stride`.\n\n')
    w.write('### Тип 1 — EQ (блок 200 Б)\n\n')
    w.write('Шапка 8 Б + `count` × 16 Б: `{band u16 | type u16 | freq u32 | '
            'pad u32 | Q float}`. Пример (BassShelf, 12 полос):\n\n')
    w.write('| band | type | freq, Гц | Q |\n|---|---|---|---|\n')
    ex = next(b for b in out['blocks'] if b['type'] == 1 and b['name'] == 'BassShelf')
    for b in ex['bands']:
        w.write(f"| {b['band']} | {b['type']} | {b['freq_hz']} | {b['q']} |\n")
    w.write('\n### Тип 2 — DRC (76 Б, float) и тип 3 — гейны (12 Б, float)\n\n')
    for b in out['blocks']:
        if b['type'] == 2:
            w.write(f"- {b['name']} (off {b['off']:#x}): "
                    f"{b['floats'][:8]} …\n")
    w.write('\nТип 3 (пример SET_HP_GAIN, off 0x4d5f): тройки float '
            '(8.2, -90.0, 0.0 … — дБ: макс/мин/шаг?).\n\n')
    w.write('## Выводы\n\n1. `stream.bin` = effect_cfg: полный аудио-граф '
            '(узлы+рёбра) и параметры всех эффектов MR5.\n'
            '2. Узел адресуется парой (crc16 имени, param); crc16 — тот же '
            'jl_crc16.\n'
            '3. EQ-блоки — полосы (freq/type/Q), биквады DSP строит сам; '
            'гейны — float в дБ; DRC — float-наборы.\n'
            '4. Привязка к коду: SET_HP_GAIN-кластер (B2), файловый API по '
            'имени `stream.bin`.\n'
            '5. Не разобрано: tag 0 семантика слова w, tag 3/6/8/10, '
            'групповые записи 04/05/07, типы дескрипторов 7.\n')
    w.close()

    print(f"nodes: {len(out['nodes'])}, edges: {len(out['edges'])}, "
          f"descriptors: {len(descs)}, unique blocks: {len(out['blocks'])}")
    print('wrote', OUT_MD)
    print('wrote', OUT_JSON)


if __name__ == '__main__':
    main()
