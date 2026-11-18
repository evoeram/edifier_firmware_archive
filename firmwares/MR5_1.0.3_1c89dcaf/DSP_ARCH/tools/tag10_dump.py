import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
TAIL = 0x8EFFC
STREAM = 0xc3b4
tail = dec[TAIL:]

# extract tag 10
o = 0
while True:
    p = STREAM + o
    if p + 4 > len(tail):
        break
    tag, ln = struct.unpack_from('<HH', tail, p)
    if ln > len(tail) - p - 4:
        break
    if tag == 10:
        t10 = tail[p + 4:p + 4 + ln]
        break
    o += 4 + ln

print('len', len(t10))
# hexdump with offsets
for i in range(0, len(t10), 16):
    chunk = t10[i:i+16]
    print(f'{i:04x}: {chunk.hex(" ")}')
