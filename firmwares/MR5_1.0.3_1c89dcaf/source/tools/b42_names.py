#!/usr/bin/env python3
"""B4.2: build the rename manifest for still-unnamed functions.

Bulk rule (B4 convention): name = f_<sanitized top distinctive string>,
where distinctive = window-matched, not seen in >12 functions' windows
(noise = shared tables), printable and mostly alphanumeric (rejects binary
junk like 'p~?#C~?#').

Expert names: functions reviewed manually at asm level (see
findings/B4_2_names.md for the evidence chains).

Output: disasm/b42_manifest.json  {sub_ADDR: {name, strings:[...], how}}
"""
import csv
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
FUNCS_J = os.path.join(SRC, 'disasm', 'b42_funcs.json')
CSV = os.path.join(SRC, 'ghidra_export', 'functions.csv')
OUT = os.path.join(SRC, 'disasm', 'b42_manifest.json')

# manual review 2026-11-18 (asm evidence; details in findings/B4_2_names.md)
EXPERT = {
    '0600ba7c': 'dut_tst_cmd_handler',
    '06013202': 'dut_tst_get_resp',
    '060109f0': 'dut_tst_strtbl_get_a',
    '06010a06': 'dut_tst_strtbl_get_b',
    '06014348': 'dut_tst_get_send',
    '0605312e': 'effect_cfg_mgr',
    '06072d92': 'ota_file_lookup',
    '0604b08e': 'jlstream_res_init',
    '0604c65c': 'effect_nodes_close',
    '0600e3d8': 'effect_nodes_open',
    '060724f4': 'sdfile_dev_tbl_scan',
}

GOOD_RE = re.compile(r'[A-Za-z0-9_]')


def ok_string(s):
    """Plausible human-readable string, not binary junk (float/code tables
    also decode into printable ASCII, so a marker test is needed)."""
    s = s.strip()
    if len(s) < 5:
        return False
    if not re.fullmatch(r'[\x20-\x7e]+', s):
        return False
    if re.search(r'[\x60@\[\]{}<>|~^\\"]', s):
        return False
    letters = sum(1 for c in s if c.isalpha())
    if letters < 4 or len(set(s)) < 4 or len(s) > 64:
        return False
    if re.search(r'(.)\1{3,}', s):
        return False
    if '/' in s or '+' in s:
        return True
    if '_' in s and re.search(r'[a-z]{2}', s):
        return True
    if re.search(r'[A-Za-z]{3,}\.', s):
        return True
    words = [w for w in re.split(r'[^A-Za-z0-9]+', s) if w]
    if len(words) >= 2 and sum(1 for w in words if len(w) >= 3) >= 2:
        return True
    if re.search(r'[a-z]{4,}', s):
        return True
    return False


def sanitize(s):
    r = re.sub(r'[^A-Za-z0-9_]', '_', s)
    r = re.sub(r'_+', '_', r).strip('_')
    return r[:40].lower()


def main():
    funcs = json.load(open(FUNCS_J, encoding='utf-8'))
    names = {}
    for row in csv.DictReader(open(CSV, encoding='utf-8')):
        names[row['entry'].lower().zfill(8)] = row['name']

    # noise: strings window-matched by many functions (shared data tables)
    from collections import Counter
    cnt = Counter()
    for d in funcs.values():
        for s in set(d['strings']):
            cnt[s] += 1
    noise = {s for s, n in cnt.items() if n > 12}

    manifest = {}
    used = set()
    # expert names first (win over bulk)
    for a, nm in EXPERT.items():
        key = 'sub_' + a
        d = funcs.get(key, {})
        manifest[key] = {'name': nm, 'how': 'expert',
                         'strings': d.get('strings', [])[:12]}
        used.add(nm)

    for a, d in funcs.items():
        if a in manifest or a in EXPERT:
            continue
        nm = names.get(a.lower(), '')
        if nm and not nm.startswith(('FUN_', 'sub_', 'thunk_')):
            continue
        dists = d.get('strdist', {})
        good = [(dists.get(s, 512), -len(s), s)
                for s in d['strings']
                if s not in noise and ok_string(s) and dists.get(s, 512) <= 128]
        if not good:
            continue
        good.sort()
        top = good[0][2]
        base = 'f_' + sanitize(top)
        if len(base) < 4:
            continue
        nm2, k = base, 2
        while nm2 in used:
            nm2 = f'{base}_{k}'
            k += 1
        used.add(nm2)
        manifest[a] = {'name': nm2, 'how': 'string',
                       'strings': [g[2] for g in good[:12]]}

    json.dump(manifest, open(OUT, 'w', encoding='utf-8'),
              ensure_ascii=False, indent=1)
    # normalize keys to sub_XXXXXXXX (B42Apply derives the address from key)
    manifest = {('sub_' + k.removeprefix('sub_')) if not k.startswith('sub_')
                else k: v for k, v in manifest.items()}
    json.dump(manifest, open(OUT, 'w', encoding='utf-8'),
              ensure_ascii=False, indent=1)
    exp = sum(1 for m in manifest.values() if m['how'] == 'expert')
    print(f'manifest: {len(manifest)} names ({exp} expert, '
          f'{len(manifest) - exp} by-string)')
    print('wrote', OUT)


if __name__ == '__main__':
    main()
