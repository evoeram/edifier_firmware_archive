

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
