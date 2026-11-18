#!/usr/bin/env python3
# A3-prep: locate function starts in the UNDECODED regions of MR5 app.bin.
#
# B2 found 248 mov32-imm sites (Cx FF imm32) that reference strings but lie
# OUTSIDE the recursive-disassembly coverage -> indirect-called functions.
# This tool recovers their true function starts:
#   1. sweep raw mov32 sites; keep those outside decoded coverage;
#   2. for each site, walk backwards (2-byte steps) and linear-decode with
#      the hardware-validated pi32v2isa decoder; a candidate C is accepted
#      when linear decode from C cleanly reaches the site (site = insn start)
#      and continues >= MIN_PAST bytes beyond it; take the earliest C whose
#      clean run before the site is >= MIN_BACK bytes;
#   3. verify the start looks like a prologue (push {rets,...}) when possible;
#   4. estimate function extent (decode until undecodable byte / next start).
# Output: disasm/hidden_funcs.txt  ("ADDR SIZE_EVIDENCE" lines + comments)
import sys, os, struct, collections

HERE = os.path.dirname(os.path.abspath(__file__))
PKG = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
sys.path.insert(0, PKG)
sys.path.insert(0, HERE)
os.chdir(PKG)

from pi32v2isa import codec
from pi32v2isa.table import load
from pi32v2isa.objdump import decoder_for, BRANCH_FIELD

SRC = os.path.dirname(HERE)
APP = os.path.join(SRC, 'decrypted', 'app.bin')
LST = os.path.join(SRC, 'disasm', 'mr5_app_disasm.txt')
OUT = os.path.join(SRC, 'disasm', 'hidden_funcs.txt')
BASE = 0x06000100

import re
LINE_RE = re.compile(r'^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$')
MIN_BACK = 24        # min clean bytes before the site
MIN_PAST = 24        # min clean bytes after the site
MAX_BACK = 4096      # how far to walk back

def main():
    data = open(APP, 'rb').read()
    N = len(data)
    tab = load()
    dec = decoder_for(tab)

    # decoded coverage from the existing listing
    cov = bytearray(N)          # 1 = byte belongs to a decoded instruction
    insns = set()
    cur = None
    for raw in open(LST, encoding='utf-8', errors='replace'):
        raw = raw.rstrip('\n')
        if raw.startswith('sub_'):
            cur = raw
            continue
        if raw.startswith(';') or not raw.strip():
            continue
        m = LINE_RE.match(raw)
        if not m:
            continue
        off = int(m.group(1), 16) - BASE
        size = len(m.group(2).split())
        for i in range(off, min(N, off + size)):
            cov[i] = 1
        insns.add(off)

    # raw mov32 sweep
    sites = []
    i = 0
    while i < N - 5:
        if 0xC0 <= data[i] <= 0xCF and data[i + 1] == 0xFF:
            v = struct.unpack_from('<I', data, i + 2)[0]
            o = v - BASE
            if 0 <= o < N:
                sites.append(i)
            i += 6
        else:
            i += 1
    hidden_sites = [s for s in sites if not cov[s]]
    print(f'mov32 sites: {len(sites)}, hidden (outside decoded coverage): {len(hidden_sites)}')

    def clean_run(c):
        """Linear-decode from c; return list of (off,size) until undecodable."""
        out, off = [], c
        while off < N:
            got = dec.decode(data, off)
            if got is None:
                break
            insn, values, size, text = got
            out.append((off, size, text, insn.id))
            off += size
        return out

    starts = {}
    stats = collections.Counter()
    for site in sorted(hidden_sites):
        best = None
        c = site - 2
        limit = site - MAX_BACK
        while c >= 0 and c >= limit:
            if cov[c]:
                break                      # walked into known code: stop
            run = clean_run(c)
            offs = [o for o, _, _, _ in run]
            end = c + sum(sz for _, sz, _, _ in run)
            if site in offs and end >= site + MIN_PAST \
                    and (site - c) >= MIN_BACK:
                best = c                   # keep earliest (furthest back)
                break
            # if linear decode from c doesn't even reach site cleanly, earlier
            # candidates won't help either ONLY if the block is undecodable;
            # but misaligned starts can decode garbage -> keep walking back.
            c -= 2
        if best is None:
            stats['no_start'] += 1
            starts.setdefault(site, (site, []))   # fallback: start at site
            continue
        run = clean_run(best)
        starts.setdefault(best, (best, run))
        stats['found'] += 1

    # sort; extents are capped at the next start (linear decode may cross
    # function boundaries, so overlapping clean runs are normal)
    all_starts = sorted(starts.items())
    final = [(a, run) for a, (a, run) in all_starts]

    # estimate extents
    out_lines = []
    funcs = []
    for idx, (a, run) in enumerate(final):
        nxt = final[idx + 1][0] if idx + 1 < len(final) else N
        end = a
        for off, sz, text, iid in run:
            if off >= nxt:
                break
            end = off + sz
        # extend beyond run end while decode is clean
        off = end
        while off < nxt:
            got = dec.decode(data, off)
            if got is None:
                break
            end = off + got[2]
            off = end
        funcs.append((a, end))
        n_ins = sum(1 for off, _, _, _ in run if off < nxt)
        # evidence: string refs inside body
        ev = []
        for off, sz, text, iid in run:
            if off >= nxt:
                break
            m = re.search(r'\b(\d{7,})\b', text)
            if m:
                v = int(m.group(1))
                o = v - BASE
                if 0 <= o < N:
                    s = extract_str(data, o)
                    if s and len(s) >= 4:
                        ev.append(s[:40])
        first = run[0][3] if run else ''
        first_txt = run[0][2] if run else ''
        mark = 'prologue-ok' if ('sp' in first_txt and '[' in first_txt) else ''
        out_lines.append((a, end, n_ins, ev[:3], mark))

    with open(OUT, 'w', encoding='utf-8') as f:
        f.write('; MR5 hidden functions: starts recovered from mov32 sites\n')
        f.write('; outside recursive-disassembly coverage (see B2).\n')
        f.write(f'; sites={len(hidden_sites)} starts={len(final)} '
                f'(fallback-at-site={stats["no_start"]})\n\n')
        for a, end, n_ins, ev, mark in sorted(out_lines):
            evs = (' ; ' + ' | '.join(repr(e) for e in ev)) if ev else ''
            f.write(f'{BASE+a:08x} size={end-a:5d} insns~{n_ins:4d} {mark}{evs}\n')
    print(f'wrote {OUT}: {len(final)} hidden function starts')
    print(stats)

def extract_str(data, o, maxlen=48):
    out = bytearray()
    while o < len(data) and 0x20 <= data[o] < 0x7f and len(out) < maxlen:
        out.append(data[o])
        o += 1
    if len(out) >= 4:
        return out.decode('ascii')
    return None

if __name__ == '__main__':
    main()
