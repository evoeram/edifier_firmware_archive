#!/usr/bin/env python3
"""Быстрый осмотр .bin без внешних библиотек: размер, SHA-256, энтропия, строки."""
import argparse, hashlib, math, re, sys
from collections import Counter
from pathlib import Path

ap = argparse.ArgumentParser()
ap.add_argument('file')
ap.add_argument('--strings', type=int, default=80, help='сколько строк показать')
ap.add_argument('--minlen', type=int, default=6)
a = ap.parse_args()
p = Path(a.file)
d = p.read_bytes()
print('file    :', p)
print('size    :', len(d), 'bytes')
print('sha256  :', hashlib.sha256(d).hexdigest())
print('md5     :', hashlib.md5(d).hexdigest())
print('first64 :', d[:64].hex())
c = Counter(d)
ent = -sum((n/len(d)) * math.log2(n/len(d)) for n in c.values())
print('entropy :', f'{ent:.3f}', '/ 8.000  (≈8 => сжато или зашифровано)')
print('topbytes:', ', '.join(f'{k:02x}={v}' for k, v in c.most_common(8)))
strs = []
for s in re.findall(rb'[\x20-\x7e]{%d,}' % a.minlen, d):
    t = s.decode('ascii', 'replace')
    if t not in strs:
        strs.append(t)
print(f'printable strings (>= {a.minlen}): {len(strs)} unique; show {min(a.strings, len(strs))}')
for s in strs[:a.strings]:
    print('  ', repr(s[:200]))
