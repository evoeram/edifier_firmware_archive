#!/usr/bin/env python3
# A1: generate a full decode-only SLEIGH spec for pi32v2 from the pi32v2-isa table.
#
# Input : C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg  (isa/pi32v2.toml, 1171 confirmed forms)
# Output: source\gen\pi32v2_full.slaspec
#
# Design (see REVERSE_ENGINEERING_PLAN A1):
#   - ONE 16-bit token `instr` (little-endian, = the codec's per-word read); multi-word
#     instructions span tokens via the `;` section operator (6502/68000 style);
#   - the codec's combined value stacks 16-bit words with the FIRST word numerically
#     highest; field bit order follows field_bits (value MSB first);
#   - fixed encoding bits -> shared constraint fields c16[wN]_lo_hi = value;
#   - register/enum/etc letter fields -> shared fields + attach variables/names/values;
#   - numeric (uimm/simm) fields -> computed operands via the [] disassembly action
#     (scale/add/sign); zero_as fields -> attach values;
#   - branch/call offsets -> branch-target subtables (export *:4 res); offsets spanning
#     several words (goto.l, call.l, call.xl, gotoss.xl) use dedicated subtables with
#     `... & btX` anchoring (only form with one root constraint before the ellipsis);
#   - semantics: only for branches/calls/returns (real flow); everything else empty
#     (decode-only; p-code for the rest is a later task);
#   - non-contiguous attached fields (10 in the table) fall back to a numeric display.
#
# Self-check: every branch-target formula is evaluated in Python against codec.value
# for all examples of all branch forms.
import os
import re
import sys
import collections

HERE = os.path.dirname(os.path.abspath(__file__))
PKG = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
sys.path.insert(0, PKG)
sys.path.insert(0, HERE)
os.chdir(PKG)

from pi32v2isa.table import load, SYNTAX_TOKEN          # noqa: E402
from pi32v2isa import codec                              # noqa: E402

SRC = os.path.dirname(HERE)
OUT = os.path.join(SRC, 'gen', 'pi32v2_full.slaspec')

SR_NAMES = codec.SR_NAMES

# ---------------------------------------------------------------- helpers ----


def contig_runs(positions):
    """Positions in value-bit order -> list of (first,last) combined-MSB-position runs.

    The input order is preserved (it is the field VALUE bit order: MSB run first)."""
    runs = []
    start = prev = positions[0]
    for p in positions[1:]:
        if p == prev + 1:
            prev = p
        else:
            runs.append((start, prev))
            start = prev = p
    runs.append((start, prev))
    return runs


def split_run_word(run):
    """Split a combined-position run at 16-bit word boundaries -> [(w, first, last)]."""
    first, last = run
    out = []
    w = first // 16
    while True:
        end = min(last, (w + 1) * 16 - 1)
        out.append((w, first, end))
        if end == last:
            return out
        first = (w + 1) * 16
        w += 1


def q(s):
    """Quote a string for a SLEIGH attach-names list."""
    return '"' + s.replace('\\', '\\\\').replace('"', '\\"') + '"'


def pair_regs_names():
    """codec pair_regs display for raw 0..31 (5-bit field)."""
    out = []
    for raw in range(32):
        out.append(f"r{2 * (raw >> 2) + (raw >> 1 & 1)},r{2 * (raw >> 2) + (raw & 1)}")
    return out


def rlist4_names():
    """codec rlist4 display for raw 0..15."""
    out = []
    for raw in range(16):
        hi, lo = (3, raw) if raw < 4 else (raw, 4)
        regs = list(range(hi, lo - 1, -1))
        parts, k = [], 0
        while k < len(regs):
            j = k
            while j + 1 < len(regs) and regs[j + 1] == regs[j] - 1:
                j += 1
            if j - k >= 2:
                parts.append(f"r{regs[k]}-r{regs[j]}")
            else:
                parts += [f"r{r}" for r in regs[k:j + 1]]
            k = j + 1
        out.append(", ".join(parts))
    return out


def srmask_names(width):
    """codec srmask display for raw 0..2^width-1."""
    out = []
    for raw in range(1 << width):
        out.append(", ".join(SR_NAMES[r] for r in range(width - 1, -1, -1) if raw >> r & 1))
    return out


# ------------------------------------------------------------- registries ----

