import re
from collections import Counter

f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo, hi = 0x9B800, len(data)
z = data[lo:hi]

# maximal doubling runs (b[i+1] == 2*b[i] & 0xFF), exclude trivial pairs 00->00, 80->00, ff->fe
runs = []
i = 1
while i < len(z):
    j = i
    while j < len(z)-1 and z[j+1] == (z[j]*2) & 0xFF and not (z[j] in (0x00, 0x80) or (z[j]==0xff and z[j+1]==0xfe)):
        j += 1
    L = j - i
    if L >= 2:
        runs.append((i, L, z[i-1], z[i:i+L+1].hex()))
        i = j+1
    else:
        i += 1
print('runs>=3:', len(runs))
lens = Counter(r[1] for r in runs)
print('len dist:', sorted(lens.items()))
mod32 = Counter(r[0] % 32 for r in runs)
print('start mod32:', sorted(mod32.items()))
print('start mod8:', sorted(Counter(r[0] % 8 for r in runs).items()))
# show 15 sample runs
for r in runs[:15]:
    print(hex(lo+r[0]), 'len', r[1], 'prev', hex(r[2]), r[3])

# kernel occurrences
for pat in (b'\xc1\x82\x25\x4a', b'\xb5\x4b\xb6', b'\x96\x0d', b'\x63\xc6', b'\x2d\x5a\xb4'):
    offs = [m.start() for m in re.finditer(re.escape(pat), data)]
    print(pat.hex(), 'count', len(offs), 'mod2048:', Counter(o % 2048 for o in offs).most_common(6), 'in-file first/last:', hex(offs[0]) if offs else '-', hex(offs[-1]) if offs else '-')
