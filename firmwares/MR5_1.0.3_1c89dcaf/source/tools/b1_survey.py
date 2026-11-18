#!/usr/bin/env python3
"""B1 survey: classify instruction forms by structural template of their syntax
placeholder kinds, to plan p-code generation."""
import sys
import collections
import os

PKG = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
sys.path.insert(0, PKG)
os.chdir(PKG)
from pi32v2isa.table import load, SYNTAX_TOKEN  # noqa: E402

TABLE = load()

templates = collections.Counter()
by_t = collections.defaultdict(list)
for insn in TABLE.insns:
    sig_parts = []
    pos = 0
    for m in SYNTAX_TOKEN.finditer(insn.syntax):
        if m.start() > pos:
            sig_parts.append(insn.syntax[pos:m.start()])
        if m.group(0) in ('{{', '}}'):
            continue
        if m.group(2):
            f = insn.fields[m.group(2)]
            k = 'gpr' if f.kind in ('gpr_lo', 'gpr_hi') else f.kind
            sig_parts.append('+' if m.group(1) else k)
        else:
            sig_parts.append(m.group(0))
        pos = m.end()
    if pos < len(insn.syntax):
        sig_parts.append(insn.syntax[pos:])
    sig = ' '.join(s.strip() for s in sig_parts if s.strip())
    templates[sig] += 1
    by_t[sig].append(insn.id)

print(f'{len(templates)} templates, {sum(templates.values())} forms')
for sig, n in templates.most_common(60):
    print(f'{n:5d}  {sig}')
    if n <= 3:
        print('        ', ', '.join(by_t[sig][:6]))