class Spec:
    """Collects token fields, attaches, subtables and constructors."""

    def __init__(self):
        self.fields = {}         # key -> name
        self.field_defs = {}     # name -> (w, lo, hi, signed)
        self.attach_vars = {}    # name -> [register names]
        self.attach_names = {}   # name -> [display strings]
        self.attach_values = {}  # name -> [ints]
        self.subtables = {}      # key -> (name, sleigh text, meta)
        self.constructors = []   # (insn, display, pattern, ext, pcode, comments)
        self.pcode_stats = collections.Counter()
        self.pcode_examples = {}
        self.pcodeops = set()    # B1.3: stub/helper pcodeop names to define

    def field(self, w, lo, hi, kind_key, signed=False):
        """Register (once) and return the name of a token field."""
        key = (w, lo, hi, kind_key, signed)
        if key in self.fields:
            return self.fields[key]
        base = f"{lo}_{hi}"
        wsuf = '' if w == 0 else f"w{w}"
        if kind_key == 'c':
            name = f"c16{wsuf}_{base}"
        elif kind_key == 'raw' or kind_key.startswith('raw_'):
            name = f"{'s' if signed else 'u'}16{wsuf}_{base}"
        else:
            name = f"{kind_key}_16{wsuf}_{base}"
        i = 2
        while name in self.field_defs:
            name = f"{name}x{i}"
            i += 1
        self.fields[key] = name
        self.field_defs[name] = (w, lo, hi, signed)
        return name

    def enum_field(self, w, lo, hi, values):
        key = ('enum', w, lo, hi, tuple(values))
        if key in self.fields:
            return self.fields[key]
        name = self.field(w, lo, hi, f"e{len(self.attach_names)}")
        self.attach_names[name] = list(values)
        return name

    def var_field(self, w, lo, hi, reglist, kind_key):
        key = ('var', w, lo, hi, kind_key)
        if key in self.fields:
            return self.fields[key]
        name = self.field(w, lo, hi, kind_key)
        self.attach_vars[name] = list(reglist)
        return name

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

    # ------------------------------------------------------- display ----
    def build_display(self, syntax, disp):
        pieces = []
        pos = 0
        for m in SYNTAX_TOKEN.finditer(syntax):
            if m.start() > pos:
                pieces.append(('lit', syntax[pos:m.start()]))
            if m.group(0) in ('{{', '}}'):
                pieces.append(('lit', m.group(0)[0]))
            else:
                pieces.append(('fld', m.group(2), m.group(1)))
            pos = m.end()
        if pos < len(syntax):
            pieces.append(('lit', syntax[pos:]))
        out = []
        counts = collections.Counter()
        for p in pieces:
            if p[0] == 'lit':
                if p[1]:
                    out.append(q(p[1]))
            else:
                letter, plus = p[1], p[2]
                counts[letter] += 1
                if plus:
                    out.append('"+"')
                ident = disp[letter] if counts[letter] == 1 else self.alias(letter, counts[letter] - 1)
                if not out:
                    # a display starting with a bare identifier is compiled by SLEIGH
                    # as literal text; an empty quoted prefix forces operand semantics
                    out.append('""')
                out.append(ident)
        return '^'.join(out)

    # ---------------------------------------------------------- semantics ----
    def build_pcode(self, targets, target_letter):
        insn = self.i
        if insn.id in ('rts', 'rte', 'rti', 'rtx'):
            reg = {'rts': 'rets', 'rte': 'rete', 'rti': 'reti', 'rtx': 'retx'}[insn.id]
            return f"return [{reg}];"
        if insn.id == 'tbb':
            x = self.pcode_id['x']
            return (f"local a_tb:4 = inst_next + {x}; local b_tb:1 = *:1 a_tb; "
                    "local w_tb:4 = zext(b_tb); local t_tb:4 = inst_next + 2 * w_tb; "
                    "goto [t_tb];")
        if insn.id == 'tbh':
            x = self.pcode_id['x']
            return (f"local a_th:4 = inst_next + {x}; local h_th:2 = *:2 (a_th & 0xfffffffe); "
                    "local w_th:4 = zext(h_th); local t_th:4 = inst_next + 2 * w_th; "
                    "goto [t_th];")
        if not targets:
            return ""
        kind = targets[-1].group(1)
        if target_letter is None:
            return ""
        tf = insn.fields[target_letter]
        if tf.kind == 'gpr':
            tref = f"[{self.pcode_id[target_letter]}]"
        else:
            tref = self.target_st
        prefix = insn.syntax[:targets[-1].start()].strip()
        if insn.syntax.startswith('ifs2ns'):
            op = '==' if insn.syntax.endswith('(c)') else '!='
            cond = f"local t_s2:4 = r0 & 1; if (t_s2 {op} 0)"
        else:
            cond = self.cond_pcode(prefix)
        if cond is None:
            return ""          # cannot express: no p-code (decode only)
        if kind == 'callns':
            cond = cond or FLAG_PROLOGUE + "local c_ns:1 = c_N ^ 1;"
            return f"{cond} if (c_ns != 0) goto inst_next; call {tref};"
        mid = f"call {tref};" if kind == 'call' else f"goto {tref};"
        if cond:
            return f"{cond} {mid}"
        return mid

    def cond_pcode(self, prefix):
        """p-code statements ending in `if (...)`; '' when unconditional; None when inexpressible."""
        if prefix == '':
            return ''
        word = prefix.split()[0] if prefix.split() else ''
        if word in FLAG_CONDS:
            return f"{FLAG_PROLOGUE}local c_fl:1 = {FLAG_CONDS[word]}; if (c_fl != 0)"
        m = re.match(r"^if([sf]?)\s*\((.+)\)$", prefix)
        if m is None:
            return None
        mode = m.group(1)
        inner = m.group(2).strip()
        return self.cond_expr(inner, mode)

    def cond_expr(self, inner, mode):
        pid = self.pcode_id
        m = re.match(r"^--\{(\w)\} != 0$", inner)
        if m:
            op = pid.get(m.group(1), f"o_{m.group(1)}")
            return f"{op} = {op} - 1; if ({op} != 0)"
        m = re.match(r"^\(\{(\w)\} & \{(\w)\}\) (!=|==) 0$", inner)
        if m:
            a, b, op = pid[m.group(1)], pid[m.group(2)], m.group(3)
            return f"if (({a} & {b}) {op} 0)"
        m = re.match(r"^\{(\w)\} \?\? \{(\w)\}$", inner)
        if m:
            def arg(letter):
                v = pid[letter]
                return v if self.pcode_isreg.get(letter) else f"{v}:4"
            return (f"local c_qq:4 = cond_unspec({arg(m.group(1))}, {arg(m.group(2))}); "
                    "if (c_qq != 0)")
        m = re.match(r"^\{(\w)\} (==|!=|u<|u<=|u>|u>=|<|<=|>|>=) (\{(\w)\}|0)$", inner)
        if m:
            a, op = pid[m.group(1)], m.group(2)
            rop = pid[m.group(4)] if m.group(4) else "0"
            opn = op.lstrip('u') if op.startswith('u') else op
            OP = {'==': '==', '!=': '!=', '<': '<', '<=': '<=', '>': '>', '>=': '>='}
            if mode == 's':
                OP.update({'<': 's<', '<=': 's<=', '>': 's>', '>=': 's>='})
            elif mode == 'f':
                if op == 'ord':
                    return (f"local c_or:1 = ({a} f<= {rop}) || ({rop} f<= {a}); "
                            "if (c_or != 0)")
                if op == 'uno':
                    return (f"local c_un:1 = ({a} f<= {rop}) || ({rop} f<= {a}); "
                            "if (c_un == 0)")
                OP.update({'==': 'f==', '!=': 'f!=', '<': 'f<', '<=': 'f<=',
                           '>': 'f>', '>=': 'f>='})
            pop = OP.get(opn, opn)
            return f"if ({a} {pop} {rop})"
        return None


