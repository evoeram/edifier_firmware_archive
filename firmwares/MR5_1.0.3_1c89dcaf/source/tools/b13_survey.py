#!/usr/bin/env python3
# B1.3 survey: family x error x field kinds for every form the expression
# compiler rejects. Decides the pcodeop-stub mapping.
import sys, os, collections

HERE = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\tools'
PKG = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
sys.path.insert(0, HERE)
sys.path.insert(0, PKG)
os.chdir(PKG)

import gen_sleigh as G   # noqa: E402  (TABLE, Spec, InsnGen, PcodeCompiler...)

fam_err = collections.Counter()          # (family, errorclass) -> n
err_kinds = collections.defaultdict(set) # errorclass -> {field kinds}
fam_kinds = collections.defaultdict(set) # family -> {field kinds}
err_examples = collections.defaultdict(list)

for insn in G.TABLE.insns:
    if insn.nbits not in (16, 32, 48):
        continue
    spec = G.Spec()
    g = G.InsnGen(spec, insn)
    display, pattern, ext_text, pcode = g.build()
    if pcode:
        continue
    fam = insn.id.split('.')[0]
    # re-run to capture the error class
    g2 = G.InsnGen(G.Spec(), insn)
    g2.build()
    # error class: rebuild stats delta is awkward; instead try compile directly
    g3 = G.InsnGen(G.Spec(), insn)
    g3.add_constraints()
    for letter in insn.fields:
        g3.build_field(letter, insn.fields[letter])
    err = 'ok?'
    try:
        G.PcodeCompiler(g3).compile()
    except G.PcodeError as e:
        err = str(e)[:40]
    fam_err[(fam, err)] += 1
    err_kinds[err].update(f.kind for f in insn.fields.values())
    fam_kinds[fam].update(f.kind for f in insn.fields.values())
    if len(err_examples[err]) < 3:
        err_examples[err].append(f'{insn.id} | {insn.syntax}')

by_fam = collections.defaultdict(int)
for (fam, err), n in fam_err.items():
    by_fam[fam] += n
print('=== families (unsupported forms) ===')
for fam, n in sorted(by_fam.items(), key=lambda kv: -kv[1]):
    errs = {e: c for (f, e), c in fam_err.items() if f == fam}
    tops = sorted(errs.items(), key=lambda kv: -kv[1])[:2]
    print(f'{n:4d}  {fam:24s} kinds={sorted(fam_kinds[fam])}  errs={tops}')
print()
print('=== error classes -> field kinds ===')
for err, kinds in sorted(err_kinds.items(), key=lambda kv: -len(kv[1])):
    print(f'{err!r}: kinds={sorted(kinds)}')
    for ex in err_examples[err]:
        print(f'    {ex}')
