#!/usr/bin/env python3
# Print a function dossier for B4.2 naming: strings, callees, callers with
# their evidence. usage: python b42_dossier.py 0600a278 [depth]
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
J = json.load(open(os.path.join(SRC, 'disasm', 'b42_funcs.json'),
                   encoding='utf-8'))

# Ghidra names from functions.csv (entry -> name)
NAMES = {}
try:
    import csv
    for row in csv.DictReader(open(os.path.join(SRC, 'ghidra_export',
                                                'functions.csv'),
                                   encoding='utf-8')):
        NAMES[row['entry'].lower()] = row['name']
except FileNotFoundError:
    pass


def nm(a):
    d = J.get(a, {})
    lbl = NAMES.get(a) or d.get('label') or ''
    return lbl if lbl else f'unk_{a}'


def brief(a, width=64):
    d = J.get(a)
    if not d:
        return f'{nm(a)} ({a}) [no data]'
    ss = '; '.join(d['strings'][:4])
    return (f'{nm(a)} ({a}, {d["size"]}B, callers={len(d["callers"])})'
            + (f' str: {ss[:width]}' if ss else ''))


def dossier(a, depth=1):
    d = J.get(a)
    if not d:
        print(f'== {a}: not in listing data')
        return
    print(f'== {nm(a)} @ {a} size={d["size"]} regcalls={d["regcalls"]}')
    if d['strings']:
        print('  strings:')
        for s in d['strings'][:12]:
            print(f'    - {s!r}')
    if d['imms']:
        print(f'  imms: {", ".join(d["imms"][:10])}')
    print(f'  callees ({len(d["calls"])}):')
    for c in d['calls']:
        print('    ', brief(c))
    print(f'  callers ({len(d["callers"])}):')
    for c in d['callers']:
        print('    ', brief(c))
    if depth >= 1:
        for c in d['calls'][:6]:
            cd = J.get(c)
            if cd and cd['calls']:
                print(f'  -- callees of {nm(c)}:')
                for cc in cd['calls'][:8]:
                    print('      ', brief(cc))


if __name__ == '__main__':
    dossier(sys.argv[1], int(sys.argv[2]) if len(sys.argv) > 2 else 1)