# ================================================================== B1: pcode ==
# Expression compiler: translates the syntax of data-processing forms into
# SLEIGH p-code. Covered: scalar ALU (rr/ri, op-assign), loads/stores (b/h/w,
# +offset, post-inc ++=, pre-dec --, sp-relative), li, rmw, sp ops, unary
# abs/negs/not, umax/smax/umin/smin/sat8/clz. Everything else stays empty
# (dedicated TODO pcodeops in a later pass); coverage stats printed at the end.

import re as _re


class PcodeError(Exception):
    pass


_FINE_RE = _re.compile(r'''
    \s+
  | \+\+= | <<<= | >>>= | <<= | >>= | >>> | <<< | <c>= | <>=
  | == | != | <= | >= | \*= | &= | \|= | \^= | \+= | -= | -- | \+\+
  | \*\|\*\|\*\|\* | \*\|\* | \+\|\+\|\+\|\+ | \+\|\+ | \+\|- | -\|\+ | -\|-
  | >< | <> | <c> | \?\? | << | >> | && | \|\|
  | [-+*/&|^~<>=(),\[\]{};#!]
  | [a-z_][a-z0-9_.]*
  | [A-Z0-9]+
''', _re.X)

ASSIGN_TOKENS = {'=', '+=', '-=', '*=', '&=', '|=', '^=', '<<=', '>>=',
                 '>>>=', '<<<='}
UNSUPPORTED_EXPR_OPS = {'<<<', '><', '*|*', '*|*|*|*', '+|+', '+|+|+|+',
                        '+|-', '-|+', '-|-', '<>', '<c>', '??', '&&', '||',
                        '<c>=', '<>='}
MEM_PREFIX = {'b': 1, 'h': 2, 'd': 8}
FUNC_OK = {'abs', 'negs', 'umax', 'smax', 'umin', 'smin', 'sat8'}
FUNC_UNSUP = {'sum', 'all', 'any', 'cmp', 'alls', 'anys', 'cmps', 'packb',
              'ftof', 'ftoi', 'ftou', 'min', 'max', 'rnd', 'saturate'}
FUNC_CMP = {'all', 'any', 'cmp', 'alls', 'anys', 'cmps'}
CMP_OP = {'==': 'eq', '!=': 'ne', '<': 'lt', '<=': 'le', '>': 'gt', '>=': 'ge'}
VALUE_SUFFIX = {('(', 'u', ')'), ('(', 's', ')'), ('(', 'v', ')'),
                ('(', 'f', ')'), ('(', 'usat', ')'), ('(', 'ssat', ')')}
NOP_WORDS = {'nop', 'idle', 'break', 'di', 'ei', 'reti', 'rts',
             'csync', 'cli', 'sti', 'trigger', 'pfetch', 'iflush', 'flush',
             'sync', 'wait', 'idle2', 'bkpt', 'hbkpt', 'syscall',
             'sevl', 'sevg', 'wfe', 'lockclr', 'lockset', 'flushinv'}


def fine_tokens(syntax):
    """Syntax -> fine token list (literals split; placeholders expanded)."""
    out = []
    pos = 0
    for m in SYNTAX_TOKEN.finditer(syntax):
        if m.start() > pos:
            out.extend(_lit_tokens(syntax[pos:m.start()]))
        if m.group(0) in ('{{', '}}'):
            out.extend(_lit_tokens(m.group(0)))
        else:
            out.append(('fld', m.group(2), m.group(1)))
        pos = m.end()
    if pos < len(syntax):
        out.extend(_lit_tokens(syntax[pos:]))
    return out


def _lit_tokens(s):
    out = []
    for m in _FINE_RE.finditer(s):
        t = m.group(0)
        if t.strip():
            out.append(('lit', t))
    return out


