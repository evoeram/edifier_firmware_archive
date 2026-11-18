
# ------------------------------------------------------- operand building ----

VAR_LISTS = {
    'gpr': [f"r{k}" for k in range(16)],
    'gpr_lo': [f"r{k}" for k in range(8)],
    'gpr_hi': [f"r{k}" for k in range(8, 16)],
}

NAME_LISTS = {
    'pair': [f"r{2 * k + 1}_r{2 * k}" for k in range(8)],
    'sr': list(SR_NAMES),
    'bit': [str(1 << k) for k in range(32)],
    'invbit': [str(0xFFFFFFFF ^ (1 << k)) for k in range(32)],
    'pair_regs': pair_regs_names(),
    'rlist4': rlist4_names(),
}

# B1.3: p-code counterpart for the 3-bit 'pair' display field: the 8-byte
# register varnodes defined in the header (display keeps the objdump order
# r1_r0 = high,low; the varnode r0_r1 holds r0 as the low word).
PAIR_VAR_LIST = [f"r{2 * k}_r{2 * k + 1}" for k in range(8)]

# Semantic (p-code) counterparts for attach-name kinds: variables must match
# the register definitions in the header; values are the decoded constants.
# NOTE: attach variables cannot coexist with attach names on one field, so only
# kinds whose display equals the register name get variables ('sr'); 'pair'
# keeps display names ("r1_r0") and stays registerless in p-code.
VAR_OF_NAME = {
    'sr': list(SR_NAMES),
}
VALUE_OF_NAME = {
    'bit': [1 << k for k in range(32)],
    'invbit': [0xFFFFFFFF ^ (1 << k) for k in range(32)],
}

TARGET_RE = re.compile(r"\b(gotoss|goto|callns|call)\s*\{(\+?)(\w)\}")

FLAG_CONDS = {
    'ifeq': 'c_Z',
    'ifne': '(c_Z ^ 1)',
    'ifcs': 'c_C',
    'ifcc': '(c_C ^ 1)',
    'ifhi': '(c_C & (c_Z ^ 1))',
    'ifls': '((c_C ^ 1) | c_Z)',
    'ifge': '((c_N ^ c_V) ^ 1)',
    'iflt': '(c_N ^ c_V)',
    'ifgt': '((c_Z ^ 1) & ((c_N ^ c_V) ^ 1))',
    'ifle': '(c_Z | (c_N ^ c_V))',
}

FLAG_PROLOGUE = ("local p_fl:4 = psr; local c_N:1 = psr[3,1]; local c_Z:1 = psr[2,1]; "
                 "local c_C:1 = psr[1,1]; local c_V:1 = psr[0,1]; ")


def pieces_expr(pieces, field_names):
    """SLEIGH expression composing pieces (value-bit order) into the raw field value."""
    sizes = [last - first + 1 for _, first, last in pieces]
    parts = []
    for i, fn in enumerate(field_names):
        after = sum(sizes[i + 1:])
        parts.append(f"({fn} << {after})" if after else fn)
    return " | ".join(parts) if len(parts) > 1 else parts[0]


def num_expr(pieces, field_names, scale, add):
    """Expression for value = raw*scale + add."""
    e = pieces_expr(pieces, field_names)
    if scale == 1 and add == 0:
        return e
    terms = []
    terms.append(f"({e}) * {scale}" if scale != 1 else f"({e})")
    if add:
        terms.append(f"({add})" if add < 0 else str(add))
    return " + ".join(terms)


def eval_num(raws, sizes, scale, add, signed, w):
    """Python evaluation of the same value (self-check against codec.value)."""
    v = 0
    for r, sz in zip(raws, sizes):
        v = (v << sz) | r
    if signed and v >= (1 << (w - 1)):
        v -= 1 << w
    return v * scale + add


