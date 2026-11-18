f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()

def dump(off, n, label):
    print('====', label, hex(off))
    for i in range(off, off+n, 32):
        row = data[i:i+32]
        print(f'{i:06x}  {row.hex(" ")}')

dump(0x9B800, 128, 'tail start')
dump(0x9C000+32*0, 64, 'table 0x9C000 rows0-1')
dump(0x9C800, 128, '0x9C800')
dump(0x9E000, 128, '0x9E000')
dump(0xA0000, 128, '0xA0000')
dump(0xA4000, 128, '0xA4000')
dump(0xAA400, 128, 'near end 0xAA400')
dump(0xAA50C, 128, 'after tail zone')
dump(0x5C206, 128, 'zone boundary 0x5C206')
dump(0x60043, 64, 'model field ctx 0x60043')
