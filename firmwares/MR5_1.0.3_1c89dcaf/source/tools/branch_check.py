import re
import collections

LST = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\disasm\mr5_app_disasm.txt'
DMP = r'C:\Users\User\AppData\Local\Temp\opencode\ghidra_dump.txt'
LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')
BRANCH_RE = re.compile(r'\b(goto|call)\b')


def norm(s):
    return ' '.join(s.split())


ref = {}
for raw in open(LST, encoding='utf-8', errors='replace'):
    m = LINE_RE.match(raw.rstrip('\n'))
    if m:
        ref[int(m.group(1), 16)] = (len(m.group(2).split()), norm(m.group(3)))

bad = []
for raw in open(DMP, encoding='utf-8', errors='replace'):
    raw = raw.rstrip('\n')
    if not raw:
        continue
    parts = raw.split(None, 2)
    addr = int(parts[0], 16)
    if parts[1] == 'MISSING':
        continue
    rsize, rtext = ref[addr]
    gtext = norm(parts[2]) if len(parts) > 2 else ''
    if gtext == rtext:
        continue
    if BRANCH_RE.search(rtext) and rsize == int(parts[1]):
        rp, gp = rtext.split(), gtext.split()
        if len(rp) != len(gp):
            bad.append(('LEN', addr, rtext, gtext))
            continue
        for a, b in zip(rp, gp):
            if a == b:
                continue
            if re.fullmatch(r'-?\d+', a) and re.fullmatch(r'(0x)?[0-9a-f]+', b):
                exp = (addr + rsize + int(a)) & ~1
                got = int(b, 16) if b.startswith('0x') else int(b)
                if got != exp:
                    bad.append(('TARGET', addr, rtext, gtext))
                    break
            elif re.fullmatch(r'(0x)?[0-9a-f]+', a) and re.fullmatch(r'(0x)?[0-9a-f]+', b):
                # plain numeric compare (hex vs decimal formatting)
                ia = int(a, 16) if a.startswith('0x') else int(a)
                ib = int(b, 16) if b.startswith('0x') else int(b)
                if ia != ib:
                    bad.append(('TARGET2', addr, rtext, gtext))
                    break
            else:
                bad.append(('FMT', addr, rtext, gtext))
                break

print('unverified branch lines:', len(bad))
c = collections.Counter(k for k, *_ in bad)
print(c)
for k, addr, r, g in [b for b in bad if b[0] == 'TARGET'][:8]:
    print(f'{k} {addr:08x} ref: {r} || ghidra: {g}')
for k, addr, r, g in [b for b in bad if b[0] == 'LEN'][:6]:
    print(f'{k} {addr:08x} ref: {r} || ghidra: {g}')
for k, addr, r, g in [b for b in bad if b[0] == 'FMT'][:6]:
    print(f'{k} {addr:08x} ref: {r} || ghidra: {g}')
