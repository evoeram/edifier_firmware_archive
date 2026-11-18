import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
dec = open(SRC + r'\decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()

def hexdump(off, n, label=''):
    print(f'--- {label} @ {off:06x}')
    for i in range(0, n, 16):
        chunk = dec[off + i:off + i + 16]
        if not chunk:
            break
        hexs = ' '.join(f'{b:02x}' for b in chunk)
        asc = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
        print(f'{off+i:06x}: {hexs:<47s}  {asc}')

hexdump(0x98310, 0x60, 'cfg_tool.bin record zone')
hexdump(0x98400, 0x40, 'p11_code.bin record zone')
# check candidate data areas
hexdump(0x98438, 0x40, 'after p11 name')
hexdump(0x9b3b0, 0x20, 'stream.bin data start (TLV tag0 begins)')
