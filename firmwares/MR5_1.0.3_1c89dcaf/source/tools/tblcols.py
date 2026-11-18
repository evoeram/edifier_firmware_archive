data = open(r"C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin",'rb').read()
T0, R, C = 0x9C000, 256, 32

cols = [[data[T0 + r*C + c] for r in range(R)] for c in range(C)]

print("col : ndistinct : min..max : first 16 values : autocorr best period")
for c in range(C):
    col = cols[c]
    nd = len(set(col))
    mn, mx = min(col), max(col)
    # find best period p in 1..64 with max matches
    bestp, bestm = 0, -1
    for p in range(1, 65):
        m = sum(1 for r in range(R-p) if col[r] == col[r+p])
        if m > bestm: bestm, bestp = m, p
    print(f"{c:2d} : {nd:3d} : {mn:02x}..{mx:02x} : " + ' '.join(f'{v:02x}' for v in col[:16]) + f" : bestp={bestp} match={bestm}/{R-bestp}")
