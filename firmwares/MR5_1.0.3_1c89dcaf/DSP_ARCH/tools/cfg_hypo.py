import re
import struct
import io

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
img = open(SRC + r'\decrypted\app_bin_full.bin', 'rb').read()
print('app image size:', len(img), hex(len(img)))
print('full dec size:', len(dec), hex(len(dec)))

TAIL = 0x8EFFC
# 1) header of the TLV volume
hdr_off = TAIL + 0xc394
data_off = TAIL + 0xc3b4
hdr = dec[hdr_off:hdr_off + 16]
print('hdr @', hex(hdr_off), ':', hdr.hex(' '))
vals = struct.unpack('<4H', hdr[:8]) + struct.unpack('<8B', hdr[8:16])
print('as u16x4+u8x8:', vals)
u32 = struct.unpack('<4I', hdr)
print('as u32x4:', [hex(v) for v in u32])

# 2) does the TLV volume end exactly at image end?
o = data_off
total = 0
n = 0
while True:
    if o + 4 > len(dec):
        break
    tag, ln = struct.unpack_from('<HH', dec, o)
    if ln > len(dec) - o - 4:
        break
    total += 4 + ln
    o += 4 + ln
    n += 1
print('TLV: records=%d, bytes=%d (0x%x), volume end=%s (0x%x), image end=%s (0x%x)'
      % (n, total, total, o >= len(img), o, len(img) >= len(img), len(img)))
print('data_off + total =', hex(data_off + total), ' len(img) =', hex(len(img)))

# 3) strings in the whole image mentioning res files
pat = re.compile(rb'[\x20-\x7e]{4,64}')
kw = ('effect_cfg', 'cfg_tool', 'p11', 'res/', 'flash/res', '.bin', 'cfg.db', 'stream.bin')
hits = {}
for m in pat.finditer(dec):
    s = m.group().decode('ascii')
    ls = s.lower()
    if any(k in ls for k in kw) and len(s) < 60:
        hits.setdefault(s, m.start())
for s, off in sorted(hits.items(), key=lambda x: x[1]):
    print(f'{off:08x}  {s!r}')
