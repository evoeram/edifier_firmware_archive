#!/usr/bin/env python3
"""B4.2: aggregate per-function evidence from the disassembly listing.

Listing numbers (call targets, immediates) are decimal, far calls negative.

For every function (label `sub_XXXXXXXX:` or named `label:`) collect:
  - call edges (callee -> callers); register-calls counted, no target
  - immediate references into the XIP window
  - referenced string texts (from app.bin extraction)

Output: disasm/b42_funcs.json
"""
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
LST = os.path.join(SRC, 'disasm', 'mr5_app_disasm.txt')
APP = os.path.join(SRC, 'decrypted', 'app_bin_full.bin')
OUT = os.path.join(SRC, 'disasm', 'b42_funcs.json')

BASE = 0x06000100
INS_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')
SUB_RE = re.compile(r'^sub_([0-9a-f]{8}):$')
LBL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):$')
CALL_RE = re.compile(r'^call (-?\d+)$')


def extract_strings(data, minlen=4):
    out = {}
    start = None
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7f:
            if start is None:
                start = i
        else:
            if start is not None and i - start >= minlen:
                out[start] = data[start:i].decode('ascii', 'replace')
            start = None
    return out


def main():
    data = open(APP, 'rb').read()
    str_by_addr = {BASE + o: t
                   for o, t in extract_strings(data).items()}
    hi = BASE + len(data)

    info = {}
    cur = None
    pending_label = None
    for raw in open(LST, encoding='utf-8', errors='replace'):
        ln = raw.rstrip()
        if ln.startswith(';') or not ln.strip():
            continue
        m = SUB_RE.match(ln)
        if m:
            pending_label = 'sub_' + m.group(1)
            continue
        m = LBL_RE.match(ln)
        if m:
            pending_label = m.group(1)
            continue
        m = INS_RE.match(ln)
        if not m:
            continue
        addr = int(m.group(1), 16)
        size = len(m.group(2).split())
        text = m.group(3).strip()
        if pending_label is not None:
            cur = addr
            info.setdefault(cur, {'size': 0, 'calls': [], 'regcalls': 0,
                                  'imms': [], 'strs': [], 'anchor': [], 'strdist': {},
                                  'label': pending_label})
            pending_label = None
        elif cur is None or addr < cur:
            cur = addr
            info.setdefault(cur, {'size': 0, 'calls': [], 'regcalls': 0,
                                  'imms': [], 'strs': [], 'anchor': [], 'strdist': {}, 'label': None})
        d = info[cur]
        d['size'] += size
        if text.startswith('call r'):
            d['regcalls'] += 1
            continue
        cm = CALL_RE.match(text)
        if cm:
            rel = int(cm.group(1))
            tgt = (((addr + size + rel) & ~1 & 0xFFFFFFFF))
            if BASE <= tgt < hi:
                d['calls'].append(f'{tgt:08x}')
            continue
        # immediates: decimal tokens (incl. negative) anywhere in the text
        for tok in re.findall(r'-?\d+', text):
            v = int(tok)
            if BASE <= v < hi:
                d['imms'].append(v)
                s = str_by_addr.get(v)
                if s:
                    if s not in d['strs']:
                        d['strs'].append(s)
                        d['strdist'][s] = 0
                    if s not in d['anchor']:
                        d['anchor'].append(s)
                    continue
                # inline member of a struct: window +512B (weaker evidence)
                for sv, s2 in str_by_addr.items():
                    if v <= sv < min(v + 512, hi):
                        dist = sv - v
                        if s2 not in d['strdist'] or dist < d['strdist'][s2]:
                            d['strdist'][s2] = dist
                        if s2 not in d['strs']:
                            d['strs'].append(s2)

    calls = {}
    for a, d in info.items():
        d['calls'] = list(dict.fromkeys(d['calls']))
        d['imms'] = list(dict.fromkeys(d['imms']))
        for c in d['calls']:
            calls.setdefault(c, []).append(f'{a:08x}')

    out = {}
    for a, d in info.items():
        key = f'{a:08x}'
        out[key] = {
            'label': d['label'],
            'size': d['size'],
            'calls': d['calls'],
            'callers': calls.get(key, []),
            'regcalls': d['regcalls'],
            'imms': [f'{v:08x}' for v in d['imms'][:40]],
            'strings': d['strs'][:20],
            'strdist': {k: v for k, v in sorted(d['strdist'].items(), key=lambda x: x[1])[:20]},
            'anchors': d['anchor'][:20],
        }
    json.dump(out, open(OUT, 'w', encoding='utf-8'), ensure_ascii=False,
              indent=0)
    nstr = sum(1 for d in out.values() if d['strings'])
    ne = sum(len(d['calls']) for d in out.values())
    print(f'functions: {len(out)}; with strings: {nstr}; call edges: {ne}')
    print('wrote', OUT)


if __name__ == '__main__':
    main()
