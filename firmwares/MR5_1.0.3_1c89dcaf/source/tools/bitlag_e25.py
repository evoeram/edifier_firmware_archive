f = r'C:\dev\edifier_firmware_archive\firmwares\e25HD_1.2.0_503d40d0\firmware.bin'
data = open(f,'rb').read()
def bits_msb(b):
    return [(x >> (7-j)) & 1 for x in b for j in range(8)]
bt = bits_msb(data[0x206:0x8000])
n = len(bt)
for lag in (1, 7, 14):
    m = sum(1 for i in range(n-lag) if bt[i]==bt[i+lag])
    print(f'e25HD code lag {lag}: match {m/(n-lag):.4f}')
