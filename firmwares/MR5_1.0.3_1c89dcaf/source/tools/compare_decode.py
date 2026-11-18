#!/usr/bin/env python3
# A1 verification: compare the Ghidra decode dump (VerifyDecode.java) against the
# reference listing (mr5_app_disasm.txt).
#   - size match per instruction;
#   - text match after whitespace normalization, with branch/call targets
#     normalized (Ghidra shows absolute addresses, the listing shows offsets).
import re
import sys
import collections

LST = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\disasm\mr5_app_disasm.txt'
DMP = sys.argv[1] if len(sys.argv) > 1 else r'C:\Users\User\AppData\Local\Temp\opencode\ghidra_dump.txt'

LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')
BRANCH_RE = re.compile(r'\b(goto|call|gotoss|callns|tbb|tbh|ifs2ns)\b')


def norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def main():
    ref = {}
    for raw in open(LST, encoding='utf-8', errors='replace'):
        m = LINE_RE.match(raw.rstrip('\n'))
        if m:
            ref[int(m.group(1), 16)] = (len(m.group(2).split()), norm(m.group(3)))

    missing = []
    size_bad = []
    text_bad = []
    ok = 0
    branch_checked = branch_ok = 0
    for raw in open(DMP, encoding='utf-8', errors='replace'):
        raw = raw.rstrip('\n')
        if not raw:
            continue
        parts = raw.split(None, 2)
        addr = int(parts[0], 16)
        rsize, rtext = ref[addr]
        if parts[1] == 'MISSING':
            missing.append((addr, rtext))
            continue
        gsize = int(parts[1])
        gtext = norm(parts[2]) if len(parts) > 2 else ''
        if gsize != rsize:
            size_bad.append((addr, rsize, gsize, rtext, gtext))
            continue
        if gtext == rtext:
            ok += 1
            continue
        # branch forms: ghidra shows the absolute target, listing shows the offset
        if BRANCH_RE.search(rtext):
            branch_checked += 1
            rp = rtext.split()
            gp = gtext.split()
            if len(rp) == len(gp):
                same = True
                for a, b in zip(rp, gp):
                    if a == b:
                        continue
                    if re.fullmatch(r'-?\d+', a) and re.fullmatch(r'(0x)?[0-9a-fA-F]+', b):
                        # offset vs absolute target: target = (addr+size+off) & ~1
                        exp = (addr + rsize + int(a)) & ~1
                        got = int(b, 16) if b.startswith('0x') else int(b)
                        if got != exp:
                            same = False
                    else:
                        same = False
                if same:
                    branch_ok += 1
                    continue
        text_bad.append((addr, rtext, gtext))

    total = len(ref)
    print(f'total: {total}')
    print(f'exact text match: {ok} ({100 * ok / total:.2f}%)')
    print(f'missing (not decoded): {len(missing)} ({100 * len(missing) / total:.3f}%)')
    print(f'size mismatches: {len(size_bad)}')
    print(f'branch targets verified: {branch_ok}/{branch_checked}')
    print(f'other text mismatches: {len(text_bad)}')

    def bucket(seq, n=12, key=lambda x: x):
        c = collections.Counter(key(x) for x in seq)
        return c.most_common(n)

    if missing:
        print('\n-- missing samples:')
        for a, t in missing[:8]:
            print(f'   {a:08x}  {t}')
        print('   by first word of text:', bucket(missing, key=lambda x: x[1].split()[0]))
    if size_bad:
        print('\n-- size mismatch samples:')
        for a, rs, gs, rt, gt in size_bad[:8]:
            print(f'   {a:08x} ref={rs} ghidra={gs} | {rt}  ||  {gt}')
    if text_bad:
        print('\n-- text mismatch samples:')
        for a, rt, gt in text_bad[:15]:
            print(f'   {a:08x} ref: {rt}  ||  ghidra: {gt}')
        print('   by ref mnemonic:', bucket(text_bad, key=lambda x: x[1].split()[0]))


if __name__ == '__main__':
    main()
