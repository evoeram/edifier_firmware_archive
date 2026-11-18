#!/usr/bin/env python3
"""F1 (plan NEW2): build expert dossiers for the unnamed RAM-overlay targets.

For each unnamed target: decompiled body, callees (named ones resolved),
touched globals/registers, app-side callers with their strings, size, sites.
Output: disasm/b5_dossiers.md (human) + disasm/b5_dossiers.json (machine).
"""
import io
import json
import re
import csv

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
XIP = 0x06000100

targets = json.load(io.open(SRC + r'\disasm\b3_far_targets.json',
                            encoding='utf-8'))
sigs = json.load(io.open(SRC + r'\disasm\b3_signatures.json', encoding='utf-8'))
b42 = json.load(io.open(SRC + r'\disasm\b42_funcs.json', encoding='utf-8'))

# name maps: flash VA -> name
names = {}
for k, v in sigs.items():
    names[int(k, 16)] = v['name']
with open(SRC + r'\ghidra_export\functions.csv', encoding='utf-8') as fh:
    for row in csv.DictReader(fh):
        nm = row.get('name', '')
        va = int(row['entry'], 16)
        if nm and not nm.startswith(('FUN_', 'sub_', 'thunk_')):
            names.setdefault(va, nm)
# semantic + chain names from far targets
for k, e in targets.items():
    fe = e.get('flash_equiv')
    if e.get('name') and fe:
        names.setdefault(int(fe, 16), e['name'])

# parse decomp dump
decomp = {}
cur_key = None
buf = []
for l in io.open(SRC + r'\disasm\b3_overlay_decomp.c', encoding='utf-8',
                 errors='replace'):
    if l.startswith('// ===== '):
        if cur_key:
            decomp[cur_key] = ''.join(buf)
        head = l.split('@ ')[1].strip()
        cur_key = head.split()[0].lstrip('FUN_')
        buf = []
    elif cur_key:
        buf.append(l)
if cur_key:
    decomp[cur_key] = ''.join(buf)
print('decomp entries:', len(decomp))

# unnamed targets, sorted by sites
unnamed = []
for k, e in targets.items():
    if e['kind'] == 'ram-overlay' and 'name' not in e:
        unnamed.append((int(e['flash_equiv'], 16), int(k, 16), e))
unnamed.sort(key=lambda x: -x[2]['sites'])
print('unnamed targets:', len(unnamed))

call_re = re.compile(r'(?:FUN_|func_0x)([0-9a-f]{8})')
glob_re = re.compile(r'0x(00[0-9a-f]{6}|[0-9a-f]{8})')
reg_regions = [
    (0x108000, 0x10a000, 'OS-arrays'),
    (0x0ff0000, 0x1000000, 'core/IRQ'),
    (0x0fd0000, 0x0fe0000, 'periph-A'),
    (0x0fe0000, 0x0ff0000, 'periph-B(clk/pll)'),
]


def classify_globals(body):
    tags = set()
    for m in re.finditer(r'0x([0-9a-f]{6,8})', body):
        v = int(m.group(1), 16)
        for lo, hi, tag in reg_regions:
            if lo <= v < hi:
                tags.add(tag)
    return sorted(tags)


def callees_of(body):
    out = []
    for m in call_re.finditer(body):
        va = int(m.group(1), 16)
        if 0x06000000 <= va < 0x06100000:
            out.append(va)
    return out


md = ['# F1: досье безымянных функций RAM-оверлея (по убыванию сайтов)\n']
js = {}
for fe, ram, e in unnamed:
    key = f'{fe:08x}'
    body = decomp.get(key.lstrip('0'), decomp.get(key, ''))
    if not body:
        # dump keys have no leading zeros: try int->8hex no-pad form
        body = decomp.get(f'{fe:08x}'.lstrip('0'), '')
    cal = [c for c in callees_of(body) if c != fe]
    named_calls = sorted({names[c] for c in cal if c in names})
    ov_calls = sorted(f'{c - XIP:06x}' for c in cal
                      if c not in names and c >= 0x06000000)
    callers = e.get('callers', [])
    cstr = []
    for c in callers[:6]:
        cf = b42.get(c)
        if cf and cf.get('strings'):
            cstr.append((c, cf['strings'][0]))
    glob_tags = classify_globals(body)
    nlines = len(body.splitlines()) if body else 0
    d = {'ram': f'{ram:08x}', 'flash': key, 'sites': e['sites'],
         'size_lines': nlines, 'glob_tags': glob_tags,
         'named_calls': named_calls, 'overlay_calls': ov_calls,
         'caller_strings': cstr}
    js[key] = d
    md.append(f"## ovl_{fe - XIP:06x} (RAM {ram:08x}) — {e['sites']} сайтов, "
              f"~{nlines} строк декомпила, глобалы: "
              f"{', '.join(glob_tags) or '-'}")
    if named_calls:
        md.append(f"- вызывает именованные: {', '.join(named_calls[:8])}")
    if ov_calls:
        md.append(f"- вызывает оверлей: {', '.join(ov_calls[:8])}")
    if cstr:
        md.append('- вызывающие (app) со строками: ' + '; '.join(
            f'{c}: {s[:26]!r}' for c, s in cstr))
    md.append('')

io.open(SRC + r'\disasm\b5_dossiers.md', 'w', encoding='utf-8').write(
    '\n'.join(md))
json.dump(js, io.open(SRC + r'\disasm\b5_dossiers.json', 'w',
                      encoding='utf-8'), indent=0, ensure_ascii=False)
print('wrote b5_dossiers.md / .json')
