import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
TAIL = 0x8EFFC
STREAM = 0xc3b4
tail = dec[TAIL:]
o = 0
n = 0
while True:
    p = STREAM + o
    if p + 4 > len(tail):
        break
    tag, ln = struct.unpack_from('<HH', tail, p)
    if ln > len(tail) - p - 4:
        break
    pay = tail[p + 4:p + 4 + ln]
    print(f'tag {tag:2d} len {ln:6d} (0x{ln:04x}) off {o:6d} head: {pay[:32].hex(" ")}')
    o += 4 + ln
    n += 1
print('total records', n, 'end', hex(STREAM + o), 'vs image end 0xaa50c')
