#!/usr/bin/env python3
# Print the decompiled C body of one function from ghidra_export/mr5_decomp_all.c.
# usage: python show_c.py 0600a278 [max_lines]
import sys, os, re

PATH = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                    'ghidra_export', 'mr5_decomp_all.c')

def main():
    addr = sys.argv[1].lower().removeprefix('0x')
    limit = int(sys.argv[2]) if len(sys.argv) > 2 else 250
    want = f'@ {addr}'
    lines = open(PATH, encoding='utf-8', errors='replace').read().splitlines()
    start = None
    for i, l in enumerate(lines):
        if l.startswith('// ====') and want in l:
            start = i
            break
    if start is None:
        sys.exit(f'function @{addr} not found')
    out = [lines[start]]
    for l in lines[start + 1:start + 1 + limit]:
        if l.startswith('// ===='):
            break
        out.append(l)
    print('\n'.join(out))

if __name__ == '__main__':
    main()
