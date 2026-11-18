#!/usr/bin/env python3
from collections import Counter
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo = 0x9B800
z = data[lo:]

def lfsr_next(s):
    return ((s << 1) & 0xFFFF) ^ (0x1021 if s & 0x8000 else 0)

def lfsr_prev(s):
    for cand in ((s >> 1) & 0xFFFF, ((s >> 1) & 0xFFFF) | 0x8000,
                 ((s ^ 0x1021) >> 1) & 0xFFFF, (((s ^ 0x1021) >> 1) & 0xFFFF) | 0x8000):
        if lfsr_next(cand) == s:
            return cand
    return None

def reconstruct_end(seq):
    cands = set((h << 8) | seq[0] for h in range(256))
    for k in range(1, len(seq)):
        nxt = set()
        for s in cands:
            ns = lfsr_next(s)
            if (ns & 0xFF) == seq[k]:
                nxt.add(ns)
        cands = nxt
        if not cands:
            return []
    return sorted(cands)

runs = []
i = 0
n = len(z)
while i < n - 1:
    j = i
    while j < n-1 and z[j+1] in (((2*z[j]) & 0xFF), ((2*z[j]) & 0xFF) ^ 0x21):
        j += 1
    if j - i >= 8:
        runs.append((i, j - i + 1)); i = j
    else:
        i += 1

states = {}
for a, l in runs:
    seq = z[a:a+min(l, 24)]
    st = reconstruct_end(seq)
    if len(st) == 1:
        s = st[0]
        for _ in range(len(seq)-1):
            s = lfsr_prev(s)
        states[a] = s

results = []
for r in range(32):
    # block starts at offsets ≡ r (mod 32)
    seeds = []  # (block_start, seed)
    for a, s in states.items():
        o = lo + a
        bs = o - ((o - r) % 32)
        t = o - bs
        seed = s
        for _ in range(t):
            seed = lfsr_prev(seed)
        seeds.append((bs, seed))
    # scan m: B = r + 32*m ; a = (bs - B)/4 = (bs - r)/4 - 8m
    for m in range(0, 22000):
        Ks = Counter()
        nvalid = 0
        for bs, seed in seeds:
            a = (bs - r)//4 - 8*m
            if a < 0:
                continue
            nvalid += 1
            Ks[(seed ^ (a & 0xFFFF)) & 0xFFFF] += 1
        if nvalid < 5:
            continue
        k, cnt = Ks.most_common(1)[0]
        if cnt >= max(3, nvalid//2):
            results.append((cnt, nvalid, r, m, k))
results.sort(reverse=True)
print('top: (consistent, total, r, m, K)')
for x in results[:10]:
    print(x)
