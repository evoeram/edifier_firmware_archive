import struct

data = open(r"C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin",'rb').read()
body = data[0x206:]

def lfsr_stream(key, n, poly=0x1021, msb=True, step_first=False, high=False):
    out = bytearray()
    k = key
    for _ in range(n):
        if not step_first:
            out.append((k >> 8) & 0xFF if high else k & 0xFF)
        if msb:
            fb = (k >> 15) & 1
            k = ((k << 1) & 0xFFFF) ^ (poly if fb else 0)
        else:
            fb = k & 1
            k = (k >> 1) ^ (poly if fb else 0)  # poly 0x8408 expected
        if step_first:
            out.append((k >> 8) & 0xFF if high else k & 0xFF)
    return bytes(out)

cands = []
for poly, msb in [(0x1021, True), (0x8408, False)]:
    for step_first in (False, True):
        for high in (False, True):
            for key in range(0x10000):
                ks = lfsr_stream(key, 16, poly, msb, step_first, high)
                dec = bytes(a ^ b for a, b in zip(body[:14], ks))
                bank_id, size, load, bank_off, crc = struct.unpack("<HHIIH", dec)
                if 1 <= bank_id <= 64 and 0 < size <= 0x40000 and bank_off <= 0x20000 and load <= 0x03000000:
                    cands.append((hex(key), poly, msb, step_first, high, hex(bank_id), hex(size), hex(load), hex(bank_off), hex(crc)))
for c in cands[:60]:
    print(c)
print("total", len(cands))
