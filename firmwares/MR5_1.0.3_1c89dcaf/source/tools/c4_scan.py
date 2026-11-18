#!/usr/bin/env python3
"""C4: build the data-markup manifest for Ghidra (restores the markup lost
when the full disassembly overwrote data as junk instructions).

Sources (decrypted app_bin_full.bin, XIP base 06000100):
  a4   - strings_for_ghidra.json (A4: 2426 listing-free strings; 1657 were
         marked before the project's data markup got wiped)
  b2   - string_xrefs.md anchors: 136 strings with direct/structural code
         references (clear junk instructions over them)
  tables - dense runs (>=2, step 4) of u32 pointing into the app region,
         outside function bodies -> pointer arrays

NOTE: the A4-leftover 'u32 tables with 10 20 40 80 / 30 60 c0 motifs' do NOT
exist in the decrypted image (byte-level search: 0 hits); that observation
came from the encrypted view -> sub-task dropped.

Output: disasm/c4_manifest.json
"""
import bisect
import csv
import json
import os
import re
import struct

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
APP = os.path.join(SRC, 'decrypted', 'app_bin_full.bin')
FUNCS = os.path.join(SRC, 'ghidra_export', 'functions.csv')
A4 = os.path.join(SRC, 'disasm', 'strings_for_ghidra.json')
MD = os.path.join(SRC, 'disasm', 'string_xrefs.md')
OUT = os.path.join(SRC, 'disasm', 'c4_manifest.json')

BASE = 0x06000100
HDR_RE = re.compile(r'^### `(.*)` @ `([0-9a-f]{8})`')


def string_len(data, off, cap=4096):
    """Printable run length at off (NUL or non-printable ends it)."""
    n = 0
    while off + n < len(data) and n < cap and 0x20 <= data[off + n] < 0x7f:
        n += 1
    return n


def main():
    data = open(APP, 'rb').read()
    n = len(data)

    franges = []
    with open(FUNCS, newline='', encoding='utf-8') as f:
        for row in csv.DictReader(f):
            entry = int(row['entry'], 16) - BASE
            franges.append((entry, entry + int(row['size'])))
    franges.sort()
    fstarts = [a for a, _ in franges]

    def in_func(off):
        i = bisect.bisect_right(fstarts, off) - 1
        return i >= 0 and franges[i][0] <= off < franges[i][1]

    out = {'strings': [], 'tables': []}
    seen = set()

    # ---- a4 free strings ----
    for s in json.load(open(A4, encoding='utf-8')):
        if s['addr'] in seen:
            continue
        seen.add(s['addr'])
        out['strings'].append({'addr': s['addr'], 'len': s['len'],
                               'src': 'a4'})

    # ---- b2 referenced strings (clear junk instructions over them) ----
    nb2 = 0
    cur = None
    for ln in open(MD, encoding='utf-8'):
        m = HDR_RE.match(ln.rstrip())
        if m:
            cur = int(m.group(2), 16)
            continue
        if cur is not None and ln.startswith('- ') and cur not in seen:
            seen.add(cur)
            off = cur - BASE
            slen = string_len(data, off)
            if slen < 4:
                cur = None
                continue
            out['strings'].append({'addr': cur, 'len': slen, 'src': 'b2'})
            nb2 += 1
            cur = None
        elif cur is not None and not ln.startswith((' ', '-', '#', '```')):
            cur = None

    # ---- pointer tables ----
    ptr_slots = {}
    for o in range(0, n - 3, 4):
        v = struct.unpack_from('<I', data, o)[0]
        t = v - BASE
        if 0 <= t < n:
            ptr_slots[o] = t
    runs = []
    run = []
    prev = None
    for o in sorted(ptr_slots):
        if prev is not None and o == prev + 4:
            run.append(o)
        else:
            if len(run) >= 2:
                runs.append(run)
            run = [o]
        prev = o
    if len(run) >= 2:
        runs.append(run)
    for run in runs:
        a, b = run[0], run[-1] + 4
        if in_func(a) or in_func(b - 1):
            continue
        out['tables'].append({'addr': BASE + a, 'n': len(run)})

    json.dump(out, open(OUT, 'w', encoding='utf-8'), ensure_ascii=False, indent=1)
    srcs = {}
    for s in out['strings']:
        srcs[s['src']] = srcs.get(s['src'], 0) + 1
    print('strings:', len(out['strings']), srcs)
    print('pointer tables:', len(out['tables']))
    print('wrote', OUT)


if __name__ == '__main__':
    main()
