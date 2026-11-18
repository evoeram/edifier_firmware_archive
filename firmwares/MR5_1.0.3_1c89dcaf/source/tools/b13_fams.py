#!/usr/bin/env python3
# B1.3: print id | syntax | summary for selected families
import sys, os

PKG = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
sys.path.insert(0, PKG)
os.chdir(PKG)
from pi32v2isa.table import load  # noqa: E402

TABLE = load()
WANT = {'madd', 'msub', 'mul', 'mul2', 'mul4', 'mov', 'li', 'all', 'any',
        'cmp', 'sum', 'addadd', 'st', 'ld', 'pop', 'push', 'xchg', 'lsr',
        'shl3', 'ror', 'cycc', 'packb', 'unpackb', 'ftof', 'ftoi', 'ext',
        'insert', 'uextra', 'sextra', 'popcnt', 'ldm', 'stm', 'add4',
        'div', 'shiftr', 'sat16', 'vsat16', 'unpack4', 'copex', 'mts0', 'clz'}
seen = set()
for insn in TABLE.insns:
    fam = insn.id.split('.')[0]
    if fam not in WANT:
        continue
    print(f'{insn.id:28s} | {insn.syntax:44s} | {insn.summary[:70]}')
