#!/usr/bin/env python3
# B2: string <-> code cross-references for MR5 app.bin (pi32v2).
#
# Sources of references resolved:
#  1. direct: absolute immediate in code (mov32 imm = 0x06000100 + file offset)
#     pointing at a string start (or into a string);
#  2. indirect: pointer tables inside app.bin (u32 LE entries in the XIP
#     window) whose target is a string; the table itself is linked to code
#     immediates, so a string gets xrefs from the table's referencing code.
#
# Inputs : decrypted/app.bin, disasm/mr5_app_disasm.txt
# Output : disasm/string_xrefs.md, disasm/function_strings.json
import sys, os, re, json, struct, collections, bisect

BASE = 0x06000100
HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
APP = os.path.join(SRC, 'decrypted', 'app.bin')
LST = os.path.join(SRC, 'disasm', 'mr5_app_disasm.txt')
OUT_MD = os.path.join(SRC, 'disasm', 'string_xrefs.md')
OUT_JS = os.path.join(SRC, 'disasm', 'function_strings.json')

LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')
FUNC_RE = re.compile(r'^sub_([0-9a-f]{8}):$')
# immediates: 0x-hex or decimal, not part of a register/offset expression
NUM_RE = re.compile(r'(?<![\w.\-])(0x[0-9a-fA-F]+|\d{6,})(?![\w:])')
CALL_RE = re.compile(r'^call (-?\d+)$')

def extract_strings(data, minlen=4):
    """Maximal printable-ASCII runs (>= minlen); terminators may be NUL, \\r, \\n, etc."""
    out = {}
    start = None
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7f:
            if start is None:
                start = i
        else:
            if start is not None and i - start >= minlen:
                out[start] = data[start:i].decode('ascii', 'replace')
            start = None
    if start is not None and len(data) - start >= minlen:
        out[start] = data[start:].decode('ascii', 'replace')
    return out

