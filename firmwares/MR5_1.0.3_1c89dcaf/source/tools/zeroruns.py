from collections import Counter
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo, hi = 0x9B800, len(data)
z = data[lo:hi]
c = Counter(z)
print('top20:', c.most_common(20))
print('zero count:', c[0], 'of', len(z))
# zero run lengths and alignment
runs = []
i = 0
while i < len(z):
    if z[i] == 0:
        j = i
        while j < len(z) and z[j]==0: j += 1
        runs.append((i, j-i)); i = j
    else: i += 1
L = Counter(r[1] for r in runs)
print('zero-run len dist:', sorted(L.items())[:15], 'total runs', len(runs))
print('zero-run start mod8:', sorted(Counter(r[0]%8 for r in runs).items()))
print('zero-run start mod32:', sorted(Counter(r[0]%32 for r in runs).items()))
# doubling-pair alignment already known; check pair (x,2x) start mod8 within doubling pairs of len>=1
dp = [(i, z[i]) for i in range(len(z)-1) if z[i+1]==(2*z[i])&0xFF and z[i] not in (0,0x80,0xff)]
print('doubling pair count:', len(dp), 'of', len(z)-1)
print('pair start byte val top:', Counter(v for _,v in dp).most_common(10))
