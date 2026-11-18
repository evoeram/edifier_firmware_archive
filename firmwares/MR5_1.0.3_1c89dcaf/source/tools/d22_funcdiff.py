#!/usr/bin/env python3
"""D2.2: function-level diff MR5 1.0.3 vs MR4.5 / MR4_MKII (JieLi family).

Step 1 (this script): for every NAMED MR5 function (functions.csv, XIP
06000100+off), locate its byte image in the sibling models' app.bin
(exact search of the first 64 bytes -> anchor delta), then compare the
whole body byte-for-byte at the anchored offset.

Output: findings/D2_2_funcdiff.md + .json
"""
import csv
import json
import os
import re
import struct

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
ARCH = os.path.normpath(os.path.join(SRC, '..', '..', '..'))
DEC = os.path.join(ARCH, 'decrypted')
FUNCS = os.path.join(SRC, 'ghidra_export', 'functions.csv')
OUT_JS = os.path.join(SRC, 'findings', 'D2_2_funcdiff.json')
OUT_MD = os.path.join(SRC, 'findings', 'D2_2_funcdiff.md')

BASE = 0x06000100
SIBLINGS = ['MR4.5_1.0.1_fb09ee14', 'MR4_MKII_1.0.1_d5acc167']


def jl_crc16(data, crc=0):
    for b in data:
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) if crc & 0x8000 else (crc << 1)
            crc &= 0xFFFF
    return crc


def parse_jlfs(d):
    out = {}
    off = 2
    while off + 32 <= len(d):
        hcrc, hdr = struct.unpack_from('<H30s', d, off)
        if jl_crc16(hdr) != hcrc:
            break
        edcrc, eoff, esize, eflags, _, eidx, ename = struct.unpack(
            '<HIIBBH16s', hdr)
        name = ename.split(b'\0')[0].decode('ascii', 'replace')
        out[name] = (eoff, esize, edcrc)
        if eidx != 0:
            break
        off += 32
    return out


def load_app(model):
    d = open(os.path.join(DEC, model + '_dec.bin'), 'rb').read()
    ents = parse_jlfs(d)
    eoff, esize, _ = ents['app.bin']
    return d[eoff:eoff + esize]


def main():
    apps = {m: load_app(m) for m in ['MR5_1.0.3_1c89dcaf'] + SIBLINGS}
    mr5 = apps['MR5_1.0.3_1c89dcaf']

    named = []
    b42 = json.load(open(os.path.join(SRC, 'disasm', 'b42_funcs.json'),
                         encoding='utf-8'))
    for row in csv.DictReader(open(FUNCS, encoding='utf-8')):
        e = row['entry']
        nm = row['name']
        if not e.startswith('06') or int(e, 16) < BASE:
            continue
        if re.match(r'^(FUN_|thunk_|sub_)', nm):
            continue
        d = b42.get(e.lower())
        size = d['size'] if d else int(row['size'])
        named.append((int(e, 16) - BASE, size, nm))
    named.sort()
    print(f'MR5 named functions in XIP: {len(named)}')

    res = []
    for off, size, nm in named:
        body = mr5[off:off + size]
        if len(body) < size:
            continue
        rec = {'name': nm, 'mr5_off': off, 'size': size}
        for m in SIBLINGS:
            b = apps[m]
            pos = -1
            # try anchors: start, quarters (immediates may poison the head)
            for ao in (0, size // 4, size // 2, size - 64):
                if ao < 0:
                    continue
                anc = body[ao:ao + 64]
                if len(anc) < 32:
                    continue
                p = b.find(anc)
                if p >= 0:
                    pos = p - ao
                    break
            if pos < 0:
                rec[m] = {'status': 'not_found'}
                continue
            delta = pos - off
            other = b[pos:pos + size]
            diff = sum(1 for x, y in zip(other, body) if x != y)
            rec[m] = {'status': 'identical' if diff == 0 else 'changed',
                      'delta': delta, 'diff_bytes': diff,
                      'sim': round(1 - diff / size, 4)}
        res.append(rec)

    ident = sum(1 for r in res
                if all(r[m].get('status') == 'identical' for m in SIBLINGS))
    nf = sum(1 for r in res
             if any(r[m].get('status') == 'not_found' for m in SIBLINGS))
    chg = [r for r in res
           if any(r[m].get('status') == 'changed' for m in SIBLINGS)]
    print(f'identical in both: {ident}; not_found somewhere: {nf}; '
          f'changed somewhere: {len(chg)}')
    for r in chg:
        print(' changed:', r['name'], r['size'], 'B',
              {m: (r[m].get('diff_bytes'), r[m].get('sim'))
               for m in SIBLINGS if r[m].get('status') == 'changed'})

    json.dump(res, open(OUT_JS, 'w', encoding='utf-8'), indent=1)

    # report
    with open(OUT_MD, 'w', encoding='utf-8') as f:
        f.write('# D2.2 — function-level дифф MR5 1.0.3 ↔ MR4.5 / MR4_MKII\n\n')
        f.write('Метод: якорь (первые 64 Б тела функции) ищется в app.bin '
                'родственника, затем тело сравнивается побайтово. '
                f'Именованных функций MR5 в XIP: {len(named)}.\n\n')
        f.write(f'- идентичны в обоих: **{ident}**\n')
        f.write(f'- изменены хотя бы в одном: **{len(chg)}**\n')
        f.write(f'- якорь не найден: **{nf}**\n\n')
        f.write('## Изменённые функции\n\n')
        f.write('| функция | размер | MR4.5 | MR4_MKII |')
        f.write(' (diff Б, сходство, сдвиг)\n|---|---|---|---|\n')
        for r in chg:
            a = r[SIBLINGS[0]]
            b = r[SIBLINGS[1]]

            def cell(x):
                if x['status'] == 'identical':
                    return '≡'
                if x['status'] == 'not_found':
                    return '?'
                return (f'{x["diff_bytes"]} Б diff, sim {x["sim"]:.3f}, '
                        f'δ{x["delta"]:+d}')
            f.write(f'| {r["name"]} | {r["size"]} | {cell(a)} | '
                    f'{cell(b)} |\n')
        f.write('\n## Полный список (идентичные)\n\n')
        for r in res:
            if r not in chg:
                dd = {m: r[m].get('delta', '?') for m in SIBLINGS}
                f.write(f'- {r["name"]} ({r["size"]} Б, '
                        f'δ {dd[SIBLINGS[0]]}/{dd[SIBLINGS[1]]})\n')
    print('wrote', OUT_MD)


if __name__ == '__main__':
    main()
