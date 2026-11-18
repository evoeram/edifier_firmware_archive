#!/usr/bin/env python3
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
    if j - i >= 10:
        runs.append((i, j - i + 1))
        i = j
    else:
        i += 1
runs.sort(key=lambda t: -t[1])

for a, l in runs[:6]:
    seq = z[a:a+min(l, 24)]
    states = reconstruct_end(seq)
    if not states:
        print(f'run {hex(lo+a)} len={l}: no state'); continue
    s_end = states[0]
    s = s_end
    for _ in range(len(seq)-1):
        s = lfsr_prev(s)
    # s = state at run start (lo byte == z[a]); roll back 16 more
    s16 = s
    ok = True
    for _ in range(16):
        s16 = lfsr_prev(s16)
        if s16 is None: ok = False; break
    if not ok:
        print(f'run {hex(lo+a)}: rollback failed'); continue
    ks = []
    st = s16
    for _ in range(64):
        ks.append(st & 0xFF); st = lfsr_next(st)
    ks = bytes(ks)
    seg = data[lo+a-16:lo+a+48]
    pt = bytes(c ^ k for c, k in zip(seg, ks))
    print(f'run {hex(lo+a)} len={l}')
    print('  pt:', pt.hex(' '))
