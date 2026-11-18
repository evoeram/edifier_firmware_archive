import statistics
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo, hi = 0x206, 0x51000  # code-only zone, before table motifs
seg = data[lo:hi]
def xw(d):
    return statistics.mean(bin(x).count('1') for x in d)
def small_frac(d):
    return sum(1 for x in d if x < 32)/len(d)
for lag in (16, 32, 48, 64):
    d = [a ^ b for a, b in zip(seg, seg[lag:])]
    print(f'lag {lag:3d}: meanHW={xw(d):.3f} frac<32={small_frac(d):.4f}')
# null expectation: meanHW ~4, frac<32 ~ 0.125
# also same test on e25HD plaintext code for calibration
e25 = open(r'C:\dev\edifier_firmware_archive\firmwares\e25HD_1.2.0_503d40d0\firmware.bin','rb').read()[0x206:0x8000]
for lag in (16, 32, 48, 64):
    d = [a ^ b for a, b in zip(e25, e25[lag:])]
    print(f'e25HD lag {lag:3d}: meanHW={xw(d):.3f} frac<32={small_frac(d):.4f}')
