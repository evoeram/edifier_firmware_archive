import os, itertools
base = r"C:\dev\edifier_firmware_archive\firmwares"
files = {}
for d in sorted(os.listdir(base)):
    p = os.path.join(base, d, "firmware.bin")
    if os.path.exists(p):
        files[d.split('_')[0]] = open(p, 'rb').read()

names = list(files)
hdrs = {n: files[n][:0x206] for n in names}
print("models:", names)
print()

# per-byte: which models differ from the majority
N = 0x206
print("byte offset : set of distinct values (count) across 12 models")
groups = []
for off in range(N):
    vals = [hdrs[n][off] for n in names]
    distinct = set(vals)
    if len(distinct) == 1:
        groups.append(('C', off, vals[0]))
    else:
        groups.append(('V', off, tuple(sorted(set(vals)))))

# summarize constant ranges
i = 0
while i < N:
    if groups[i][0] == 'C':
        j = i
        while j < N and groups[j][0] == 'C': j += 1
        if j - i >= 2:
            print(f"CONST 0x{i:03x}..0x{j-1:03x} ({j-i} B): " + ' '.join(f'{groups[k][2]:02x}' for k in range(i, min(j, i+24))) + (" ..." if j-i > 24 else ""))
        i = j
    else:
        j = i
        while j < N and groups[j][0] == 'V': j += 1
        print(f"VARIES 0x{i:03x}..0x{j-1:03x} ({j-i} B)")
        # show values for each model in this range (max 8 bytes per row)
        for start in range(i, j, 8):
            end = min(start+8, j)
            row = ' | '.join(f"{n[:6]}:" + ' '.join(f'{hdrs[n][k]:02x}' for k in range(start, end)) for n in names)
            print("   ", row)
        i = j
