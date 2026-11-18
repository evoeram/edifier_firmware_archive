f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def bits_msb(b):
    return [(x >> (7-j)) & 1 for x in b for j in range(8)]

def bits_lsb(b):
    return [(x >> j) & 1 for x in b for j in range(8)]

def syms(bits, w, start=0, n=200):
    return [int(''.join(map(str,bits[start+i*w:start+(i+1)*w])), 2) for i in range(n)]

lo, hi = 0x9B800, len(data)
zone = data[lo:hi]

for order, fb in (('MSB', bits_msb), ('LSB', bits_lsb)):
    bt = fb(zone)
    for w in (7,):
        s = syms(bt, w, 0, 64)
        print(f'--- {order} w={w} first64:', s)
        # symbol histogram
        allsyms = syms(bt, w, 0, (len(bt)//w)-1)
        from collections import Counter
        c = Counter(allsyms)
        print('   top10:', c.most_common(10), 'distinct', len(c))
        # run-lengths of constant symbols
        runs, cur, ln = [], allsyms[0], 1
        for v in allsyms[1:]:
            if v == cur: ln += 1
            else: runs.append((cur, ln)); cur, ln = v, 1
        runs.append((cur, ln))
        rl = [r[1] for r in runs]
        rl.sort(reverse=True)
        print('   runs:', len(runs), 'maxrun', rl[0], 'top runs:', rl[:15])
