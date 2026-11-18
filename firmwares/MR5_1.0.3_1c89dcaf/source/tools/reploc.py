from collections import defaultdict
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
lo = 0x206
seg = data[lo:0x5C206]
pos = defaultdict(list)
for i in range(len(seg)-8):
    pos[seg[i:i+8]].append(i)
print('repeated 8-grams locations (file offsets, distance):')
for k, v in pos.items():
    if len(v) > 1:
        for a in range(len(v)):
            for b in range(a+1, len(v)):
                print(f'  {hex(lo+v[a])} .. {hex(lo+v[b])} d={v[b]-v[a]} {k.hex()}')
