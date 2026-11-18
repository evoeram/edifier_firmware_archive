#!/usr/bin/env python3
# C1: resource tail of the MR5 image (app_area_tail_res.bin).
# The tail is a JLFS-style resource volume (32-byte records with CRC16)
# followed by data: tone files (mp3, TIDX index) and DSP/effect config
# blobs (node names like DAC24, MIXER1, BassShelf, IIS0_RX1...).
#
# Output: source/findings/C1_resources.md + extracted entries to
#         source/decrypted/res/<name>
import os, re, struct, collections

SRC = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEC = os.path.join(SRC, 'decrypted')
IMG = os.path.join(DEC, 'MR5_1.0.3_1c89dcaf_dec.bin')
OUTDIR = os.path.join(DEC, 'res')
OUT_MD = os.path.join(SRC, 'findings', 'C1_resources.md')
TAIL_OFF = 0x8EFFC                      # start of the tail in the image
XIP = 0x06000000 + TAIL_OFF             # XIP address of the tail

def jl_crc16(data, crc=0):
    for b in data:
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) if crc & 0x8000 else (crc << 1)
            crc &= 0xFFFF
    return crc

def main():
    data = open(IMG, 'rb').read()
    tail = data[TAIL_OFF:]
    os.makedirs(OUTDIR, exist_ok=True)

    # ---- volume header: scan 32-byte records from offset 2 (as main image) ----
    print('=== volume records (32 B, JLFS-like, base=2) ===')
    recs = []
    off = 2
    while off + 32 <= len(tail):
        w0, = struct.unpack_from('<H', tail, off)
        if jl_crc16(tail[off + 2:off + 32]) != w0:
            break
        dcrc, roff, rsize, flags, rsvd, idx = struct.unpack('<HIIBBH', tail[off + 2:off + 16])
        name = tail[off + 16:off + 32].split(b'\0')[0].split(b'\xff')[0]
        name = name.decode('ascii', 'replace')
        recs.append(dict(hdr_crc=w0, data_crc=dcrc, off=roff, size=rsize,
                         flags=flags, idx=idx, name=name))
        print(f'@{off:05x} {name:20s} off={roff:08x} size={rsize:7d} '
              f'flags={flags:02x} rsvd={rsvd:02x} idx={idx} dcrc={dcrc:04x}')
        if idx != 0:
            break
        off += 32
        if off > 0x400:
            break

    # verify data CRCs where possible
    for r in recs:
        if r['off'] + r['size'] <= len(tail):
            ok = jl_crc16(tail[r['off']:r['off'] + r['size']]) == r['data_crc']
            r['crc_ok'] = ok
            pref = crc_prefix(tail[r['off']:r['off'] + r['size']], r['data_crc'])
            r['crc_prefix'] = pref
        else:
            r['crc_ok'] = None
            r['crc_prefix'] = None

    # ---- dump entries ----
    for r in recs:
        if r['off'] + r['size'] <= len(tail) and r['size']:
            p = os.path.join(OUTDIR, r['name'].replace('/', '_') or f'ent_{r["off"]:x}')
            open(p, 'wb').write(tail[r['off']:r['off'] + r['size']])

    # ---- TIDX (tone index) ----
    print('\n=== TIDX ===')
    tidx = None
    for r in recs:
        if r['off'] < len(tail) and tail[r['off']:r['off'] + 4] == b'TIDX':
            tidx = r
    if tidx:
        blob = tail[tidx['off']:tidx['off'] + tidx['size']]
        print('TIDX record:', tidx['name'], 'size', len(blob))
        print(blob[:96].hex(' '))
        # guess: magic TIDX, then u16? entries of {u16 crc, u16 id, name[]}
        # from hexdump: after TIDX: cb 45 ff ff ff ff ff ff 03 00 00 00 c2 9c 10 01 'bt_conn.mp3' 00 ...
        # entries look like: u16 crc, u16 id?, name z-terminated
        o = 4
        # find count field
        cnt = struct.unpack_from('<H', blob, 0x10)[0]
        print('u16@0x10 =', cnt)

    # ---- effect/DSP config area: tagged records `13 00 | crc16 | param u8 | name z` ----
    print('\n=== DSP/effect name records (tag 0x0013) ===')
    name_recs = []
    o = 0x9400
    while True:
        o = tail.find(b'\x13\x00', o)
        if o < 0 or o + 8 > len(tail):
            break
        crc, = struct.unpack_from('<H', tail, o + 2)
        p0 = tail[o + 4]
        # payload: param u8 (любой) + печатное имя + нули
        e = o + 5
        while e < len(tail) and (0x20 <= tail[e] < 0x7f or tail[e] == 0):
            e += 1
        payload = tail[o + 4:e]
        printable = sum(1 for b in payload if 0x20 <= b < 0x7f)
        if printable >= 4 and payload.rstrip(b'\0') and e - (o + 4) <= 64:
            s = payload.split(b'\0')[0].decode('ascii', 'replace')
            if len(s) >= 3:
                name_recs.append((o, e - o - 4, crc, p0, s))
                o = e
                continue
        o += 1
    print('records:', len(name_recs))
    for o, ln, crc, p0, s in name_recs[:80]:
        print(f'@{o:05x} plen={ln:3d} crc={crc:04x} p0={p0:02x} {s!r}')

    # ---- code references into the tail ----
    print('\n=== ссылки кода в хвост ===')
    lst = os.path.join(SRC, 'disasm', 'mr5_app_disasm.txt')
    NUM_RE = re.compile(r'(?<![\w.\-])(0x[0-9a-fA-F]+|\d{6,})(?![\w:])')
    LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)')
    FUNC_RE = re.compile(r'^sub_([0-9a-f]{8}):$')
    cur = None
    refs = []
    lo, hi = XIP, XIP + len(tail)
    for raw in open(lst, encoding='utf-8', errors='replace'):
        m = FUNC_RE.match(raw.rstrip())
        if m:
            cur = 'sub_' + m.group(1)
            continue
        m = LINE_RE.match(raw.rstrip())
        if not m:
            continue
        for tok in NUM_RE.findall(m.group(3)):
            v = int(tok, 0)
            if lo <= v < hi:
                refs.append((v, cur, m.group(1), m.group(3).strip()))
    # raw sweep too
    for i in range(len(data) - 5):
        if 0xC0 <= data[i] <= 0xCF and data[i + 1] == 0xFF:
            v = struct.unpack_from('<I', data, i + 2)[0]
            if lo <= v < hi:
                refs.append((v, '(raw)', f'{0x06000100+i:08x}', f'mov32 -> {v:08x}'))
    print('ссылок:', len(refs))
    seen = collections.Counter((v, f or '?') for v, f, _, _ in refs)
    for (v, f), c in sorted(seen.items(), key=lambda kv: (kv[0][0], str(kv[0][1]))):
        toff = v - XIP
        near = nearest_name(name_recs, toff)
        print(f'{v:08x} <- {f} x{c} (tail+{toff:05x}) {near}')

    # ---- markdown ----
    with open(OUT_MD, 'w', encoding='utf-8') as out:
        out.write('# C1 — ресурсный хвост MR5 (app_area_tail, 111 888 Б)\n\n')
        out.write(f'Хвост образа (файл {hex(TAIL_OFF)}…{hex(len(data))}) — '
                  'самостоятельный **ресурсный том** с JLFS-подобными записями '
                  '(32 Б, CRC16 0x11021). XIP-адрес начала: '
                  f'`{XIP:08x}`.\n\n')
        out.write('## 1. Записи тома\n\n')
        out.write('| имя | offset (в хвосте) | размер | flags | idx | data_crc | CRC данных |\n')
        out.write('|---|---|---|---|---|---|---|\n')
        for r in recs:
            ok = {True: 'OK', False: 'нет', None: '—'}[r.get('crc_ok')]
            out.write(f'| `{r["name"]}` | {hex(r["off"])} | {r["size"]} | '
                      f'{r["flags"]:02x} | {r["idx"]} | {r["data_crc"]:04x} | {ok} |\n')
        out.write('\nCRC **данных** записей тома не сходится с jl_crc16 '
                  '(ни init, ни отражённый вариант) — алгоритм сверки данных '
                  'ресурсного тома отличается; заголовки записей сходятся. TBD.\n\n')
        out.write('Извлечено в `source/decrypted/res/`.\n\n')
        out.write('## 2. TIDX — индекс тонов (`index.idx`, 67 Б)\n\n')
        if tidx:
            blob = tail[tidx['off']:tidx['off'] + tidx['size']]
            out.write('Структура: `ff ff | "TIDX" | u16 | ff ff ×3 | count:u16 '
                      '| 00 00 | записи {crc:u16, id:u16, имя z-строка}`:\n\n')
            out.write('```\n' + blob.hex(' ') + '\n```\n\n')
            # entries
            o = blob.find(b'TIDX') + 2 + 2 + 6 + 2 + 2
            out.write('| crc | id | имя |\n|---|---|---|\n')
            for _ in range(3):
                c, i = struct.unpack_from('<HH', blob, o)
                o2 = blob.find(b'\0', o + 4)
                nm = blob[o + 4:o2].decode('ascii', 'replace')
                out.write(f'| {c:04x} | {i:04x} | `{nm}` |\n')
                o = o2 + 1
            out.write('\n')
        out.write('## 3. DSP/эффекты: именованные узлы аудио-графа\n\n')
        out.write('Формат записи (переменная длина, 21 Б): '
                  '`tag:u16 = 0x0013 | crc16 | param:u8 | имя z-строка (добито '
                  'нулями до 16)`. Это **имена узлов аудио-графа Edifier** '
                  '(= содержимое `effect_cfg`-класса ресурсов; те же имена '
                  'видны в app.bin: `SET_HP_GAIN`, `AUX_DAC_GAIN`, `MusicEq`, '
                  '`EscoDlEq`, `EnergyMusic`…). `param` — номер экземпляра '
                  'узла в своей группе (у DAC24 param=0x18=24, у DAC25 — 0x19=25).\n\n')
        out.write('| смещение (хвост) | len | crc | p0 | имя |\n|---|---|---|---|---|\n')
        for o, ln, crc, p0, s in name_recs:
            out.write(f'| {hex(o)} | {ln} | {crc:04x} | {p0:#04x} | `{s}` |\n')
        out.write('\n## 4. Ссылки из кода в хвост\n\n')
        out.write('Прямых ссылок почти нет: том адресуется **по имени через '
                  'файловый API** (`flash/res/...`, `tone_zh/...`). Единственная '
                  'найденная ссылка — crt0 (`0x06000176`): `r1 = 0x0608EFFC` — '
                  'регистрация базы ресурсного тома (копия длиной 0 → передача '
                  'адреса):\n\n')
        out.write('```\n06000170: c4 ff 00 00 00 02    r4 = 33554432\n'
                  '06000176: c1 ff fc ef 08 06    r1 = 101249020  ; 0x0608EFFC\n'
                  '0600017c: c2 ff 00 00 00 00    r2 = 0\n```\n\n')
        out.write('| target | ссылка из | x | контекст |\n|---|---|---|---|\n')
        for (v, f), c in sorted(seen.items(), key=lambda kv: (kv[0][0], str(kv[0][1]))):
            toff = v - XIP
            near = nearest_name(name_recs, toff)
            out.write(f'| `{v:08x}` (tail+{hex(toff)}) | `{f}` | {c} | {near} |\n')

        out.write('\n## 5. Выводы\n\n')
        out.write(f'''1. Хвост — **автономный ресурсный том** (JLFS-записи, base=2):
   `tone_zh` (подтом тонов, 37 664 Б), `index.idx` (TIDX), 3 mp3-тона
   (bt_conn, bt_dconn, bt_dconn2).
2. `TIDX` — индекс тонов: пары (crc16, id) + имена mp3.
3. Зона DSP-конфигов (tail+0xC67C…): **62 записи** имён узлов аудио-графа
   `tag 0x0013 | crc16 | param u8 | имя` — узлы DAC*/ADC*/MIXER*/IIS0_*/
   BassShelf*/TrebShelf*/EQDIY*/Desk_Acoustic*/Vol_*/EnergyMusic*/
   ChannelExpand*/config*/SET_HP_GAIN/AUX_DAC_GAIN/Esco*/DRC*/A2DP_RX*.
   `DAC3`/`DAC25` из старого отчёта — просто имена узлов DAC (param 21/25).
4. После блока имён (tail+0xCB92…) идут двоичные структуры узлов —
   коэффициенты/конфиги (следующий шаг C1: связать размер блока имён
   с парсером effect_cfg в коде).
5. Код обращается к тому **по имени через файловый API**; единственная
   прямая ссылка — crt0 регистрирует базу тома 0x0608EFFC (копия длиной 0).
   Привязку «узел → код» делать через парсер effect_cfg (якоря B2:
   `Eq*Media`, `SET_HP_GAIN` → sub_06006390, sub_06013cf2, sub_06016d36).
''')

def crc_prefix(blob, want, maxn=None):
    crc = 0
    for i, b in enumerate(blob):
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) if crc & 0x8000 else (crc << 1)
            crc &= 0xFFFF
        if crc == want:
            return i + 1
    return None

def nearest_name(name_recs, toff):
    best = None
    for o, ln, crc, idxb, s in name_recs:
        d = toff - o
        if 0 <= d <= 256 and (best is None or d < best[0]):
            best = (d, s)
    return f'~{best[1]} (+{best[0]})' if best else ''

if __name__ == '__main__':
    main()
