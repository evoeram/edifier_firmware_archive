# Add hidden-function starts (recovered from mov32 sweep, see B2/A3-prep)
# into the current program: disassemble, create function, bookmark+comment.
# @category JieLi
# @runtime Jython
import os

from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.app.cmd.disassemble import DisassembleCommand

prog = currentProgram
fm = prog.getFunctionManager()
af = prog.getAddressFactory().getDefaultAddressSpace()
listing = prog.getListing()
bm = prog.getBookmarkManager()

args = getScriptArgs()
path = args[0] if args else 'hidden_funcs.txt'

lines = []
for l in open(path, encoding='utf-8', errors='replace'):
    l = l.strip()
    if l and not l.startswith(';'):
        lines.append(l)

created = exists = failed = 0
txid = prog.startTransaction('Add hidden funcs from B2 sweep')
try:
    for l in lines:
        addr = af.getAddress(l.split()[0])
        if addr is None:
            failed += 1
            continue
        if fm.getFunctionAt(addr) is not None:
            exists += 1
            continue
        try:
            cmd = DisassembleCommand(addr, None, True)
            cmd.applyTo(prog, monitor)
        except Exception:
            pass
        ok = CreateFunctionCmd(addr).applyTo(prog, monitor)
        fn = fm.getFunctionAt(addr)
        if ok and fn is not None:
            created += 1
        else:
            failed += 1
        bm.setBookmark(addr, 'Note', 'hidden-func-B2', l[:200])
finally:
    prog.endTransaction(txid, True)

print('AddHiddenFuncs: total=%d created=%d already=%d failed=%d'
      % (len(lines), created, exists, failed))
print('program: %s @ base %s' % (prog.getName(), prog.getImageBase()))
