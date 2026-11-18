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
