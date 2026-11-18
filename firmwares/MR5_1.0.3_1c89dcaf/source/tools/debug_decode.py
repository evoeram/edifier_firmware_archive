#!/usr/bin/env python3
"""Debug A1 decode mismatches: bytes, codec form, generated constructors, Ghidra result."""
import re
import sys
import collections

sys.path.insert(0, r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg')
from pi32v2isa.table import load          # noqa: E402
from pi32v2isa import codec               # noqa: E402

LST = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\disasm\mr5_app_disasm.txt'
DMP = r'C:\Users\User\AppData\Local\Temp\opencode\ghidra_dump.txt'
SPEC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\gen\pi32v2_full.slaspec'
BIN = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\app_bin_full.bin'

# address base of the program: infer from listing vs file. The Ghidra program was
# imported from app_bin_full.bin at base 0x06000000 (check: first listing addr).
BASE = 0x06000100

LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')

data = open(BIN, 'rb').read()
table = load()


def word_at(addr, n=1):
    off = addr - BASE
    v = 0
    for k in range(n):
        v = (v << 16) | data[off + 2 * k] | (data[off + 2 * k + 1] << 8)
    return v


def codec_form(addr):
    off = addr - BASE
    got = codec.decode(table, data, off)
    if got is None:
        return None
    return got[0], got[2]   # insn, length


# ---- parse dump and listing
ref = {}
for raw in open(LST, encoding='utf-8', errors='replace'):
    m = LINE_RE.match(raw.rstrip('\n'))
    if m:
        ref[int(m.group(1), 16)] = (m.group(2).split(), m.group(3).strip())

ghidra = {}
for raw in open(DMP, encoding='utf-8', errors='replace'):
    raw = raw.rstrip('\n')
    if not raw:
        continue
    parts = raw.split(None, 2)
    addr = int(parts[0], 16)
    if parts[1] == 'MISSING':
        ghidra[addr] = None
    else:
        ghidra[addr] = (int(parts[1]), parts[2] if len(parts) > 2 else '')

# ---- parse the generated spec: constructor -> (word0 mask, word0 value, nwords)
spec_lines = open(SPEC, encoding='utf-8').read().splitlines()
ctors = []          # (lineno, display, constraint list)
i = 0
while i < len(spec_lines):
    l = spec_lines[i]
    if l.startswith(':'):
        m = re.match(r'^:.*? is (.+?)$', l)
        if m:
            pat = m.group(1)
            if ' is ' in l and not l.rstrip().endswith(']') or True:
                pass
            # pattern may continue with ext section ' [ ... ]'
            pat = re.split(r' \[', pat)[0]
            ctors.append((i + 1, l.split(' is ')[0][1:], pat))
    i += 1


def pattern_word0_mask_value(pat):
    """Combine constraints that fall into the first 16 bits (word0) of each token."""
    mask = 0
    value = 0
    for c in pat.split(' & '):
        c = c.strip()
        if '=' not in c:
            continue           # bare field: no constraint
        # fields named c16_lo_hi: token size from the name
        m2 = re.match(r'^c(\d+)_(\d+)_(\d+)=0x([0-9a-fA-F]+)$', c)
        if not m2:
            return None        # bare field in pattern: not a pure-constraint form
        tok, lo, hi, v = int(m2.group(1)), int(m2.group(2)), int(m2.group(3)), int(m2.group(4), 16)
        width = hi - lo + 1
        if tok != 16:
            # constraint bits of a wider token: word0 bits are tok bits >= tok-16
            shift = tok - 16
            if lo >= shift:
                # entirely within word0: token bit lo..hi -> word0 bits (lo-shift)..(hi-shift)
                wlo, whi = lo - shift, hi - shift
                msk = ((1 << (whi - wlo + 1)) - 1)
                mask |= msk << wlo
                value |= (v & msk) << wlo
            elif hi >= shift:
                return None    # crosses the word boundary; ignore (rare)
            # else: constraint entirely in word1+: does not affect word0
        else:
            msk = ((1 << width) - 1)
            mask |= msk << lo
            value |= (v & msk) << lo
    return mask, value


spec_forms = []
for lineno, disp, pat in ctors:
    mv = pattern_word0_mask_value(pat)
    if mv is None:
        continue
    spec_forms.append((lineno, disp, pat, mv[0], mv[1]))


def spec_word0_matches(w0):
    out = []
    for lineno, disp, pat, mask, value in spec_forms:
        if w0 & mask == value:
            out.append((lineno, disp, pat))
    return out


def report(addr):
    print(f'==== {addr:08x}')
    rb, rt = ref[addr]
    print(f'  ref   : {" ".join(rb)}  {rt}')
    off = addr - BASE
    print(f'  bytes : {data[off:off+8].hex(" ")}')
    w0 = data[off] | data[off + 1] << 8
    print(f'  word0 : {w0:04x}')
    cf = codec_form(addr)
    if cf:
        print(f'  codec : {cf[0].id} ({cf[0].nbits} bit) len={cf[1]}')
    g = ghidra.get(addr)
    print(f'  ghidra: {g}')
    print(f'  table first-word matches:')
    for ins in table.insns:
        m, v = ins.mask, ins.value
        shift = 16 * (len(ins.words) - 1)
        if w0 & (m >> shift) == (v >> shift):
            print(f'    {ins.id} {ins.nbits}bit')
    sm = spec_word0_matches(w0)
    print(f'  spec  first-word matches: {len(sm)}')
    for lineno, disp, pat in sm[:6]:
        print(f'    L{lineno} :{disp[:80]} is {pat[:110]}')


if __name__ == '__main__':
    n_missing = sum(1 for v in ghidra.values() if v is None)
    n_size = 0
    n_ok = 0
    size_samples = []
    for a, g in ghidra.items():
        if g is None:
            continue
        rs = len(ref[a][0])
        if g[0] == rs:
            n_ok += 1
        else:
            n_size += 1
            size_samples.append(a)
    print(f'dump: {len(ghidra)} entries, missing={n_missing}, size_ok={n_ok}, size_bad={n_size}')
    for a in size_samples[:6]:
        report(a)
    if len(sys.argv) > 1:
        for a in sys.argv[1:]:
            report(int(a, 16))
