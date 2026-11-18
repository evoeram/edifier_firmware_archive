

# -------------------------------------------------------------- emission ----

HEADER = """\
# pi32v2 SLEIGH specification - GENERATED from the pi32v2-isa table
# (isa/pi32v2.toml, {ninsn} forms, status=confirmed) by tools/gen_sleigh.py.
# Decode-only: semantics are provided for branches/calls/returns (control flow);
# data-processing p-code is a later task. Display matches JieLi objdump except
# branch/call targets, which are shown as absolute addresses.
#
# Encoding model: ONE little-endian 16-bit token (equal to the codec's per-word
# read); wider instructions consume consecutive tokens via the `;` pattern
# sections. Field bit order follows the table's field_bits (value MSB first).
# Branch-target subtables export *:4 (kagaimiq style); offsets spanning several
# words use dedicated subtables anchored with `... & btX`.

define endian    = little;
define alignment = 2;

define space ram      type=ram_space      size=4 default;
define space register type=register_space size=4;

define register offset=0x0 size=4
\t[ r0 r1 r2 r3 r4 r5 r6 r7 r8 r9 r10 r11 r12 r13 r14 r15 ];

# Paired registers
define register offset=0x0 size=8
\t[ r0_r1 r2_r3 r4_r5 r6_r7 r8_r9 r10_r11 r12_r13 r14_r15 ];

define register offset=0x100 size=4
\t[ {srregs} ];
"""


def emit(spec, path):
    out = [HEADER.format(ninsn=len(TABLE.insns),
                         srregs=' '.join(SR_NAMES))]

    # single 16-bit token; word index is encoded in the field NAME only
    out.append("define token instr (16)")
    for name, (w, lo, hi, signed) in sorted(spec.field_defs.items(),
                                            key=lambda kv: (kv[1][0], kv[1][1], kv[1][2])):
        out.append(f"  {name} = ({lo},{hi}){' signed' if signed else ''}")
    out.append(";\n")

    if spec.attach_vars:
        out.append("# ---- attached registers ----")
        for name, regs in spec.attach_vars.items():
            out.append(f"attach variables [ {name} ] [ {' '.join(regs)} ];")
        out.append("")
    if spec.attach_names:
        out.append("# ---- attached names (display only) ----")
        for name, vals in spec.attach_names.items():
            out.append(f"attach names [ {name} ] [ {' '.join(q(v) for v in vals)} ];")
        out.append("")
    if spec.attach_values:
        out.append("# ---- attached values ----")
        for name, vals in spec.attach_values.items():
            out.append(f"attach values [ {name} ] [ {' '.join(str(v) for v in vals)} ];")
        out.append("")

    out.append("define pcodeop cond_unspec;\n")
    out.append("define pcodeop rep_unspec;\n")
    out.append("define pcodeop swi_unspec;\n")
    out.append("define pcodeop testset_unspec;\n")
    if spec.pcodeops:
        out.append("\n# ---- B1.3 stub/helper pcodeops ----")
        for name in sorted(spec.pcodeops):
            out.append(f"define pcodeop {name};")
        out.append("")

    if spec.subtables:
        out.append("# ---- branch-target subtables ----")
        for key, (stname, text, meta) in sorted(spec.subtables.items(),
                                                key=lambda kv: kv[1][0]):
            out.append(text)
            out.append("")
        out.append("")

    out.append("# ---- instructions ----")
    n_note = 0
    for insn, display, pattern, ext_text, pcode, comments in spec.constructors:
        for c in comments:
            out.append(f"# NOTE({insn.id}): {c}")
            n_note += 1
        out.append(f"# {insn.id} | {insn.group} | {insn.summary[:100]}")
        line = f":{display} is {pattern}"
        if ext_text:
            line += " " + ext_text
        out.append(line)
        if pcode:
            out.append("{" + "\n\t" + pcode + "\n}")
        else:
            out.append("{ }")
        out.append("")
    with open(path, 'w', encoding='utf-8', newline='\n') as f:
        f.write("\n".join(out))
    print(f"wrote {path}: {len(spec.constructors)} constructors, "
          f"{len(spec.field_defs)} token fields, {len(spec.subtables)} bt-subtables, "
          f"{n_note} notes")


# ------------------------------------------------------------- self-check ----

def selfcheck(spec):
    """Re-evaluate every branch-target formula in Python against codec.value."""
    bad = 0
    checked = 0
    for key, (stname, _text, meta) in spec.subtables.items():
        if meta is None:
            continue          # register-split subtables carry no offset formula
        pieces, sizes, scale, add, w, signed = meta
        for insn in TABLE.insns:
            for letter, f in insn.fields.items():
                if f.kind not in ('simm', 'uimm') or f.scale != scale or f.add != add:
                    continue
                pos = insn.field_bits(letter)
                if sum(last - first + 1 for _, first, last in pieces) != w:
                    continue
                if [p for p in pos if True] and pieces != [
                        (p // 16, p, p) for p in []] and not _pieces_match(pos, pieces):
                    continue
                for ex in insn.examples:
                    vals = codec.fields_of(insn, ex.bytes)
                    raw_full = vals[letter]
                    bits = [(raw_full >> (w - 1 - i)) & 1 for i in range(w)]
                    raws, k = [], 0
                    for sz in sizes:
                        chunk = 0
                        for b in bits[k:k + sz]:
                            chunk = (chunk << 1) | b
                        k += sz
                        raws.append(chunk)
                    got = eval_num(raws, sizes, scale, add, signed, w)
                    exp = codec.value(f, raw_full, w)
                    checked += 1
                    if got != exp:
                        bad += 1
                        if bad <= 5:
                            print(f"  MISMATCH {insn.id}.{letter}: formula {got} != codec {exp}")
                    break   # first matching field only
    print(f"self-check: {checked} branch-offset formulas verified, {bad} mismatches")
    return bad == 0


def _pieces_match(pos, pieces):
    """Do the field's value-bit positions split into exactly these pieces (in order)?"""
    out = []
    k = 0
    for w, first, last in pieces:
        n = last - first + 1
        chunk = pos[k:k + n]
        if len(chunk) != n:
            return False
        # a piece must be contiguous and inside its word
        if chunk != list(range(first, last + 1)):
            return False
        if any(p // 16 != w for p in chunk):
            return False
        k += n
    return k == len(pos)


# -------------------------------------------------------------------- main ----

TABLE = load()


def main():
    spec = Spec()
    for insn in TABLE.insns:
        if insn.nbits not in (16, 32, 48):
            print(f"skip {insn.id}: nbits {insn.nbits}")
            continue
        g = InsnGen(spec, insn)
        display, pattern, ext_text, pcode = g.build()
        spec.constructors.append((insn, display, pattern, ext_text, pcode, g.comments))
    ok = selfcheck(spec)
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    emit(spec, OUT)
    print(f"pcode coverage: {spec.pcode_stats.get('pcode_ok', 0)} forms with "
          f"semantics, {sum(v for k, v in spec.pcode_stats.items() if k != 'pcode_ok')} "
          f"unsupported")
    for k, v in spec.pcode_stats.most_common(25):
        if k != 'pcode_ok':
            print(f"  {v:5d}  {k}")
            for ex in spec.pcode_examples.get(k, [])[:4]:
                print(f"          e.g. {ex}")
    if not ok:
        print("SELF-CHECK FAILED")


if __name__ == '__main__':
    main()
