from collections import Counter
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def resid_hists(seg, P=32):
    hists = [Counter() for _ in range(P)]
    for i, b in enumerate(seg):
        hists[i % P][b] += 1
    return hists

def xor_align(h1, h2):
    # find d maximizing sum h2[x^d] matched to h1[x], on top values
    best = (0, -1)
    top1 = [x for x,_ in h1.most_common(24)]
    for d in range(256):
        s = sum(h1[x] * h2[x ^ d] for x in top1)
        if s > best[1]: best = (d, s)
    return best

for name, lo, hi in [('first half', 0x206, 0x5C206), ('mid', 0x5C206, 0x9B800), ('tail', 0x9B800, len(data))]:
    seg = data[lo:hi]
    H = resid_hists(seg)
    # baseline check: same-length segments offset by 16 (misaligned control)
    print('===', name, 'len', len(seg))
    modes = [h.most_common(1)[0][0] for h in H]
    print('modes per residue:', ' '.join(f'{m:02x}' for m in modes))
    # XOR alignment quality between residue 0 and others
    tot = sum(c.most_common(1)[0][1] for c in H)
    al = []
    for r in range(1, 32):
        d, s = xor_align(H[0], H[r])
        frac = s / (H[0].total_count() if hasattr(H[0],'total_count') else sum(H[0].values()))
        al.append((r, d, round(frac,2)))
    print('align r0<->r (r, xor-d, frac):', al[:16])
    print('                               ', al[16:])
