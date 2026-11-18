#!/usr/bin/env python3
# Reconstruct jl_enc LFSR 16-bit states from zero-plaintext runs in MR5 tail.
# ks[i+1] = (state<<1 & 0xFFFF) ^ (0x1021 if state & 0x8000); ct[i] = ks[i] & 0xFF (p=0)
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo, hi = 0x9B800, len(data)
z = data[lo:hi]

def lfsr_next(s):
    return ((s << 1) & 0xFFFF) ^ (0x1021 if s & 0x8000 else 0)

def lfsr_prev(s):
    # inverse of next: bit0 of s came from bit15 shift-in? next = (s<<1)^fb -> s = (next ^ fb)>>1 with fb determined by bit15 of s
    # try both: candidate p = (s >>1); if p & 0x8000: p ^= ... standard: p0 = s >> 1; if lfsr_next(p0) == s: return p0
    # also p1 = (s >> 1) | 0x8000
    for cand in ((s >> 1) & 0xFFFF, ((s >> 1) & 0xFFFF) | 0x8000, ((s >> 1) & 0x7FFF), ((s >> 1) & 0x7FFF) | 0x8000):
        if lfsr_next(cand) == s:
            return cand
    return None

# find runs where consecutive bytes satisfy the zero-ks recurrence:
# y_{i+1} == (2*y_i)&0xFF  or  (2*y_i & 0xFF) ^ 0x21
runs = []
i = 0
n = len(z)
while i < n - 1:
    j = i
    while j < n - 1 and z[j+1] in (((2*z[j]) & 0xFF), ((2*z[j]) & 0xFF) ^ 0x21):
        j += 1
    if j - i >= 6:
        runs.append((i, j - i + 1))
        i = j
    else:
        i += 1
runs.sort(key=lambda t: -t[1])
print('top zero-ks runs (offset_in_tail, len):', [(hex(lo+a), l) for a, l in runs[:10]])

# state reconstruction: enumerate hi candidates at run start, propagate
def reconstruct(seq):
    # seq: consecutive ct bytes where plaintext=0 (assumed)
    cands = set()
    for h in range(256):
        cands.add((h << 8) | seq[0])
    for k in range(1, len(seq)):
        nxt = set()
        for s in cands:
            if (s & 0xFF) != seq[k-1]:
                continue
            ns = lfsr_next(s)
            if (ns & 0xFF) == seq[k]:
                nxt.add(ns)
        cands = nxt
        if not cands:
            return []
    return sorted(cands)

found = []
for a, l in runs[:12]:
    seq = z[a:a+min(l, 24)]
    states = reconstruct(seq)
    print(f'run at {hex(lo+a)} len={l}: states={[(hex(s)) for s in states[:8]]} (of {len(states)})')
    for s in states:
        found.append((lo + a, s))

# cross-check: run LFSR forward from reconstructed state, compare with raw bytes
if found:
    off, s = found[0]
    print('\nverify at', hex(off), 'state', hex(s))
    out = []
    st = s
    for i in range(32):
        out.append(st & 0xFF)
        st = lfsr_next(st)
    print('keystream:', bytes(out).hex(' '))
    print('actual   :', data[off:off+32].hex(' '))
