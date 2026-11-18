from collections import Counter
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def bitruns(chunk, order='msb'):
    bits = []
    for x in chunk:
        if order=='msb': bits += [(x>>(7-j))&1 for j in range(8)]
        else: bits += [(x>>j)&1 for j in range(8)]
    runs=[]; cur=bits[0]; ln=1
    for b in bits[1:]:
        if b==cur: ln+=1
        else: runs.append((cur,ln)); cur=b; ln=1
    runs.append((cur,ln))
    return runs

for off in (0x9C000, 0xA0000, 0x97000, 0x40000):
    z = data[off:off+8192]
    for order in ('msb','lsb'):
        r = bitruns(z, order)
        L = Counter(l for _,l in r)
        ones = sum(l for v,l in r if v==1); zeros = sum(l for v,l in r if v==0)
        tot = ones+zeros
        print(hex(off), order, 'bit1 frac', round(ones/tot,3),
              'runlens top:', L.most_common(8), 'runs/tot', round(len(r)/tot,3))
