data = open(r"C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin",'rb').read()
N = len(data)

# chain density: fraction of adjacent pairs with y == (2*x)&0xFF (mod-256 doubling)
# plus a stricter measure: run-length distribution of chains
blk = 1024
print("block offsets with high doubling density (>=8%):")
runs = []
for start in range(0, N-blk, blk):
    b = data[start:start+blk]
    cnt = sum(1 for i in range(len(b)-1) if b[i+1] == ((b[i]*2) & 0xFF))
    runs.append((start, cnt/(len(b)-1)))

import statistics
vals = [r[1] for r in runs]
print(f"mean={statistics.mean(vals):.4f} max={max(vals):.3f} min={min(vals):.3f}")
hi = [(hex(s), f"{v:.2f}") for s, v in runs if v > 0.10]
print("blocks >10%:", hi[:80])
print("count:", len(hi))

# chain run-length histogram (whole file)
from collections import Counter
hist = Counter()
cur = 0
for i in range(N-1):
    if data[i+1] == ((data[i]*2) & 0xFF):
        cur += 1
    else:
        if cur: hist[cur] += 1
        cur = 0
print("chain run-length histogram:", sorted(hist.items())[:12], "... total runs:", sum(hist.values()))
