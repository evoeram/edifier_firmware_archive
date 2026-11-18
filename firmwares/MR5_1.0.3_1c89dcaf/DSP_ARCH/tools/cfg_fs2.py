import struct
import re

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()

MAGIC = struct.pack('<I', 0x4c689141)
print('=== occurrences of VFS magic 4C689141:')
start = 0
while True:
    p = dec.find(MAGIC, start)
    if p < 0:
        break
    hdr = dec[p:p + 32]
    if len(hdr) == 32:
        hsz, size, attr = struct.unpack_from('<III', hdr, 4)
        name = hdr[16:32].split(b'\0')[0].decode('ascii', 'replace')
        print(f'  @ {p:06x}: hdr={hsz:#x} size={size:#x}({size}) attr={attr:#x} name={name!r}')
    start = p + 1

print()
print('=== any ".bin"-named records: context scan in tail region 0x8eefc..EOF:')
pat = re.compile(rb'[a-zA-Z0-9_]{1,20}\.bin')
start = 0x8eefc
for m in pat.finditer(dec, start):
    p = m.start()
    pre = dec[max(0, p - 16):p]
    print(f'  @ {p:06x}: {m.group().decode():24s} pre={pre.hex(" ")}')
