from collections import Counter, defaultdict
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
seg = data[0x206:0x5C206]
pos = defaultdict(list)
for i in range(len(seg)-8):
    pos[seg[i:i+8]].append(i)
reps = {k:v for k,v in pos.items() if len(v)>1}
print('distinct 8-grams:', len(pos), 'repeated:', len(reps))
dists = Counter()
occ = 0
for v in reps.values():
    for a in range(len(v)):
        for b in range(a+1, len(v)):
            dists[v[b]-v[a]] += 1; occ += 1
print('repeat pairs:', occ)
m32 = sum(c for d,c in dists.items() if d % 32 == 0)
print('dist %32==0:', m32, '=', round(m32/occ*100,1), '%')
print('top dists:', [(d,c) for d,c in dists.most_common(20)])
# also 4-grams for more stats
pos4 = defaultdict(list)
for i in range(len(seg)-4):
    pos4[seg[i:i+4]].append(i)
reps4 = {k:v for k,v in pos4.items() if len(v)>1}
d4 = Counter(); occ4=0
for v in reps4.values():
    for a in range(len(v)):
        for b in range(a+1,len(v)):
            d4[v[b]-v[a]] += 1; occ4 += 1
m32 = sum(c for d,c in d4.items() if d % 32 == 0)
print('4-gram pairs:', occ4, 'dist%32==0:', round(m32/occ4*100,1), '%')
