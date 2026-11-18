data = open(r"C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin",'rb').read()

def bits(buf):
    out = []
    for b in buf:
        for k in range(7, -1, -1):
            out.append((b >> k) & 1)
    return out

regions = {
    "table9c": (0x9C000, 0x9E000),
    "tables1": (0x5B700, 0x5C200),
    "first-half": (0x206, 0x40000),
    "second-half": (0x50000, 0x90000),
    "header": (0, 0x206),
}
for name, (lo, hi) in regions.items():
    bb = bits(data[lo:hi])
    n = len(bb)
    print(f"--- {name} ({n} bits)")
    for lag in (7, 8, 14, 9, 6):
        m = sum(1 for i in range(n - lag) if bb[i] == bb[i+lag])
        print(f"   lag {lag:2d}: match {m}/{n-lag} = {m/(n-lag):.4f}")
