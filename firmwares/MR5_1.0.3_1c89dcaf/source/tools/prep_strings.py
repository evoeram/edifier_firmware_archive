import re
import json
import os

BASE = 0x06000100
HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
APP = os.path.join(SRC, 'decrypted', 'app_bin_full.bin')
LST = os.path.join(SRC, 'disasm', 'mr5_app_disasm.txt')
OUT = os.path.join(SRC, 'disasm', 'strings_for_ghidra.json')

LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')


def extract_strings(data, minlen=4):
    out = {}
    start = None
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7f:
            if start is None:
                start = i
        else:
            if start is not None and i - start >= minlen:
                out[start] = (i - start, data[start:i].decode('ascii', 'replace'))
            start = None
    if start is not None and len(data) - start >= minlen:
        out[start] = (len(data) - start, data[start:].decode('ascii', 'replace'))
    return out


data = open(APP, 'rb').read()
strings = extract_strings(data)
print('strings found:', len(strings))

# instruction coverage from the listing (offsets relative to file start = addr - BASE)
ins_ranges = []
for raw in open(LST, encoding='utf-8', errors='replace'):
    m = LINE_RE.match(raw.rstrip())
    if m:
        off = int(m.group(1), 16) - BASE
        size = len(m.group(2).split())
        ins_ranges.append((off, off + size))

ins_ranges.sort()
merged = []
for a, b in ins_ranges:
    if merged and a <= merged[-1][1]:
        merged[-1][1] = max(merged[-1][1], b)
    else:
        merged.append([a, b])


def in_ins(off):
    import bisect
    i = bisect.bisect_right(merged, [off, 1 << 30]) - 1
    return i >= 0 and merged[i][0] <= off < merged[i][1]


free, overlap = [], 0
for off, (ln, text) in strings.items():
    if in_ins(off) or in_ins(off + ln - 1):
        overlap += 1
    else:
        free.append({'addr': BASE + off, 'len': ln, 'text': text})

print('overlapping instructions:', overlap, '-> skipped')
print('free strings:', len(free))
json.dump(free, open(OUT, 'w', encoding='utf-8'), ensure_ascii=False)
print('wrote', OUT)