def main():
    data = open(APP, 'rb').read()
    N = len(data)
    strings = extract_strings(data)
    str_starts = sorted(strings)

    # ---------- pass 1: parse listing ----------
    funcs = {}                 # start offset -> name
    func_of_addr = {}          # rebuilt after: sorted starts
    cur_name = None
    insns = {}                 # off -> (size, text, func)
    calls = []                 # (site_off, target_off)
    imm_hits = collections.defaultdict(list)  # target off -> [(site, func, text)]

    for raw in open(LST, encoding='utf-8', errors='replace'):
        raw = raw.rstrip('\n')
        m = FUNC_RE.match(raw)
        if m:
            so = int(m.group(1), 16) - BASE
            cur_name = 'sub_%08x' % (BASE + so)
            funcs[so] = cur_name
            continue
        if raw.startswith(';') or not raw.strip():
            continue
        m = LINE_RE.match(raw)
        if not m:
            continue
        off = int(m.group(1), 16) - BASE
        size = len(m.group(2).split())
        text = m.group(3).strip()
        insns[off] = (size, text, cur_name)
        cm = CALL_RE.match(text)
        if cm:
            rel = int(cm.group(1))
            tgt = (((BASE + off) + size + rel) & ~1 & 0xFFFFFFFF) - BASE
            calls.append((off, tgt))
            continue
        for tok in NUM_RE.findall(text):
            v = int(tok, 0)
            o = v - BASE
            if 0 <= o < N:
                imm_hits[o].append((off, cur_name, text))

    starts = sorted(funcs)
    def func_at(off):
        i = bisect.bisect_right(starts, off) - 1
        return funcs[starts[i]] if i >= 0 else '?'

    # ---------- pass 2: pointer tables inside app.bin ----------
    # a slot is interesting if value is a XIP-window address into app region
    ptr_slots = {}             # slot off -> target off
    for o in range(0, N - 3, 4):
        v = struct.unpack_from('<I', data, o)[0]
        t = v - BASE
        if 0 <= t < N:
            ptr_slots[o] = t

    # group contiguous slots into tables (>=2 entries, dense 4-byte step)
    tables = []                # (start_off, [targets])
    run = []
    prev = None
    for o in sorted(ptr_slots):
        if prev is not None and o == prev + 4:
            run.append(o)
        else:
            if len(run) >= 2:
                tables.append((run[0], [ptr_slots[x] for x in run]))
            run = [o]
        prev = o
    if len(run) >= 2:
        tables.append((run[0], [ptr_slots[x] for x in run]))

    # ---------- pass 3: resolve string references ----------
    # direct: imm target within [s, s+len+1] of a string
    def str_by_range(t):
        i = bisect.bisect_right(str_starts, t) - 1
        if i >= 0:
            s = str_starts[i]
            if s <= t <= s + len(strings[s]):
                return s
        return None

    direct = collections.defaultdict(set)   # str off -> {func}
    direct_sites = collections.defaultdict(list)
    for t, sites in imm_hits.items():
        s = str_by_range(t)
        if s is not None:
            for site, fn, text in sites:
                direct[s].add(fn)
                direct_sites[s].append((site, fn, text, 'direct'))

    # indirect: string -> tables containing its pointer -> funcs referencing table
    str_tables = collections.defaultdict(list)  # str off -> [(table off, idx)]
    table_strs = collections.defaultdict(set)   # table off -> {str offs}
    for toff, targets in tables:
        for idx, t in enumerate(targets):
            s = str_by_range(t)
            if s is not None:
                str_tables[s].append((toff, idx))
                table_strs[toff].add(s)

    indirect = collections.defaultdict(set)
    indirect_sites = collections.defaultdict(list)
    for toff, ss in table_strs.items():
        refs = imm_hits.get(toff)
        if not refs:
            continue
        fns = {fn for _, fn, _ in refs}
        for s in ss:
            indirect[s] |= fns
            for site, fn, text in refs:
                indirect_sites[s].append((site, fn, text, f'table@{BASE+toff:08x}+{toff}'))

    # ---------- call graph ----------
    callers = collections.defaultdict(set)
    for site, tgt in calls:
        sf = func_at(site)
        tf = funcs.get(tgt)
        if tf:
            callers[tf].add(sf)
    def caller_line(fn, depth=2):
        seen, out = set(), []
        frontier = {fn}
        for d in range(depth, 0, -1):
            nxt = set()
            for f in frontier:
                for c in callers.get(f, ()):
                    if c not in seen and c != f:
                        seen.add(c); nxt.add(c); out.append((d, c, f))
            frontier = nxt
        return out

    # ---------- pass 4: raw mov32 sweep over the whole binary ----------
    # mov32 rX, imm32 encodes as: Cx FF <imm32 LE>  (6 bytes).
    # The recursive listing covers only direct-call-reachable code (~69%),
    # so sweep the raw bytes to catch references from unreached functions.
    decoded_ranges = sorted(insns)          # file offsets of decoded insns
    import bisect as _b
    def is_decoded(off):
        i = _b.bisect_right(decoded_ranges, off) - 1
        if i < 0:
            return False
        s = decoded_ranges[i]
        return off < s + insns[s][0]

    raw_refs = collections.defaultdict(list)      # str off -> [(site, decoded?, fn)]
    raw_targets = collections.defaultdict(list)   # target off -> [(site, decoded?, fn)]
    i = 0
    while i < N - 5:
        if 0xC0 <= data[i] <= 0xCF and data[i + 1] == 0xFF:
            v = struct.unpack_from('<I', data, i + 2)[0]
            o = v - BASE
            if 0 <= o < N:
                dec = is_decoded(i)
                fn = insns[i][2] if (dec and i in insns) else (func_at(i) if dec else None)
                s = str_by_range(o)
                if s is not None:
                    raw_refs[s].append((i, dec, fn))
                raw_targets[o].append((i, dec, fn))
            i += 6
        else:
            i += 1
    for t, sites in imm_hits.items():
        for site, fn, text in sites:
            raw_targets[t].append((site, True, fn))

    # structural refs: code targets that fall in a window BEFORE a string
    # (string inline inside a struct/table whose base the code loads)
    STRUCT_WIN = 512
    struct_refs = collections.defaultdict(list)   # str off -> [(base, delta, [sites])]
    for s in strings:
        for t in range(max(0, s - STRUCT_WIN), s):
            if t in raw_targets:
                struct_refs[s].append((t, s - t, raw_targets[t]))

    # ---------- report ----------
    ANCHORS = ['MCU+', 'BLT+', 'DUT+', 'TST+', 'EDIFIER', 'jlstream', 'tone_',
               'flash/res', 'storage/', 'Eq', 'EQ', 'DRC', 'a2dp', 'BLE', 'ble',
               'usb', 'ota', 'GAIN', 'gain', 'effect', 'Vol_', 'dac', 'DAC']
    all_strs = set(direct) | set(indirect) | set(raw_refs)
    # строки, на которые есть только структурные ссылки (база структуры рядом)
    struct_only = {s for s in strings if s not in all_strs and s in struct_refs}
    print(f'strings={len(strings)} referenced={len(all_strs)} '
          f'(direct={len(direct)}, via_tables={len(indirect)}, raw={len(raw_refs)}) '
          f'struct_only={len(struct_only)} tables={len(tables)} '
          f'funcs={len(funcs)} call_edges={len(calls)}')

    with open(OUT_MD, 'w', encoding='utf-8') as out:
        out.write('# MR5: перекрёстные ссылки «строка → код» (этап B2)\n\n')
        out.write('Инструмент: `tools/xref_strings.py`. Ссылки: **direct** — '
                  'непосредственный imm в коде; **table** — через таблицу '
                  'указателей в данных (для таблицы указан её адрес).\n\n')
        out.write(f'- строк (печатные последовательности ≥4): **{len(strings)}**\n')
        out.write(f'- строк с прямыми ссылками из кода: **{len(all_strs)}** '
                  f'(листинг {len(direct)}, raw mov32 {len(raw_refs)}, таблицы {len(indirect)})\n')
        out.write(f'- строк внутри структур, на базы которых есть ссылки: '
                  f'**{len(struct_only)}** (окно 512 Б до строки)\n')
        out.write(f'- функций в листинге: **{len(funcs)}**, call-рёбер: {len(calls)}\n\n')

        def fmt_sites(s):
            parts = []
            for site, fn, text, kind in sorted(direct_sites.get(s, []) +
                                               indirect_sites.get(s, []))[:6]:
                parts.append(f'`{BASE+site:08x}` `{fn}`: `{text}`')
            return parts

        def fmt_raw(s):
            raws = raw_refs.get(s, ())
            dec = [f'`{BASE+o:08x}`({fn or "?"})' for o, d, fn in raws if d]
            und = [f'`{BASE+o:08x}`' for o, d, fn in raws if not d]
            return dec, und

        def fmt_struct(s, limit=6):
            out_l = []
            for t, delta, sites in sorted(struct_refs.get(s, []), key=lambda x: x[1])[:limit]:
                ss = ', '.join(f'`{BASE+site:08x}`' + (f'`{fn}`' if fn else '(вне декода)')
                               for site, dec, fn in sites[:3])
                out_l.append(f'база `{BASE+t:08x}` (+{delta}): {ss}')
            return out_l

        out.write('## 1. Якорные строки (MCU/BLE/DUT/EQ/ресурсы) — подробно\n\n')
        anchor_list = [s for s in sorted(all_strs | struct_only, key=lambda x: strings[x])
                       if any(a in strings[s] for a in ANCHORS)]
        for s in anchor_list:
            txt = strings[s]
            fns = sorted(direct.get(s, set()) | indirect.get(s, set()))
            out.write(f'### `{txt}` @ `{BASE+s:08x}`\n')
            for p in fmt_sites(s):
                out.write(f'- {p}\n')
            dec, und = fmt_raw(s)
            if dec:
                out.write(f'- raw mov32 (декод.): {", ".join(dec[:8])}\n')
            if und:
                out.write(f'- raw mov32 (вне декода — косвенный вызов): {", ".join(und[:8])}\n')
            sb = fmt_struct(s)
            for p in sb:
                out.write(f'- структурная ссылка: {p}\n')
            for f in fns[:6]:
                ch = caller_line(f)
                if ch:
                    out.write(f'- callers `{f}`: ' +
                              ', '.join(f'`{c}`→`{t}`' for _, c, t in ch[:8]) + '\n')
            out.write('\n')

        out.write('## 2. Все строки со ссылками (компактно)\n\n')
        out.write('| строка | адрес | функции / сырые ссылки |\n|---|---|---|\n')
        for s in sorted(all_strs, key=lambda x: strings[x]):
            txt = strings[s]
            if any(a in txt for a in ANCHORS):
                continue  # уже в §1
            fns = sorted(direct.get(s, set()) | indirect.get(s, set()))
            raws = raw_refs.get(s, ())
            cell = ", ".join(f"`{f}`" for f in fns[:3])
            if raws:
                ndec = sum(1 for _, d, _ in raws if d)
                cell += f' +raw×{len(raws)}({ndec} декод.)'
            out.write(f'| `{txt[:48]}` | `{BASE+s:08x}` | {cell} |\n')

        out.write('\n## 3. Строки только внутри структур (база рядом с кодом) — топ\n\n')
        out.write('| строка | адрес | ближайшая база (Δ) |\n|---|---|---|\n')
        cnt = 0
        for s in sorted(struct_only, key=lambda x: strings[x]):
            txt = strings[s]
            if any(a in txt for a in ANCHORS) or len(txt) < 5:
                continue
            refs = sorted(struct_refs[s], key=lambda x: x[1])
            if not refs:
                continue
            t, delta, sites = refs[0]
            out.write(f'| `{txt[:48]}` | `{BASE+s:08x}` | `{BASE+t:08x}` (+{delta}) |\n')
            cnt += 1
            if cnt > 120:
                break

        out.write('\n## 4. Функции по числу уникальных строк (кандидаты на разбор, B4)\n\n')
        fs = collections.defaultdict(set)
        for s, fset in list(direct.items()) + list(indirect.items()):
            for f in fset:
                fs[f].add(s)
        out.write('| функция | строк | примеры |\n|---|---|---|\n')
        for f, ss in sorted(fs.items(), key=lambda kv: -len(kv[1]))[:80]:
            ex = [strings[o][:28] for o in sorted(ss)[:4]]
            out.write(f'| `{f}` | {len(ss)} | {", ".join("`"+e+"`" for e in ex)} |\n')

    json.dump({f: sorted(strings[s] for s in ss) for f, ss in fs.items()},
              open(OUT_JS, 'w', encoding='utf-8'), ensure_ascii=False, indent=1)
    print('wrote', OUT_MD, 'and', OUT_JS)

if __name__ == '__main__':
    main()
