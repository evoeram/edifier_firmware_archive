import re
f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
offs = [m.start() for m in re.finditer(re.escape(b'\xb5\x4b\xb6'), data)]
print('total', len(offs))
# find consecutive runs with spacing 64
groups = []
cur = [offs[0]]
for o in offs[1:]:
    if o - cur[-1] == 64: cur.append(o)
    else: groups.append(cur); cur=[o]
groups.append(cur)
gl = [(g[0], len(g)) for g in groups]
gl.sort(key=lambda t:-t[1])
print('largest 64-spaced groups:', [(hex(a), n) for a,n in gl[:10]])

start = gl[0][0]
print('=== dump 64-byte records from', hex(start))
for i in range(start, min(start+64*12, len(data)), 64):
    row = data[i:i+64]
    print(f'{i:06x} ', row.hex(' '))
