# Dump functions + disassembly listing + strings from current program.
# @category Analysis
import os

prog = currentProgram
listing = prog.getListing()
fm = prog.getFunctionManager()
af = prog.getAddressFactory().getDefaultAddressSpace()

args = getScriptArgs()
outpath = args[0] if args else os.path.join(os.environ['TEMP'], 'ghidra_listing.txt')

out = open(outpath, 'w', encoding='utf-8', errors='replace')

# strings
out.write('==== STRINGS ====\n')
for data in listing.getDefinedData(True):
    dt = data.getDataType().getName().lower()
    if 'string' in dt or 'char' in dt:
        v = data.getValue()
        if v:
            out.write('%s  %r\n' % (data.getAddress(), str(v)))

out.write('\n==== FUNCTIONS ====\n')
funcs = sorted(fm.getFunctions(True), key=lambda f: f.getBody().getNumAddresses(), reverse=True)
out.write('total functions: %d\n' % len(funcs))
for f in funcs:
    out.write('%s  size=%d  %s\n' % (f.getEntryPoint(), f.getBody().getNumAddresses(), f.getName()))

out.write('\n==== LISTING ====\n')
func_by_entry = {}
for f in fm.getFunctions(True):
    func_by_entry.setdefault(f.getEntryPoint(), []).append(f)

refmgr = prog.getReferenceManager()
for instr in listing.getInstructions(True):
    a = instr.getAddress()
    fs = func_by_entry.get(a)
    if fs:
        for f in fs:
            out.write('\n--- FUNCTION %s @ %s ---\n' % (f.getName(), a))
    outs = []
    for ref in refmgr.getReferencesFrom(a):
        outs.append(str(ref.getToAddress()))
    lbl = listing.getLabelAt(a)
    extra = (' ' + lbl.getName()) if lbl else ''
    out.write('%s  %-24s %s%s\n' % (a, instr, ('; -> ' + ','.join(outs)) if outs else '', extra))

out.close()
print('Dumped to ' + outpath)
print('Functions: %d' % len(funcs))
