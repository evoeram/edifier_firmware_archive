#!/usr/bin/env python3
# Recursive-descent disassembler for pi32v2 raw code (MR5 app.bin),
# built on jvitkauskas/pi32v2-isa hardware-validated instruction table.
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from pi32v2isa import codec
from pi32v2isa.table import load
from pi32v2isa.objdump import decoder_for, BRANCH_FIELD

BASE = 0x06000100

def disasm(path, outpath, entry_off):
    tab = load()
    dec = decoder_for(tab)
    data = open(path, 'rb').read()

    decoded = {}        # addr(file off) -> (text, length, is_branch_target_info)
    func_starts = set()
    work = [entry_off]
    seen = set()
    undecoded = []

    while work:
        off = work.pop()
        while off is not None and off not in seen:
            seen.add(off)
            got = dec.decode(data, off)
            if got is None:
                undecoded.append(off)
                break
            insn, values, size, text = got
            decoded[off] = (text, size, insn.id)
            nxt = off + size
            # branch/call targets
            m = BRANCH_FIELD.search(insn.syntax)
            if m:
                letter = m.group(1)
                field = insn.fields[letter]
                v = codec.value(field, values[letter], len(insn.field_bits(letter)))
                target = ((BASE + off) + size + v) & ~1 & 0xFFFFFFFF
                toff = target - BASE
                if insn.id.startswith('call'):
                    func_starts.add(toff)
                if 0 <= toff < len(data):
                    work.append(toff)
            if insn.id in ('rets', 'retx', 'jtl', 'rte', 'rtei'):
                break
            off = nxt
            if off >= len(data):
                break

    # function starts that were never reached/decoded
    with open(outpath, 'w', encoding='utf-8', errors='replace') as out:
        out.write(f'; pi32v2 recursive-disassembly of {path}\n')
        out.write(f'; base {BASE:#x}, entry {BASE+entry_off:#x}\n')
        out.write(f'; decoded {len(decoded)} instructions, {len(func_starts)} call targets\n\n')
        addrs = sorted(decoded)
        # group functions: a new function at each call target
        for a in addrs:
            if a in func_starts:
                out.write(f'\n{name_of(a)}:\n')
            text, size, iid = decoded[a]
            out.write(f'{BASE+a:08x}: {data[a:a+size].hex(" "):<20} {text}\n')
        out.write(f'\n; undecoded starts: {len(undecoded)}\n')
    print(f'decoded {len(decoded)} instrs, funcs={len(func_starts)}, undecoded={len(undecoded)}')
    return decoded, func_starts, undecoded

def name_of(a):
    return f'sub_{BASE+a:08x}'

if __name__ == '__main__':
    pkg = r'C:\Users\User\AppData\Local\Temp\opencode\pi32v2isa_pkg'
    os.chdir(pkg)
    app = sys.argv[1] if len(sys.argv) > 1 else r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\app.bin'
    out = sys.argv[2] if len(sys.argv) > 2 else r'C:\Users\User\AppData\Local\Temp\opencode\mr5_disasm.txt'
    d, f, u = disasm(app, out, entry_off=2)
    # coverage stats
    total = len(d)
    print('coverage sample: first undecoded offsets:', [hex(x) for x in u[:10]])
