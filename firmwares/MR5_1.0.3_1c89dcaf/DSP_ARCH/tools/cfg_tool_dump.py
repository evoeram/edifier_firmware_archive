import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()

# cfg_tool.bin: record @0x9831e, size 0xea
rec = 0x9831e
size = 0xea
hdr = dec[rec:rec + 16]
name = dec[rec + 16:rec + 32].split(b'\0')[0]
data = dec[rec + 32:rec + size]
print('cfg_tool.bin: id=%08x hdr=%d size=%d attr=%x name=%s'
      % (struct.unpack_from('<I', hdr)[0], struct.unpack_from('<I', hdr, 4)[0],
         struct.unpack_from('<I', hdr, 8)[0], struct.unpack_from('<I', hdr, 12)[0], name.decode()))
print('data hex:')
print(data.hex(' '))
print('data ascii-ish:')
print(''.join(chr(b) if 32 <= b < 127 else '.' for b in data))

# gap region between app end and first file record
gap = dec[0x8eefc:0x9831e]
ff = gap.count(0xff)
print()
print('gap 0x8eefc..0x9831e: len=%d, 0xff bytes=%d (%.1f%%)'
      % (len(gap), ff, 100 * ff / len(gap)))
nonff = [(i, gap[i:i + 16].hex(' ')) for i in range(0, len(gap) - 16, 16)
         if gap[i:i + 16] != b'\xff' * 16]
print('non-0xff 16B blocks in gap:', len(nonff))
for i, h in nonff[:12]:
    print(f'  {0x8eefc+i:06x}: {h}')

# what's before 0x9831e - the aa aa marker
print()
print('bytes 0x98300..0x9831e:', dec[0x98300:0x9831e].hex(' '))
