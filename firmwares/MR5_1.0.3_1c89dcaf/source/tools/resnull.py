import random
from collections import Counter
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def resid_hists(seg, P=32):
    hists = [Counter() for _ in range(P)]
    for i, b in enumerate(seg):
        hists[i % P][b] += 1
    return hists

def xor_align_frac(h1, h2):
    top1 = [x for x,_ in h1.most_common(24)]
    best = -1
    for d in range(256):
        s = sum(h1[x] * h2[x ^ d] for x in top1)
        best = max(best, s)
    return best / sum(h1.values())

def test(seg, label):
    H = resid_hists(seg)
    fr = [xor_align_frac(H[0], H[r]) for r in range(1,32)]
    print(label, 'mean', round(sum(fr)/len(fr),3), 'max', round(max(fr),3), 'top5:', [round(x,2) for x in sorted(fr, reverse=True)[:5]])

first = data[0x206:0x5C206]
test(first, 'MR5 first half   ')
sh = list(first); random.Random(1).shuffle(sh); test(bytes(sh), 'shuffled (null)  ')
e25 = open(r'C:\dev\edifier_firmware_archive\firmwares\e25HD_1.2.0_503d40d0\firmware.bin','rb').read()[0x206:0x5C206]
test(e25, 'e25HD (8051 ctl) ')
