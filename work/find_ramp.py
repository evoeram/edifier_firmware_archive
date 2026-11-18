import re
d = open(r'firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\app.bin', 'rb').read()
print('app.bin size', len(d))
for pat in [b'wdrc', b'aeq', b'DyEq', b'Gain4', b'EnergyDet', b'volume', b'NOCP',
            b'MusicDrc', b'VBass', b'smart_voice', b'resample']:
    for m in re.finditer(re.escape(pat), d):
        print(f'{pat.decode():12s} @ 0x{m.start():06x}  ctx: {d[m.start()-24:m.start()+24]!r}')

# the descending ramp table
m = re.search(rb'[\x7e]{20,}', d)
if m:
    s = m.start()
    # find full run of >= 0x60 bytes
    a = s
    while a > 0 and 0x20 <= d[a-1] <= 0x7f:
        a -= 1
    b = s
    while b < len(d) and 0x20 <= d[b] <= 0x7f:
        b += 1
    print(f'\nramp table @ 0x{a:06x}..0x{b:06x} len {b-a}')
    print('bytes:', d[a:a+96].hex(' '))
    print('min/max byte:', min(d[a:b]), max(d[a:b]))
    # what's before/after
    print('before:', d[a-64:a].hex(' '))
    print('after :', d[b:b+64].hex(' '))
