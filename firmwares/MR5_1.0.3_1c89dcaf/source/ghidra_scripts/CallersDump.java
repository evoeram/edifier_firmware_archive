// Dump callers of given target functions (call references).
// args: <addr file hex> <out file>
// @category JieLi
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.RefType;

public class CallersDump extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        var af = currentProgram.getAddressFactory().getDefaultAddressSpace();
        var fm = currentProgram.getFunctionManager();
        var refMgr = currentProgram.getReferenceManager();
        try (PrintWriter w = new PrintWriter(new FileWriter(args[1]));
             BufferedReader br = new BufferedReader(new FileReader(args[0]))) {
            String l;
            while ((l = br.readLine()) != null) {
                l = l.trim();
                if (l.isEmpty() || l.startsWith(";")) continue;
                Address ta = af.getAddress(new BigInteger(l, 16).longValue());
                Function tf = getFunctionAt(ta);
                w.println("===== TARGET " + (tf == null ? "?" : tf.getName()) + " @ " + ta);
                Set<Function> callers = new LinkedHashSet<>();
                ReferenceIterator it = refMgr.getReferencesTo(ta);
                int n = 0;
                while (it.hasNext()) {
                    Reference r = it.next();
                    RefType rt = r.getReferenceType();
                    if (!rt.isCall()) continue;
                    n++;
                    Function f = fm.getFunctionContaining(r.getFromAddress());
                    if (f != null) callers.add(f);
                }
                w.println("call refs: " + n + ", callers: " + callers.size());
                for (Function f : callers) {
                    w.println("  " + f.getName() + " @ " + f.getEntryPoint());
                }
                // per-site detail
                ReferenceIterator it2 = refMgr.getReferencesTo(ta);
                while (it2.hasNext()) {
                    Reference r = it2.next();
                    if (!r.getReferenceType().isCall()) continue;
                    Function f = fm.getFunctionContaining(r.getFromAddress());
                    w.println("  site " + r.getFromAddress() + " in " +
                        (f == null ? "(no-func)" : f.getName() + "@" + f.getEntryPoint()));
                }
            }
        }
        println("CallersDump done");
    }
}
