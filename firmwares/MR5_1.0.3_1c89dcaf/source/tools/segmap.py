#!/usr/bin/env python3
# Map ks-valid segments in MR5 tail: propagate reconstructed states, find reseed points.
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo, hi = 0x9B800, len(data)
z = data[lo:]
n = len(z)

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

# all runs >= 8
runs = []
i = 0
while i < n - 1:
    j = i
    while j < n-1 and z[j+1] in (((2*z[j]) & 0xFF), ((2*z[j]) & 0xFF) ^ 0x21):
        j += 1
    if j - i >= 8:
        runs.append((i, j - i + 1))
        i = j
    else:
        i += 1

# reconstruct states for runs
states = {}
for a, l in runs:
    seq = z[a:a+min(l, 24)]
    st = reconstruct_end(seq)
    if len(st) == 1:
        s = st[0]
        for _ in range(len(seq)-1):
            s = lfsr_prev(s)
        states[a] = s
print('runs:', len(runs), 'with unique state:', len(states))

# for each state, propagate forward while ct == ks (pt==0) OR pt nonzero (unknown); 
# validity test: ks continues to explain ZERO runs: propagate and check where the next run's start disagrees
# Simpler: for consecutive runs (sorted by offset), check ks-consistency between them
run_list = sorted(states.items())
breaks = []
for idx in range(len(run_list)-1):
    a1, s1 = run_list[idx]
    a2, s2 = run_list[idx+1]
    # propagate s1 forward to a2, compare with s2
    d = a2 - a1
    if d > 65536*2: continue
    s = s1
    for _ in range(d):
        s = lfsr_next(s)
    if s != s2:
        breaks.append((a1, a2, d))
print('inconsistent consecutive pairs:', len(breaks), 'of', len(run_list)-1)
offs2 = [b[1] + lo for b in breaks]
print('break offsets (file):', [hex(o) for o in offs2[:40]])
print('break mod 32:', sorted(set(o % 32 for o in offs2)))
print('break deltas:', [offs2[i+1]-offs2[i] for i in range(min(30, len(offs2)-1))])
