f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def bits_msb(b):
    return [(x >> (7-j)) & 1 for x in b for j in range(8)]

for lo, hi, name in [(0x206, 0x51000, 'code half'), (0x5C206, 0x9B800, 'mid'), (0x9B800, len(data), 'tail')]:
    bt = bits_msb(data[lo:hi])
    n = len(bt)
    for lag in (1, 7, 14):
        m = sum(1 for i in range(n-lag) if bt[i]==bt[i+lag])
        print(f'{name:10s} lag {lag:2d}: match {m/(n-lag):.4f}')
    print()
