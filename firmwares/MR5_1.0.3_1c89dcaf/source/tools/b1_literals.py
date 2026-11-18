#!/usr/bin/env python3
"""B1: inventory of literal fragments (operators) between placeholders."""
import sys
import collections
import os

PKG = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
sys.path.insert(0, PKG)
os.chdir(PKG)
from pi32v2isa.table import load, SYNTAX_TOKEN  # noqa: E402

TABLE = load()
lits = collections.Counter()
for insn in TABLE.insns:
    pos = 0
    for m in SYNTAX_TOKEN.finditer(insn.syntax):
        if m.start() > pos:
            lits[insn.syntax[pos:m.start()]] += 1
        pos = m.end()
    if pos < len(insn.syntax):
        lits[insn.syntax[pos:]] += 1

print(len(lits), 'distinct literals')
for s, n in lits.most_common(120):
    print(f'{n:5d}  {s!r}')
