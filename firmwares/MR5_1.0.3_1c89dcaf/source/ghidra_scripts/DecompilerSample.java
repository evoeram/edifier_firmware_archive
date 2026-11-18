// Decompile a few known functions to check B1 p-code quality.
// @category JieLi
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompilerSample extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String[] addrs = args.length > 0 ? args[0].split(",") :
            new String[] {"06002224", "0600a278", "06007d8c", "0600a5b6"};
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        try (PrintWriter w = new PrintWriter(new FileWriter(
                "C:\\Users\\User\\AppData\\Local\\Temp\\opencode\\decomp_sample.c"))) {
            for (String a : addrs) {
                Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace()
                        .getAddress(new BigInteger(a, 16).longValue());
                Function f = getFunctionAt(addr);
                if (f == null) {
                    f = currentProgram.getFunctionManager().getFunctionContaining(addr);
                }
                if (f == null) {
                    w.println("// no function at " + a);
                    continue;
                }
                DecompileResults res = di.decompileFunction(f, 60, monitor);
                w.println("// ===== " + f.getName() + " @ " + a);
                if (res.decompileCompleted()) {
                    w.println(res.getDecompiledFunction().getC());
                } else {
                    w.println("// decompile FAILED: " + res.getErrorMessage());
                }
            }
        }
        di.dispose();
        println("decompiler sample written");
    }
}
