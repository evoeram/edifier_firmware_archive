import struct
import json
import io
import re

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
BASE = 0x06000100

b42 = json.load(io.open(SRC + r'\disasm\b42_funcs.json', encoding='utf-8'))
for want in ('f_eq_media', 'dut_tst_cluster', 'f_iis0_rx2', 'f_sha_256', 'mcu_msg_send'):
    hits = [k for k, v in b42.items() if v.get('name') == want]
    print(want, '->', hits)

# locate DUT strings
for pat in (b'DUT+TST+TXS+0', b'TST+DUT+SAV+', b'TST+LED+IO1+1', b'DUT+TST+DUT+0', b'DUT+TST+TXS+1'):
    p = dec.find(pat)
    print(pat, 'at dec', hex(p), 'VA', hex(BASE + p) if p >= 0 else '-')

# raw pointer refs to those VAs in code area (app_bin_full.bin = dec[0:0x8eefc] @ VA BASE+off)
code = dec[:0x8eefc]
for pat in (b'DUT+TST+TXS+0', b'TST+DUT+SAV+', b'TST+LED+IO1+1', b'DUT+TST+DUT+0'):
    p = dec.find(pat)
    if p < 0:
        continue
    va = BASE + p
    b = struct.pack('<I', va)
    start = 0
    sites = []
    while True:
        q = code.find(b, start)
        if q < 0:
            break
        sites.append(BASE + q)
        start = q + 1
    # also scan for VA-1..VA+15 (string might be referenced mid)
    print(pat.decode(), 'VA', hex(va), 'refs:', [hex(s) for s in sites])

# neighbors of the DUT strings (string pool dump)
p = dec.find(b'DUT+TST+TXS+0')
seg = dec[p - 0x80:p + 0x120]
print('\nstring pool around:')
for i in range(0, len(seg), 32):
    chunk = seg[i:i + 32]
    asc = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
    print(f'{p-0x80+i:06x}: {asc}')
