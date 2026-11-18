import json
import io

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
BASE = 0x06000100

# string pool around the command strings used by f_tst_btn_sta (base 0x6061d17)
start = 0x6061d17 - BASE - 0x60
seg = dec[start:start + 0x200]
print('pool dump:')
i = 0
while i < len(seg):
    j = seg.find(b'\0', i)
    if j < 0:
        break
    s = seg[i:j]
    if len(s) >= 3:
        va = BASE + start + i
        print(f'  VA {va:08x} (base{va-0x6061d17:+#x}) {s.decode("ascii","replace")}')
    i = j + 1

# who references 'Media' string (f_eq_media?)
fs = json.load(io.open(SRC + r'\disasm\function_strings.json', encoding='utf-8'))
for fname, strs in fs.items():
    vals = list(strs.values()) if isinstance(strs, dict) else strs
    hits = [s for s in vals if s in ('Media', 'ring', 'DUT+TST+VER+GET+')]
    if hits:
        print('FUNC', fname, '->', hits)
