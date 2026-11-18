// Decompile all functions listed in an address file (one hex addr per line).
// @category JieLi
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompOverlay extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String addrFile = args[0];
        String outFile = args.length > 1
                ? args[1] : "C:\\Users\\User\\AppData\\Local\\Temp\\opencode\\decomp_overlay.c";
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int ok = 0, fail = 0;
        try (PrintWriter w = new PrintWriter(new FileWriter(outFile));
             BufferedReader br = new BufferedReader(new FileReader(addrFile))) {
            String l;
            while ((l = br.readLine()) != null) {
                l = l.trim();
                if (l.isEmpty() || l.startsWith(";")) {
                    continue;
                }
                Address a = currentProgram.getAddressFactory()
                        .getDefaultAddressSpace()
                        .getAddress(new BigInteger(l, 16).longValue());
                Function f = a == null ? null : getFunctionAt(a);
                if (f == null) {
                    f = a == null ? null
                            : currentProgram.getFunctionManager()
                                    .getFunctionContaining(a);
                }
                w.println("// ===== " + (f == null ? "?" : f.getName())
                        + " @ " + l);
                if (f == null) {
                    w.println("// no function");
                    fail++;
                    continue;
                }
                DecompileResults res = di.decompileFunction(f, 60, monitor);
                if (res.decompileCompleted()) {
                    w.println(res.getDecompiledFunction().getC());
                    ok++;
                } else {
                    w.println("// decompile FAILED: " + res.getErrorMessage());
                    fail++;
                }
            }
        }
        println("DecompOverlay: ok=" + ok + " fail=" + fail + " -> " + outFile);
    }
}
