import re
d = open(r'firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\app.bin', 'rb').read()

# 1) plugin name pool around 0x5fc00..0x60300
def dump_strings(a, b):
    seg = d[a:b]
    for m in re.finditer(rb'[\x20-\x7e]{3,}', seg):
        print(f'  0x{a+m.start():06x}: {m.group().decode()!r}')

print('---- node-type name pool (0x5fb00..0x60100) ----')
dump_strings(0x5fb00, 0x60100)

# 2) ramp table full extent: values 0x00..0x7f
a = 0x06105e
lo = a
while lo > 0 and d[lo-1] <= 0x7f:
    lo -= 1
hi = a
while hi < len(d) and d[hi] <= 0x7f:
    hi += 1
print(f'\n---- ramp table full 0x{lo:06x}..0x{hi:06x} len {hi-lo} ----')
tb = d[lo:hi]
vals = list(tb)
print('min', min(vals), 'max', max(vals), 'first', vals[:8], 'last', vals[-8:])
# shape: unique transitions
trans = []
prev = None
for i, v in enumerate(vals):
    if v != prev:
        trans.append((i, v))
        prev = v
print('transitions (first 40):', trans[:40])
print('total unique values:', len(set(vals)))
# reconstruct curve (unique values in order)
uniq = []
for v in vals:
    if not uniq or uniq[-1] != v:
        uniq.append(v)
print('curve:', uniq)
