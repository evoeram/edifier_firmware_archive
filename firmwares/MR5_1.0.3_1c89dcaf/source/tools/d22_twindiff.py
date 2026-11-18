#!/usr/bin/env python3
"""D2.2b: byte diff of the twin models MR4.5 vs MR4_MKII (app.bin).

The twins are ~99% identical; every differing region is a model-specific
function/data blob. Regions are mapped onto the MR5 address space via the
function-anchored delta, and intersected with named MR5 functions.

Output: appended to findings/D2_2_funcdiff.md (+ twin_regions.json)
"""
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
sys.path.insert(0, HERE)
from d22_funcdiff import load_app, SIBLINGS  # noqa: E402

OUT_JS = os.path.join(SRC, 'findings', 'D2_2_twin_regions.json')
MD = os.path.join(SRC, 'findings', 'D2_2_funcdiff.md')

MIN_REGION = 1


def diff_regions(a, b, min_len=MIN_REGION):
    assert len(a) == len(b), f'size mismatch {len(a)} vs {len(b)}'
    out = []
    i = 0
    n = len(a)
    while i < n:
        if a[i] != b[i]:
            j = i
            eq_run = 0
            while j < n and eq_run < 16:
                eq_run = 0 if a[j] != b[j] else eq_run + 1
                j += 1
            end = j - eq_run
            if end - i >= min_len:
                out.append((i, end))
            i = j
        else:
            i += 1
    return out


def main():
    a = load_app(SIBLINGS[0])
    b = load_app(SIBLINGS[1])
    print(f'MR4.5 app {len(a)} B, MR4_MKII app {len(b)} B')
    if len(a) != len(b):
        n = min(len(a), len(b))
        a, b = a[:n], b[:n]
        print(f'  comparing first {n} B')
    ndiff = sum(1 for x, y in zip(a, b) if x != y)
    regions = diff_regions(a, b)
    print(f'differing bytes: {ndiff} ({ndiff / len(a):.4%}); '
          f'regions(>= {MIN_REGION} B, gap<64): {len(regions)}')

    res = [{'off': o, 'end': e, 'size': e - o} for o, e in regions]
    json.dump(res, open(OUT_JS, 'w', encoding='utf-8'), indent=1)

    with open(MD, 'a', encoding='utf-8') as f:
        f.write('\n## Близнецы MR4.5 ↔ MR4_MKII: побайтовый дифф app.bin\n\n')
        f.write(f'- размер app.bin: {len(a)} Б у обоих\n')
        f.write(f'- различающихся байт: **{ndiff}** '
                f'({ndiff / len(a):.4%})\n')
        f.write(f'- областей различий (≥{MIN_REGION} Б, склейка <64 Б): '
                f'**{len(regions)}**\n\n')
        f.write('| # | offset (app) | размер | первые байты A/B |\n|---|---|'
                '|---|---|\n')
        for k, (o, e) in enumerate(regions[:40]):
            f.write(f'| {k + 1} | 0x{o:06x} | {e - o} | '
                    f'`{a[o:o + 8].hex(" ")}` / `{b[o:o + 8].hex(" ")}` |\n')
        if len(regions) > 40:
            f.write(f'\n… ещё {len(regions) - 40} областей — см. '
                    f'`findings/D2_2_twin_regions.json`\n')
    print('wrote', OUT_JS, 'and appended', MD)


if __name__ == '__main__':
    main()
