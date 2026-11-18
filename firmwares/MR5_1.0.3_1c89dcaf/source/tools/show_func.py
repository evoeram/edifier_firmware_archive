#!/usr/bin/env python3
# Print a function body from the recursive-disassembly listing.
# usage: python show_func.py sub_0600a278 [max_lines]
import sys, os, re

LST = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                   'disasm', 'mr5_app_disasm.txt')

def main():
    name = sys.argv[1]
    limit = int(sys.argv[2]) if len(sys.argv) > 2 else 400
    lines = open(LST, encoding='utf-8', errors='replace').read().splitlines()
    start = None
    for i, l in enumerate(lines):
        if l.startswith(name + ':') or l.startswith(name + ' '):
            start = i
            break
    if start is None:
        # try address form
        m = re.match(r'([0-9a-f]{8})', name)
        if m:
            want = 'sub_' + m.group(1)
            for i, l in enumerate(lines):
                if l.startswith(want + ':'):
                    start = i
                    break
    if start is None:
        sys.exit(f'{name} not found')
    out = [lines[start]]
    for l in lines[start + 1:start + 1 + limit]:
        if re.match(r'^sub_[0-9a-f]{8}:$', l):
            break
        out.append(l)
    print('\n'.join(out))

if __name__ == '__main__':
    main()
