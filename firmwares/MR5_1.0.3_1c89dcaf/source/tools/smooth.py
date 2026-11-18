f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def show(off, n, w=32):
    print('===', hex(off))
    for i in range(off, off+n, w):
        row = list(data[i:i+w])
        print(f'{i:06x} ', ' '.join(f'{v:3d}' for v in row))

show(0x9C000, 6*32)
show(0xA0000, 4*32)
# smoothness metrics over tail: mean |first diff| and |second diff| vs random expectation
import random
lo, hi = 0x9B800, len(data)
z = data[lo:hi]
d1 = [abs(z[i+1]-z[i]) for i in range(len(z)-1)]
d2 = [abs((z[i+2]-z[i+1])-(z[i+1]-z[i])) & 0xFF for i in range(len(z)-2)]
d2a = [abs(((z[i+2]-z[i+1])&0xFF) - 128) for i in range(len(z)-2)]
import statistics
print('mean|d1| =', round(statistics.mean(d1),2), ' (random ~85)')
print('mean|d2-128| =', round(statistics.mean(d2a),2))
# fraction of triples where diff magnitude decreases (smooth)
