import os
base = r"C:\dev\edifier_firmware_archive\firmwares"
a = open(os.path.join(base, "MR4.5_1.0.1_fb09ee14", "firmware.bin"), 'rb').read()
b = open(os.path.join(base, "MR4_MKII_1.0.1_d5acc167", "firmware.bin"), 'rb').read()
print("sizes:", len(a), len(b))

diffs = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
print("num diffs:", len(diffs))
print("diff offsets:", [hex(i) for i in diffs])

# context around each diff cluster
clusters = []
cur = [diffs[0]]
for i in diffs[1:]:
    if i - cur[-1] <= 8:
        cur.append(i)
    else:
        clusters.append(cur)
        cur = [i]
clusters.append(cur)
for cl in clusters:
    lo = max(0, cl[0]-24); hi = min(len(a), cl[-1]+25)
    print(f"\n=== cluster {hex(cl[0])}..{hex(cl[-1])} ===")
    print("A:", ' '.join(f'{x:02x}' for x in a[lo:hi]))
    print("B:", ' '.join(f'{x:02x}' for x in b[lo:hi]))
    print("X:", ' '.join(f'{x^y:02x}' for x, y in zip(a[lo:hi], b[lo:hi])))
