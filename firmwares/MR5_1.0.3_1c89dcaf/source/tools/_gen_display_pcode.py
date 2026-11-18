
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
