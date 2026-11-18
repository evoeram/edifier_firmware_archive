import re, struct

APP = r'firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\app.bin'
d = open(APP, 'rb').read()
BASE = 0x06000100

# addresses of interest
targets = {
    0x05fb5d: 'Vol_FileMusic',
    0x05fb91: 'Vol_MicMusic',
    0x05fbab: 'Vol_SysKTone',
    0x061da7: 'volume',
    0x061c9c: 'DyEq cluster',
    0x061e9b: 'MusicDrc',
    0x061eff: 'EnergyDet/Drc*Media',
    0x05fd84: 'wdrc',
    0x05fd92: 'gain',
    0x05fda9: 'energy_detect',
    0x05fdd6: 'data_saturation',
    0x060ff0: 'ramp table',
}
for pat in [b'tone_zh/vol_max', b'tone_zh/key_tone', b'tone_zh/normal', b'MIXER7', b'Cross', b'VBass']:
    m = re.search(re.escape(pat), d)
    if m:
        targets[m.start()] = pat.decode()

mov32 = {}
# raw scan: C0-CF FF <imm32>
for m in re.finditer(rb'[\xc0-\xcf]\xff(....)', d):
    imm = struct.unpack('<I', m.group(1))[0]
    if BASE <= imm < BASE + len(d):
        mov32.setdefault(imm, []).append(m.start())

for off, name in sorted(targets.items()):
    addr = BASE + off
    refs = mov32.get(addr, [])
    print(f'{name:20s} 0x{addr:08x}: {len(refs)} refs @ ' +
          ', '.join(f'0x{BASE+r:08x}' for r in refs[:12]))
