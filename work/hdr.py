import sys
d = open(r'decrypted\MR5_1.0.3_1c89dcaf_dec.bin', 'rb').read()
for off in range(0, int(sys.argv[1]) if len(sys.argv) > 1 else 0x200, 16):
    row = d[off:off+16]
    hexs = ' '.join(f'{c:02x}' for c in row)
    asc = ''.join(chr(c) if 32 <= c < 127 else '.' for c in row)
    print(f'{off:06x}  {hexs:<48}  {asc}')