class InsnGen:
    """Builds display/pattern/ext/pcode for one table form."""

    def __init__(self, spec, insn):
        self.s = spec
        self.i = insn
        self.tmp_n = 0
        self.att_vf = {}         # display field name -> companion value field
        self.att_vf_reg = set()  # ... -> whose companion is a variable attach
        self.bits = ''.join(insn.words)
        self.nbits = insn.nbits
        self.nwords = insn.nbits // 16
        self.sec_cons = collections.defaultdict(list)   # w -> [(name, value)]
        self.sec_bare = collections.defaultdict(list)   # w -> [field names]
        self.ext = []              # list of (opname, sleigh_expr)
        self.comments = []
        self.pcode_id = {}         # letter -> identifier usable in p-code
        self.pcode_isreg = {}      # letter -> True when the identifier is a register varnode
        self.field_info = {}       # letter -> aliasing info tuple
        self.target_st = None      # branch-target subtable name
        self.spanning = False      # dedicated spanning subtable in use

    # -- field piece registration ------------------------------------------
    def pieces_of(self, name, f):
        """(attached_single, pieces) where pieces = [(w, first, last)] in value order,
        split at word boundaries. attached_single is the single attached field name."""
        pos = self.i.field_bits(name)
        runs = contig_runs(pos)
        attached = f.kind in NAME_LISTS or f.kind in VAR_LISTS or f.kind == 'enum' \
            or (f.kind == 'srmask' and len(pos) < 16) or f.kind == 'modimm'
        if len(runs) == 1 and attached and runs[0][0] // 16 == runs[0][1] // 16:
            first, last = runs[0]
            w = first // 16
            lo, hi = 15 - (last - 16 * w), 15 - (first - 16 * w)
            return self.attached_field(f.kind, f, w, lo, hi, last - first + 1), \
                [(w, first, last)]
        pieces = []
        for run in runs:
            pieces.extend(split_run_word(run))
        return None, pieces

    def piece_fields(self, pieces, kind, signed_msb_piece):
        """Register raw token fields for the pieces; returns names in value order."""
        out = []
        for idx, (w, first, last) in enumerate(pieces):
            lo, hi = 15 - (last - 16 * w), 15 - (first - 16 * w)
            signed = signed_msb_piece and idx == 0 and kind == 'simm'
            out.append(self.s.field(w, lo, hi, 'raw', signed))
        return out

    def attached_field(self, kind, f, w, lo, hi, width, suffix=''):
        """Register (once) a field with an attached name/value/variable list."""
        s = self.s
        if kind in VAR_LISTS:
            name = s.field(w, lo, hi, kind + suffix)
            s.attach_vars[name] = VAR_LISTS[kind]
            return name
        if kind == 'enum':
            key = ('enum', w, lo, hi, suffix, tuple(f.values))
            if key in s.fields:
                return s.fields[key]
            name = s.field(w, lo, hi, f"e{len(s.attach_names)}{suffix}")
            s.attach_names[name] = list(f.values)
            s.fields[key] = name
            return name
        if kind == 'modimm':
            key = ('mi', w, lo, hi, f.invert, f.decimal, suffix)
            if key in s.fields:
                name = s.fields[key]
                return name
            name = s.field(w, lo, hi, f"nmi{int(f.invert)}{int(f.decimal)}{suffix}")
            vals = []
            ivalues = []
            for raw in range(1 << width):
                v = codec.modimm(raw)
                if f.invert:
                    v ^= 0xFFFFFFFF
                ivalues.append(v)
                vals.append(str(v) if f.decimal else f"0x{v:X}")
            s.attach_names[name] = vals
            # companion value field for p-code (names+values on one field
            # are rejected by SLEIGH)
            vname = s.field(w, lo, hi,
                            f"mival{int(f.invert)}{int(f.decimal)}{suffix}")
            if vname not in s.attach_values:
                s.attach_values[vname] = ivalues
            self.att_vf[name] = vname
            s.fields[key] = name
            return name
        if kind == 'srmask':
            name = s.field(w, lo, hi, f"nsrm{width}{suffix}")
            s.attach_names[name] = srmask_names(width)
            return name
        # NAME_LISTS kinds
        name = s.field(w, lo, hi, f"n{kind}{suffix}")
        if kind in VAR_OF_NAME:
            # attach variables cannot coexist with attach names on one field;
            # the display becomes the register name (identical for 'sr')
            s.attach_vars[name] = VAR_OF_NAME[kind]
        else:
            s.attach_names[name] = NAME_LISTS[kind]
            if kind in VALUE_OF_NAME:
                vname = s.field(w, lo, hi, f"v{kind}{suffix}")
                if vname not in s.attach_values:
                    s.attach_values[vname] = VALUE_OF_NAME[kind]
                self.att_vf[name] = vname
            elif kind == 'pair':
                # B1.3: companion variable field (8-byte pair varnodes) so
                # pair operands exist in p-code while the display keeps the
                # objdump r1_r0 order
                vname = s.field(w, lo, hi, f"vp{suffix}")
                s.attach_vars[vname] = list(PAIR_VAR_LIST)
                self.att_vf[name] = vname
                self.att_vf_reg.add(name)
        return name

    # ------------------------------------------------------ construction ----
    def build(self):
        insn = self.i
        self.add_constraints()
        targets = list(TARGET_RE.finditer(insn.syntax))
        target_letter = targets[-1].group(3) if targets else None
        placeholders = [m.group(2) for m in SYNTAX_TOKEN.finditer(insn.syntax) if m.group(2)]
        disp = {}
        for letter in placeholders:
            if letter in disp:
                continue
            if letter == target_letter and insn.fields[letter].kind != 'gpr':
                disp[letter] = self.build_target(letter, insn.fields[letter])
            else:
                disp[letter] = self.build_field(letter, insn.fields[letter])
        display = self.build_display(insn.syntax, disp)
        pattern = self.build_pattern()
        ext_text = ""
        if self.ext:
            ext_text = "[ " + " ".join(f"{op} = {e};" for op, e in self.ext) + " ]"
        pcode = self.build_pcode(targets, target_letter)
        if not pcode:
            # B1: try the expression compiler for data-processing forms
            self.tmp_n = 0
            try:
                pc = PcodeCompiler(self).compile()
                if pc:
                    pcode = pc
                    self.s.pcode_stats['pcode_ok'] += 1
            except PcodeError as e:
                key = 'unsup: ' + str(e)[:70]
                self.s.pcode_stats[key] += 1
                self.s.pcode_examples.setdefault(key, []).append(
                    f"{self.i.id} | {self.i.syntax}")
                # B1.3: parameterized pcodeop stub with the form's operands
                pc = self.stub_pcode()
                if pc:
                    pcode = pc
                    self.s.pcode_stats['stub_ok'] += 1
        return display, pattern, ext_text, pcode

    STUB_ASSIGN = {'=', '+=', '-=', '*=', '&=', '|=', '^=', '<<=', '>>=',
                   '>>>=', '<<<=', '<=', '<c>=', '<>='}

    def stub_arg(self, letter):
        """P-code identifier usable as a stub argument, or None."""
        if letter not in self.pcode_id:
            return None
        if self.pcode_isreg.get(letter):
            return self.pcode_id[letter]
        info = self.field_info.get(letter)
        if info is None:
            return None
        if info[0] == 'ext':
            return self.pcode_id[letter]      # sized by pre-assignment later
        if info[0] in ('raw', 'attval') or \
                (info[0] == 'att' and info[1] == 'modimm'):
            # zext marker; stub_pcode pre-assigns to a sized local
            return f"zext({self.pcode_id[letter]})"
        return None

    def stub_pcode(self):
        """B1.3 fallback: dst = op_<id>(args...) so the decompiler shows a
        call-like stub carrying the operands. Args are register varnodes
        (incl. 8-byte pair companions) and numeric fields; display-only
        attached fields (rlist, srmask, enum selectors) are skipped.
        Numeric token fields are pre-assigned to sized 4-byte locals: bare
        token fields (and zext() of them) have no resolvable size as
        callother inputs."""
        insn = self.i
        toks = fine_tokens(insn.syntax)
        aop_idx = None
        depth = 0
        for i, t in enumerate(toks):
            if t[0] == 'lit':
                if t[1] == '[':
                    depth += 1
                elif t[1] == ']':
                    depth -= 1
                elif depth == 0 and t[1] in self.STUB_ASSIGN:
                    aop_idx = i
                    break
        pre = []
        args = []
        narg = 0
        for t in toks:
            if t[0] != 'fld':
                continue
            a = self.stub_arg(t[1])
            if not a or a in args:
                continue
            if not self.pcode_isreg.get(t[1]) or a.startswith('zext('):
                # bare token fields and ext operands have no resolvable size
                # as callother inputs: pre-assign to a sized local (the
                # imm_expr pattern)
                narg += 1
                tname = f"sarg{narg}"
                pre.append(f"local {tname}:4 = {a[5:-1] if a.startswith('zext(') else a};")
                a = tname
            args.append(a)
        op = 'op_' + insn.id.replace('.', '_')
        self.s.pcodeops.add(op)
        dst = None
        dst_pair = False
        if aop_idx is not None:
            for t in reversed(toks[:aop_idx]):
                if t[0] == 'fld':
                    d = self.stub_arg(t[1])
                    if d and self.pcode_isreg.get(t[1]):
                        dst = d
                        dst_pair = self.i.fields[t[1]].kind == 'pair'
                    break
            if dst and dst in args:
                args.remove(dst)
        call = f"{op}({', '.join(args)});"
        if dst:
            # route the result through a sized temp: the callother-output
            # form is only known to compile when the target size is explicit
            sz = 8 if dst_pair else 4
            pre.append(f"local sret:{sz} = {call[:-1]};")
            pre.append(f"{dst} = sret;")
        else:
            pre.append(call)
        return ' '.join(pre)

    def add_constraints(self):
        run = None
        runs = []
        for p, ch in enumerate(self.bits):
            if ch in '01':
                if run is None:
                    run = [p, p]
                else:
                    run[1] = p
            elif run is not None:
                runs.append(tuple(run))
                run = None
        if run is not None:
            runs.append(tuple(run))
        for run in runs:
            for w, first, last in split_run_word(run):
                lo, hi = 15 - (last - 16 * w), 15 - (first - 16 * w)
                name = self.s.field(w, lo, hi, 'c')
                value = int(self.bits[first:last + 1], 2)
                self.sec_cons[w].append((name, value))

    def reg_split(self, letter, f, suffix=''):
        """Non-contiguous register field -> per-register subtable (one constructor
        per register, exporting its varnode). Returns the subtable name or None."""
        regs = VAR_LISTS[f.kind]
        pos = self.i.field_bits(letter)
        runs = contig_runs(pos)
        pieces = []
        for run in runs:
            pieces.extend(split_run_word(run))
        if len({w for w, _f, _l in pieces}) > 1:
            return None
        total = sum(last - first + 1 for _, first, last in pieces)
        if (1 << total) != len(regs):
            return None
        fnames = []
        for (w, first, last) in pieces:
            lo, hi = 15 - (last - 16 * w), 15 - (first - 16 * w)
            fnames.append(self.s.field(w, lo, hi, f"rsp_{letter}{suffix}"))
        key = ('regsplit', f.kind, letter, suffix, tuple(fnames))
        if key in self.s.subtables:
            return self.s.subtables[key][0]
        stname = f"rs{len(self.s.subtables)}"
        lines = []
        for raw in range(len(regs)):
            cons = []
            k = 0
            for (w0, first0, last0), fn in zip(pieces, fnames):
                n = last0 - first0 + 1
                chunk = (raw >> (total - k - n)) & ((1 << n) - 1)
                k += n
                cons.append(f"{fn}=0x{chunk:x}")
            lines.append(f'{stname}: "{regs[raw]}" is ' + " & ".join(cons)
                         + f" {{ export {regs[raw]}; }}")
        self.s.subtables[key] = (stname, "\n".join(lines), None)
        return stname

    def build_field(self, name, f):
        """Add pattern/ext for a normal field; return its display identifier."""
        att, pieces = self.pieces_of(name, f)
        self.pcode_isreg[name] = False
        if att is not None:
            w, first, last = pieces[0]
            self.sec_bare[w].append(att)
            vf = self.att_vf.get(att)
            if vf is not None:
                self.sec_bare[w].append(vf)
                self.pcode_id[name] = vf
                # companion of a 'pair' display field is a variable attach
                # (register varnode); modimm companions carry values
                self.pcode_isreg[name] = att in self.att_vf_reg
            else:
                self.pcode_id[name] = att
                self.pcode_isreg[name] = (f.kind in VAR_LISTS
                                          or f.kind in VAR_OF_NAME)
            self.field_info[name] = ('att', f.kind, f, w, 15 - (last - 16 * w),
                                     15 - (first - 16 * w), last - first + 1)
            return att
        if f.kind in VAR_LISTS:
            # non-contiguous register field: per-register subtable
            stname = self.reg_split(name, f)
            if stname is not None:
                self.sec_bare[pieces[0][0]].append(stname)
                self.pcode_id[name] = stname
                self.pcode_isreg[name] = True
                self.field_info[name] = ('regsplit', name)
                return stname
            self.comments.append(
                f"non-contiguous {f.kind} field '{name}' not resolvable to a register")
        fnames = self.piece_fields(pieces, f.kind, f.kind == 'simm')
        for (w, _f, _l), fn in zip(pieces, fnames):
            self.sec_bare[w].append(fn)
        self.pcode_id[name] = fnames[0]
        w = sum(last - first + 1 for _, first, last in pieces)
        if f.kind in ('uimm', 'simm') and (f.scale != 1 or f.add != 0):
            if f.zero_as is not None and w <= 12 and len(fnames) == 1:
                fname = fnames[0]
                if fname not in self.s.attach_values:
                    self.s.attach_values[fname] = [
                        f.zero_as if raw == 0 else raw * f.scale + f.add
                        for raw in range(1 << w)]
                self.field_info[name] = ('attval', fname)
                # attach values do not change p-code runtime semantics; the
                # raw field is what expressions see (cast by imm_expr)
                self.pcode_id[name] = fname
                return fname
            op = f"o_{name}"
            self.ext.append((op, num_expr(pieces, fnames, f.scale, f.add)))
            self.field_info[name] = ('ext', num_expr(pieces, fnames, f.scale, f.add))
            # pcode must use the ext temp (raw field would lose scale/add)
            self.pcode_id[name] = op
            self.pcode_isreg[name] = False
            return op
        if len(fnames) == 1:
            w0, first, last = pieces[0]
            self.field_info[name] = ('raw', w0, 15 - (last - 16 * w0),
                                     15 - (first - 16 * w0), f.kind == 'simm')
            return fnames[0]
        # non-contiguous field: combine runs (attached kinds degrade to numeric display)
        scale = f.scale if f.kind in ('uimm', 'simm') else 1
        add = f.add if f.kind in ('uimm', 'simm') else 0
        op = f"o_{name}"
        expr = num_expr(pieces, fnames, scale, add)
        self.ext.append((op, expr))
        self.field_info[name] = ('ext', expr)
        self.pcode_id[name] = op
        self.pcode_isreg[name] = False
        if f.kind not in ('uimm', 'simm', 'rmask') and not (f.kind == 'srmask' and w == 16):
            self.comments.append(f"non-contiguous {f.kind} field '{name}' shown as raw value")
        return op

    def alias(self, letter, n):
        """Display alias for the n-th repeat (1-based) of a field's operand."""
        info = self.field_info[letter]
        tag = f"_r{n}"
        if info[0] == 'regsplit':
            name = self.reg_split(letter, self.i.fields[letter], suffix=tag)
            if name is None:
                raise RuntimeError(f"{self.i.id}: regsplit alias failed for '{letter}'")
            self.sec_bare[self.word_of(letter)].append(name)
        elif info[0] == 'att':
            _, kind, f, w, lo, hi, width = info
            name = self.attached_field(kind, f, w, lo, hi, width, suffix=tag)
            self.sec_bare[w].append(name)
            vf = self.att_vf.get(name)
            if vf is not None:
                self.sec_bare[w].append(vf)
        elif info[0] == 'attval':
            fname = info[1]
            fw, lo, hi, _signed = self.s.field_defs[fname]
            name = self.s.field(fw, lo, hi, f"za{tag}")
            self.s.attach_values[name] = self.s.attach_values[fname]
            self.sec_bare[fw].append(name)
        elif info[0] == 'ext':
            name = f"o_{letter}{tag}"
            self.ext.append((name, info[1]))
            self.sec_bare[self.word_of(letter)].append(name)
        else:  # raw
            _, w, lo, hi, signed = info
            name = self.s.field(w, lo, hi, f"raw{tag}", signed)
            self.sec_bare[w].append(name)
        return name

    def word_of(self, letter):
        """The word of a field's first piece (for placing alias fields)."""
        pos = self.i.field_bits(letter)[0]
        return pos // 16

    def build_pattern(self):
        esec = getattr(self, 'ellipsis_sec', None)
        if self.spanning and esec is None:
            # dedicated subtable starting at word0: anchor + '... & btX'
            terms = [f"{n}=0x{v:x}" for n, v in self.sec_cons.get(0, [])]
            terms += self.sec_bare.get(0, [])
            if len(terms) > 1:
                return " & ".join(terms[:-1]) + " ... & " + terms[-1]
            return " & ".join(terms)
        nsec = (esec + 1) if esec is not None else self.nwords
        parts = []
        for w in range(nsec):
            terms = [f"{n}=0x{v:x}" for n, v in self.sec_cons.get(w, [])]
            terms += self.sec_bare.get(w, [])
            if not terms:
                # word fully covered by dropped fields: unconstrained wildcard operand
                name = self.s.field(w, 0, 15, 'raw')
                terms = [name]
            if esec is not None and w == esec and len(terms) > 1:
                # subtable starting at this word and spanning further tokens
                parts.append(" & ".join(terms[:-1]) + " ... & " + terms[-1])
            else:
                parts.append(" & ".join(terms))
        return " ; ".join(parts)

    # ---------------------------------------------------- branch targets ----
    def build_target(self, name, f):
        """Register a branch-target subtable for the offset field; return its name."""
        _att, pieces = self.pieces_of(name, f)
        fnames = self.piece_fields(pieces, f.kind, f.kind == 'simm')
        inv_w = min(w for w, _f, _l in pieces)
        stream = sorted(range(len(pieces)), key=lambda k: pieces[k][0])
        # dedicated subtable when the offset spans >1 word
        spanning = len({w for w, _f, _l in pieces}) > 1
        key = (tuple(pieces), tuple(fnames), f.kind == 'simm', f.scale, f.add)
        if spanning:
            key = key + (self.i.id,)     # dedicated: folded constraints differ per form
        if key in self.s.subtables:
            stname = self.s.subtables[key][0]
            self.target_st = stname
            if spanning:
                self.spanning = True
                # all root constraints move into the subtable except one anchor
                self.move_constraints_into(stname, key, pieces, fnames, inv_w)
            else:
                self.sec_bare[inv_w].append(stname)
            return stname
        stname = f"bt{len(self.s.subtables)}"
        rel = {w: w - inv_w for w, _f, _l in pieces}
        # sections of the subtable pattern (relative word order)
        secs = collections.defaultdict(list)
        for w, first, last in pieces:
            idx = pieces.index((w, first, last))
            secs[rel[w]].append(fnames[idx])
        # value-order expression
        expr = num_expr(pieces, fnames, f.scale, f.add)
        npat = self.nwords - inv_w
        sec_texts = []
        for k in range(npat):
            sec_texts.append(" & ".join(secs.get(k, [])))
        text = (f"{stname}: res is " + " ; ".join(sec_texts) + "\n"
                f"\t[ res = ({expr}) + inst_next; ]\n"
                f"\t{{ export *:4 res; }}")
        meta = (pieces, [last - first + 1 for _, first, last in pieces],
                f.scale, f.add, sum(last - first + 1 for _, first, last in pieces),
                f.kind == 'simm')
        if spanning and inv_w == 0:
            key = key + (self.i.id,)     # dedicated: folded constraints differ per form
        self.s.subtables[key] = (stname, text, meta)
        self.target_st = stname
        if spanning:
            self.spanning = True
            if inv_w == 0:
                # root: one word0 anchor + '... & btX'; the rest folds into the subtable
                self.move_constraints_into(stname, key, pieces, fnames, inv_w)
            else:
                # root keeps all its sections; the subtable starts at word inv_w
                # after an ellipsis (j3 style); distinguishing constraints stay in root
                self.ellipsis_sec = inv_w
                self.sec_bare[inv_w].append(stname)
        else:
            self.sec_bare[inv_w].append(stname)
        return stname

    def move_constraints_into(self, stname, key, pieces, fnames, inv_w):
        """Spanning form: root keeps one word0 anchor constraint + '... & btX';
        every other constraint (word0 and words >= inv_w) folds into the subtable."""
        _name, _text, meta = self.s.subtables[key]
        rel = {w: w - inv_w for w, _f, _l in pieces}
        secs = collections.defaultdict(list)
        for w, first, last in pieces:
            idx = pieces.index((w, first, last))
            secs[rel[w]].append(fnames[idx])
        anchor = None
        folded = collections.defaultdict(list)
        for w in range(self.nwords):
            for nv in self.sec_cons.get(w, []):
                if w == 0:
                    if anchor is None:
                        anchor = nv          # one word0 constraint anchors the root
                    elif inv_w == 0:
                        folded[0].append(f"{nv[0]}=0x{nv[1]:x}")
                    else:
                        raise RuntimeError(
                            f"{self.i.id}: >1 word0 constraint with inv_w={inv_w}")
                elif w < inv_w:
                    raise RuntimeError(f"{self.i.id}: constraint below inv_w={inv_w}")
                else:
                    folded[w - inv_w].append(f"{nv[0]}=0x{nv[1]:x}")
            if w >= inv_w:
                folded[w - inv_w].extend(self.sec_bare.get(w, []))
        if anchor is None:
            raise RuntimeError(f"{self.i.id}: no word0 constraint for anchor")
        npat = self.nwords - inv_w
        sec_texts = []
        for k in range(npat):
            terms = list(folded.get(k, []))
            terms += secs.get(k, [])
            sec_texts.append(" & ".join(terms))
        expr = num_expr(pieces, fnames, meta[2], meta[3])
        text = (f"{stname}: res is " + " ; ".join(sec_texts) + "\n"
                f"\t[ res = ({expr}) + inst_next; ]\n"
                f"\t{{ export *:4 res; }}")
        self.s.subtables[key] = (stname, text, meta)
        # root pattern: anchor + ellipsis + subtable
        self.sec_cons = collections.defaultdict(list)
        self.sec_bare = collections.defaultdict(list)
        self.sec_cons[0].append(anchor)
        self.sec_bare[0].append(stname)