class PcodeCompiler:
    """Compiles one form's syntax into p-code statements."""

    def __init__(self, ig):
        self.ig = ig
        self.insn = ig.i
        self.toks = fine_tokens(ig.i.syntax)
        self.pos = 0
        self.tmps = []
        self.lbl_n = 0
        self.flag_cin = False   # saw the c/!c carry-in literal (addc/subc)

    # ------------------------------------------------------------- helpers --
    def peek(self, k=0):
        i = self.pos + k
        return self.toks[i] if i < len(self.toks) else None

    def peek_lit(self, k=0):
        t = self.peek(k)
        return t[1] if t and t[0] == 'lit' else None

    def take(self):
        t = self.peek()
        if t:
            self.pos += 1
        return t

    def take_lit(self, s):
        t = self.peek()
        if t and t[0] == 'lit' and t[1] == s:
            self.pos += 1
            return True
        return False

    def take_fld(self):
        t = self.peek()
        if t and t[0] == 'fld':
            self.pos += 1
            return t[1], t[2]
        return None

    def tmp(self, size=4):
        self.ig.tmp_n += 1
        name = f"tpc{self.ig.tmp_n}"
        self.tmps.append((name, size))
        return name

    def new_label(self):
        self.lbl_n += 1
        return f"L{self.lbl_n}"

    def unsupported(self, why):
        raise PcodeError(why)

    def reg_of(self, letter):
        if self.ig.pcode_isreg.get(letter):
            return self.ig.pcode_id[letter]
        return None

    def field_bytes(self, letter):
        w = len(self.insn.field_bits(letter))
        return (w + 7) // 8

    def imm_expr(self, letter):
        """4-byte local holding the field's value; statements are emitted into
        self.out. SLEIGH cannot apply sext/zext to bare fields or unsized []
        temps directly, so: sized local <- field (implicit extension), then
        sext(local) for signed fields."""
        f = self.insn.fields[letter]
        v = self.ig.pcode_id[letter]
        info = self.ig.field_info.get(letter)
        if f.kind == 'simm':
            if info is not None and info[0] == 'ext':
                # []-temp: the formula already carries the sign
                t = self.tmp()
                self.out.append(f"{t} = {v};")
                return t
            t2 = self.tmp(self.field_bytes(letter))
            self.out.append(f"{t2} = {v};")
            t = self.tmp()
            self.out.append(f"{t} = sext({t2});")
            return t
        if f.kind in ('uimm', 'modimm', 'bit', 'invbit'):
            t = self.tmp()
            self.out.append(f"{t} = {v};")
            return t
        self.unsupported(f"field kind {f.kind} in expression")

    def operand_of(self, letter, plus):
        """Field as operand; '+' placeholder = signed-offset marker."""
        r = self.reg_of(letter)
        if r:
            if plus:
                self.unsupported('+ marker on register')
            return r
        e = self.imm_expr(letter)
        return e

    # ---------------------------------------------------------- mem access --
    def parse_mem(self, write=False):
        """At a memory ref: optional b/h/d prefix, '[' addr ']' with
        '+off', '++=inc', '++' (post-inc), '++r=n' (pre-inc), '--' (pre-dec).
        Returns (width, addr_expr, pre_stmts, post_stmts)."""
        width = 4
        t = self.peek()
        if t and t[0] == 'lit' and t[1] in MEM_PREFIX:
            width = MEM_PREFIX[t[1]]
            self.take()
        if not self.take_lit('['):
            self.unsupported('memory [')
        pre, post = [], []
        # pre-decrement: -- reg   ([--sp] = ...)
        if self.peek_lit() == '--':
            self.take()
            base = self.take_fld()
            if base is not None:
                r = self.reg_of(base[0])
                if not r:
                    self.unsupported('pre-dec base kind')
            elif self.peek_lit() in ('sp', 'pc'):
                r = self.take()[1]
            else:
                self.unsupported('pre-dec base')
            if not self.take_lit(']'):
                self.unsupported('pre-dec syntax')
            pre.append(f"{r} = {r} - {width};")
            return width, r, pre, post
        # pre-increment with offset: [++reg=n] (addr after adding n)
        if self.peek_lit() == '++':
            self.take()
            base = self.take_fld()
            if base is None or not self.take_lit('='):
                self.unsupported('pre-inc syntax')
            r = self.reg_of(base[0])
            if not r:
                self.unsupported('pre-inc base kind')
            off = self.take_fld()
            if off is None:
                self.unsupported('pre-inc offset')
            if not self.take_lit(']'):
                self.unsupported('pre-inc syntax')
            oe = self.reg_of(off[0]) or self.imm_expr(off[0])
            pre.append(f"{r} = {r} + {oe};")
            return width, r, pre, post
        # base operand
        base = self.take_fld()
        base_reg = None
        if base is not None:
            base_reg = self.reg_of(base[0])
            if base_reg is None:
                if self.insn.fields[base[0]].kind in ('uimm', 'simm'):
                    self.unsupported('non-register memory base')
                self.unsupported('memory base kind')
            if base[1]:
                # {+n}: '+' marker before the offset field
                pass
        else:
            if self.peek_lit() == 'sp' or self.peek_lit() == 'pc':
                base_reg = self.take()[1]
            else:
                self.unsupported('memory base')
        addr = base_reg
        # a fld directly after the base: offset with the '+' marker ([sp{+n}])
        t0 = self.peek()
        if t0 and t0[0] == 'fld':
            off = self.take_fld()
            oe = self.operand_of(*off)
            if not self.take_lit(']'):
                self.unsupported('memory syntax')
            return width, f"({addr} + {oe})", pre, post
        # connector
        nx = self.peek_lit()
        if nx == ']':
            self.take()
            return width, addr, pre, post
        if nx == '++':
            # [sp++]: post-increment by access size
            self.take()
            if not self.take_lit(']'):
                self.unsupported('post-inc syntax')
            post.append(f"{base_reg} = {base_reg} + {width};")
            return width, addr, pre, post
        if nx == '+':
            self.take()
            off = self.take_fld()
            if off is not None:
                oe = self.operand_of(*off)
                shift = ''
                if self.take_lit('<<'):
                    tn = self.take()
                    if tn is None or tn[0] != 'lit' or not tn[1].isdigit():
                        self.unsupported('index shift operand')
                    shift = f" << {tn[1]}"
                if not self.take_lit(']'):
                    self.unsupported('memory syntax')
                return width, f"({addr} + ({oe}{shift}))", pre, post
            if self.take_lit(']'):
                # [reg+]: post-increment by access size
                post.append(f"{base_reg} = {base_reg} + {width};")
                return width, addr, pre, post
            self.unsupported('memory + syntax')
        if nx == '++=':
            self.take()
            inc = self.take_fld()
            if inc is None:
                self.unsupported('post-inc operand')
            if not self.take_lit(']'):
                self.unsupported('post-inc syntax')
            ie = self.reg_of(inc[0]) or self.imm_expr(inc[0])
            post.append(f"{base_reg} = {base_reg} + {ie};")
            return width, addr, pre, post
        if nx == '<<':
            self.take()
            sh = self.take_fld()
            if sh is None:
                self.unsupported('index shift')
            if not self.take_lit(']'):
                self.unsupported('indexed memory')
            if self.insn.fields[sh[0]].kind not in ('uimm', 'simm'):
                self.unsupported('index shift kind')
            oe = self.operand_of(*sh)
            addr = f"({addr} + ({oe} << 2))"
            return width, addr, pre, post
        self.unsupported(f"memory connector {nx!r}")

    # ------------------------------------------------------------ primaries --
    def parse_primary(self):
        t = self.peek()
        if t is None:
            self.unsupported('unexpected end')
        if t[0] == 'fld':
            self.take()
            v = self.operand_of(t[1], t[2])
            # register selector suffix: {s}.h (high half for h-stores)
            if self.peek_lit() == '.' and self.peek_lit(1) == 'h':
                self.take()
                self.take()
                return f"{v}(2)"
            return v
        lit = t[1]
        if lit in ('sp', 'pc', 'cc') or lit in SR_NAMES:
            self.take()
            if lit == 'cc':
                return 'psr'          # condition codes live in psr
            if lit == 'pc':
                self.unsupported('pc in data expression')
            return lit
        if lit == '~':
            self.take()
            return f"(~{self.parse_primary()})"
        if lit.isdigit():
            self.take()
            return f"{lit}:4"
        if lit == '(':
            self.take()
            v = self.parse_expr()
            if not self.take_lit(')'):
                self.unsupported('paren')
            return v
        if lit in ('[', 'b', 'h', 'd') and self.peek_lit(1) == '[':
            width, addr, pre, post = self.parse_mem()
            self.out.extend(pre)
            # value suffix (u)/(s)/... may follow
            cast = 'zext'
            if width != 4:
                suffix = tuple(x[1] for x in self.toks[self.pos:self.pos + 3]
                               if x[0] == 'lit')
                if suffix in VALUE_SUFFIX:
                    for _ in suffix:
                        self.take()
                    cast = 'zext' if 'u' in suffix else 'sext'
            tm = self.tmp(width)
            self.out.append(f"{tm} = *:{width} {addr};")
            for u in post:
                self.out.append(u)
            if width in (4, 8):
                return tm
            return f"{cast}({tm})"
        if lit == '[':
            width, addr, pre, post = self.parse_mem()
            self.out.extend(pre)
            tm = self.tmp(4)
            self.out.append(f"{tm} = *:4 {addr};")
            for u in post:
                self.out.append(u)
            return tm
        if lit in FUNC_OK or lit in FUNC_UNSUP:
            self.take()
            if lit in FUNC_CMP:
                return self.parse_lane_cmp(lit)
            if not self.take_lit('('):
                self.unsupported('call paren')
            args = [self.parse_expr()]
            while self.take_lit(','):
                args.append(self.parse_expr())
            if not self.take_lit(')'):
                self.unsupported('call close')
            self.drop_value_suffix()
            if lit not in FUNC_OK:
                # B1.3: helper pcodeop with a result temp
                self.ig.s.pcodeops.add(lit)
                tm = self.tmp()
                self.out.append(f"{tm} = {lit}({', '.join(args)});")
                return tm
            if lit == 'abs':
                tm = self.tmp()
                l1 = self.new_label()
                self.out.append(f"{tm} = {args[0]};")
                self.out.append(f"if ({tm} s>= 0) goto <{l1}>; {tm} = -{tm}; <{l1}>")
                return tm
            if lit == 'negs':
                tm = self.tmp()
                self.out.append(f"{tm} = -{args[0]};")
                return tm
            if lit in ('umax', 'smax', 'umin', 'smin'):
                tm = self.tmp()
                nop = {'umax': '<=', 'smax': 's<=', 'umin': '>=', 'smin': 's>='}[lit]
                l1 = self.new_label()
                self.out.append(f"{tm} = {args[0]};")
                self.out.append(
                    f"if ({args[1]} {nop} {tm}) goto <{l1}>; {tm} = {args[1]}; <{l1}>")
                return tm
            if lit == 'sat8':
                tm = self.tmp()
                l1 = self.new_label()
                l2 = self.new_label()
                self.out.append(f"{tm} = {args[0]};")
                self.out.append(
                    f"if ({tm} s<= 0xff:4) goto <{l1}>; {tm} = 0xff:4; <{l1}>")
                self.out.append(
                    f"if ({tm} s>= 0:4) goto <{l2}>; {tm} = 0:4; <{l2}>")
                return tm
        # B1.3: any other identifier function (clz, popcnt, fmin, itof, rev8,
        # align8, sat16, ...) becomes a helper pcodeop with a result temp
        if _re.fullmatch(r"[a-z_][a-z0-9_.]*", lit) \
                and self.peek_lit(1) == '(':
            self.take()
            self.take()
            args = [self.parse_expr()]
            while self.take_lit(','):
                args.append(self.parse_expr())
            if not self.take_lit(')'):
                self.unsupported('gen-func close')
            self.drop_value_suffix()
            self.ig.s.pcodeops.add(lit)
            tm = self.tmp()
            self.out.append(f"{tm} = {lit}({', '.join(args)});")
            return tm
        if lit == 'c':                  # carry flag as an operand (addc)
            self.take()
            self.flag_cin = True
            tm = self.tmp()
            self.out.append(f"{tm} = zext(psr[1,1]);")
            return tm
        if lit == '!':
            self.take()
            if not self.take_lit('c'):
                self.unsupported("'!' without 'c'")
            self.flag_cin = True
            tm = self.tmp()
            self.out.append(f"{tm} = zext((psr[1,1]) == 0);")
            return tm
        self.unsupported(f"primary {lit!r}")

    def parse_lane_cmp(self, lit):
        """{r} = all/any/cmp[s]({s} OP {t}) — lane compares as helper pcodeops
        named <func>_<op> (eq/ne/lt/le/gt/ge); the lane width stays in the
        form id (v/r suffixes)."""
        if not self.take_lit('('):
            self.unsupported('cmp paren')
        a = self.parse_expr()
        op = self.peek_lit()
        if op not in CMP_OP:
            self.unsupported(f'lane cmp op {op!r}')
        self.take()
        b = self.parse_expr()
        if not self.take_lit(')'):
            self.unsupported('cmp close')
        self.drop_value_suffix()
        name = f"{lit}_{CMP_OP[op]}"
        self.ig.s.pcodeops.add(name)
        tm = self.tmp()
        self.out.append(f"{tm} = {name}({a}, {b});")
        return tm

    def drop_value_suffix(self):
        while True:
            suffix = tuple(x[1] for x in self.toks[self.pos:self.pos + 3]
                           if x[0] == 'lit')
            if suffix in VALUE_SUFFIX:
                for _ in range(3):
                    self.take()
            else:
                return

    # ---------------------------------------------------------- expressions --
    LEVELS = [
        ('|', '^'),
        ('&',),
        ('<<', '>>', '>>>', '<<<', '><'),
        ('+', '-'),
        ('*', '/'),
    ]

    def parse_expr(self, level=0):
        if level >= len(self.LEVELS):
            return self.parse_primary()
        v = self.parse_expr(level + 1)
        while True:
            t = self.peek_lit()
            if t in self.LEVELS[level]:
                if t in ('<<<', '><'):
                    self.unsupported(f"operator {t!r}")
                self.take()
                r = self.parse_expr(level + 1)
                op = 's>>' if t == '>>>' else t
                v = f"({v} {op} {r})"
            elif t in UNSUPPORTED_EXPR_OPS and t in self.op_level(level):
                self.unsupported(f"operator {t!r}")
            else:
                return v

    @staticmethod
    def op_level(level):
        return set()

    # ------------------------------------------------------------ flags B1.2 --
    # Flag model from pi32v2-isa docs/COMPILER.md (hardware-verified).
    # psr bits: N=3, Z=2, C=1 (sub: 1 = no borrow), V=0 (signed overflow).
    # Only the add/sub families write flags that this firmware reads back
    # (rN = psr sites: 64-bit compares); logic/shift flags are dead here and
    # would only add noise (bc.* branches never occur in MR5).
    def flag_nzcv(self):
        fid = self.insn.id
        if 'brev' in fid:
            return None
        fam = fid.split('.')[0]
        return 'nzcv' if fam in ('add', 'sub', 'rsub', 'addc', 'subc') else None

    def _psr_set(self, res, c=None, v=None):
        """psr = keep upper bits; N,Z from res; optional C,V (1-byte bools)."""
        parts = [f"(psr & 0xfffffff0:4)",
                 f"(zext({res} s< 0) << 3)",
                 f"(zext({res} == 0) << 2)"]
        if c is not None:
            parts.append(f"(zext({c}) << 1)")
        if v is not None:
            parts.append(f"zext({v})")
        self.out.append(f"psr = {' | '.join(parts)};")

    def emit_flag_nzcv(self, r, a, b, op):
        """Append flag statements for dst=r (already assigned), operands a,b
        (pre-assignment values; the caller captures aliased values). op is
        '+' or '-'."""
        carry = self.flag_cin
        if op == '+':
            if carry:
                t = self.tmp(); be = self.tmp()
                c1 = self.tmp(1); c2 = self.tmp(1); fc = self.tmp(1)
                fv = self.tmp(1)
                self.out.append(f"{t} = {a} + {b};")
                self.out.append(f"{c1} = {t} < {a};")
                self.out.append(f"{be} = {b} + zext(psr[1,1]);")
                self.out.append(f"{c2} = {r} < {t};")
                self.out.append(f"{fc} = {c1} | {c2};")
                self.out.append(f"{fv} = (({a} ^ {be}) & ({a} ^ {r})) s< 0;")
                self._psr_set(r, c=fc, v=fv)
            else:
                fc = self.tmp(1); fv = self.tmp(1)
                self.out.append(f"{fc} = {r} < {a};")
                self.out.append(f"{fv} = (({a} ^ {r}) & ({b} ^ {r})) s< 0;")
                self._psr_set(r, c=fc, v=fv)
        else:  # '-'
            if carry:
                ci = self.tmp(1); nb = self.tmp(); be = self.tmp()
                t = self.tmp(); b1 = self.tmp(1); b2 = self.tmp(1)
                fc = self.tmp(1); fv = self.tmp(1)
                self.out.append(f"{ci} = psr[1,1];")
                self.out.append(f"{nb} = zext({ci} == 0);")
                self.out.append(f"{be} = {b} + {nb};")
                self.out.append(f"{t} = {a} - {b};")
                self.out.append(f"{b1} = {a} < {b};")
                self.out.append(f"{b2} = ({t} == 0) & ({ci} == 0);")
                self.out.append(f"{fc} = ({b1} | {b2}) == 0;")
                self.out.append(f"{fv} = (({a} ^ {be}) & ({a} ^ {r})) s< 0;")
                self._psr_set(r, c=fc, v=fv)
            else:
                fc = self.tmp(1); fv = self.tmp(1)
                self.out.append(f"{fc} = zext({a} >= {b});")
                self.out.append(f"{fv} = (({a} ^ {b}) & ({a} ^ {r})) s< 0;")
                self._psr_set(r, c=fc, v=fv)

    # ------------------------------------------------------------ pair guard --
    # B1.3: 3-bit pair fields now resolve to 8-byte varnodes, but the
    # expression compiler does not widen operands, so only forms whose
    # semantics survive same-size evaluation get the real path; every other
    # pair form falls back to a pcodeop stub.
    PAIR_REAL = ('mov.pair', 'li.zero_pair', 'ld.d', 'st.d')

    def pair_guard(self):
        fid = self.insn.id
        if fid.startswith(self.PAIR_REAL):
            return
        for f in self.insn.fields.values():
            if f.kind in ('pair', 'pair_regs'):
                self.unsupported('pair operands (stub)')

    # ------------------------------------------------------------ statement --
    def finish(self, extra=None):
        """Assemble declarations + emitted statements (+ extra) into the block."""
        stmts = list(self.out)
        if extra:
            stmts.extend(extra)
        decls = " ".join(f"local {n}:{s} = 0:{s};" for n, s in self.tmps)
        return " ".join([decls] + stmts) if decls else " ".join(stmts)

    def compile(self):
        self.out = []
        self.ig.tmp_n = 0
        self.flag_cin = False
        self.pair_guard()
        self.strip_tail()
        first = self.peek()
        if first is None:
            return ''
        if first[0] == 'lit':
            w = first[1]
            if w in ('rep',):
                args = []
                for t in self.toks[1:]:
                    if t[0] == 'fld':
                        args.append(self.operand_of(*t[1], t[2]))
                self.pos = len(self.toks)
                self.out.append(
                    f"rep_unspec({', '.join(args) if args else '0'});")
                return self.finish()
            if w == 'swi':
                self.pos = len(self.toks)
                return "swi_unspec();"
            if w == 'testset':
                # testset b[x]: atomic test-and-set (precise semantics unknown)
                self.take()
                width, addr, pre, post = self.parse_mem()
                self.pos = len(self.toks)
                pre.append(f"testset_unspec(*:1 {addr});")
                return self.finish(pre)
            if w in NOP_WORDS:
                self.pos = len(self.toks)
                return ''
            if w in ('if', 'ifs', 'iff', 'ifs2ns', 'call', 'goto', 'callns'):
                return None           # handled by the branch/call generator
        # find the assignment token (skip tokens inside [ ])
        aop_idx = None
        aop = None
        depth = 0
        for i, t in enumerate(self.toks):
            if t[0] == 'lit':
                if t[1] == '[':
                    depth += 1
                elif t[1] == ']':
                    depth -= 1
                elif depth == 0 and t[1] in ASSIGN_TOKENS:
                    aop = t[1]
                    aop_idx = i
                    break
        if aop is None:
            self.unsupported('no assignment')
        dst = self.parse_lvalue(self.toks[:aop_idx])
        self.toks = self.toks[aop_idx + 1:]
        self.pos = 0
        self.drop_value_suffix()
        if self.peek() is None:
            self.unsupported('empty rhs')
        rhs = self.parse_expr()
        if self.pos != len(self.toks):
            rest = [x[1] if x[0] == 'lit' else '{f}'
                    for x in self.toks[self.pos:]]
            self.unsupported(f"trailing tokens {rest!r}")
        aarith = {'+=': '+', '-=': '-', '*=': '*', '&=': '&', '|=': '|',
                  '^=': '^', '<<=': '<<', '>>=': '>>', '>>>=': 's>>'}.get(aop)
        if aop == '<<<=':
            # saturating shift: no plain p-code equivalent — stub, not copy
            self.unsupported('saturating shift (stub)')
        if dst[0] == 'reg':
            r = dst[1]
            fk = self.flag_nzcv()
            fa = fb = op2 = None
            if fk and aarith in ('+', '-'):
                fa = self.tmp()               # old dst: the '+=' operand
                self.out.append(f"{fa} = {r};")
            elif fk and aarith is None:
                m = _re.fullmatch(r"\((\w+) ([+-]) (\w+)\)", rhs)
                if m:
                    fa, op2, fb = m.group(1), m.group(2), m.group(3)
                elif self.flag_cin:
                    # carry form: ((a - b) - tpc1) / ((a + b) + tpc1)
                    m2 = _re.fullmatch(
                        r"\(\((\w+) ([+-]) (\w+)\) [+-] \w+\)", rhs)
                    if m2:
                        fa, op2, fb = m2.group(1), m2.group(2), m2.group(3)
                if fa is not None:
                    if fa == r:               # dst on the rhs: capture pre-value
                        old = self.tmp()
                        self.out.append(f"{old} = {r};")
                        fa = old
                    if fb == r:
                        oldb = self.tmp()
                        self.out.append(f"{oldb} = {r};")
                        fb = oldb
            if aarith is None:
                if rhs == '0:4' and self.insn.id.startswith('li.zero_pair'):
                    rhs = '0:8'          # li.zero_pair: clear the full pair
                self.out.append(f"{r} = {rhs};")
            else:
                self.out.append(f"{r} = {r} {aarith} {rhs};")
            if fk:
                if aarith in ('+', '-'):
                    self.emit_flag_nzcv(r, fa, rhs, aarith)
                elif aarith is None and fa is not None:
                    self.emit_flag_nzcv(r, fa, fb, op2)
        elif dst[0] == 'mem':
            addr, width, pre, post = dst[1], dst[2], dst[3], dst[4]
            self.out.extend(pre)
            if width == 4:
                if aarith is None:
                    self.out.append(f"*:4 {addr} = {rhs};")
                else:
                    tm = self.tmp()
                    self.out.append(f"{tm} = (*:4 {addr}) {aarith} {rhs};")
                    self.out.append(f"*:4 {addr} = {tm};")
            else:
                tm = self.tmp(width)
                rexpr = (rhs if _re.fullmatch(r"[A-Za-z0-9_]+", rhs)
                         else f"({rhs})")
                cast = '' if (width == 8 and
                              _re.fullmatch(r"[A-Za-z0-9_]+", rhs)) \
                    else f":{width}"
                self.out.append(f"{tm} = {rexpr}{cast};")
                self.out.append(f"*:{width} {addr} = {tm};")
            self.out.extend(post)
        else:
            self.unsupported('lvalue')
        return self.finish()

    def strip_tail(self):
        """Drop trailing parallel markers and value suffixes."""
        while self.toks:
            t = self.toks[-1]
            if t[0] == 'lit' and t[1] == '#':
                self.toks.pop()
                continue
            if len(self.toks) >= 3:
                tail = tuple(x[1] for x in self.toks[-3:] if x[0] == 'lit')
                if tail in VALUE_SUFFIX:
                    del self.toks[-3:]
                    continue
            break

    def parse_lvalue(self, lvals):
        if not lvals:
            self.unsupported('empty lvalue')
        if len(lvals) == 1 and lvals[0][0] == 'fld':
            letter, plus = lvals[0][1], lvals[0][2]
            r = self.reg_of(letter)
            if r:
                if plus:
                    self.unsupported('+ marker on lvalue')
                return ('reg', r)
            self.unsupported('lvalue field kind')
        if len(lvals) == 1 and lvals[0][0] == 'lit' and lvals[0][1] in ('sp', 'pc'):
            return ('reg', lvals[0][1])
        if len(lvals) == 1 and lvals[0][0] == 'lit':
            if lvals[0][1] == 'cc':
                return ('reg', 'psr')
            if lvals[0][1] in SR_NAMES:
                return ('reg', lvals[0][1])
        # memory lvalue: run the memory parser over the slice
        saved_toks, saved_pos, saved_out = self.toks, self.pos, list(self.out)
        self.toks = lvals
        self.pos = 0
        self.out = []
        try:
            mem = self.parse_mem()
            if self.pos != len(lvals):
                self.unsupported('lvalue trailing')
        finally:
            pre = list(self.out)
            self.toks, self.pos, self.out = saved_toks, saved_pos, saved_out
        if mem is None:
            self.unsupported('lvalue memory')
        width, addr, mpre, mpost = mem
        return ('mem', addr, width, pre + mpre, mpost)


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
