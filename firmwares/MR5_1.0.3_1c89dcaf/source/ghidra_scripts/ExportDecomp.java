// Decompile every function to a single C dump for archival in source/.
// 3222 functions — takes a while; progress printed every 500 functions.
// @category JieLi
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportDecomp extends GhidraScript {

    @Override
    public void run() throws Exception {
        String out = "C:\\dev\\edifier_firmware_archive\\firmwares\\MR5_1.0.3_1c89dcaf\\source\\ghidra_export\\mr5_decomp_all.c";
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int ok = 0, fail = 0, n = 0;
        try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext()) {
                Function f = it.next();
                n++;
                w.println("// ===== " + f.getName() + " @ " + f.getEntryPoint()
                        + " (size " + f.getBody().getNumAddresses() + ")");
                DecompileResults res = di.decompileFunction(f, 60, monitor);
                if (res != null && res.decompileCompleted()) {
                    w.println(res.getDecompiledFunction().getC());
                    ok++;
                } else {
                    w.println("// decompile FAILED: "
                            + (res == null ? "null" : res.getErrorMessage()));
                    fail++;
                }
                if (n % 500 == 0) {
                    println("decompiled " + n);
                }
            }
        }
        di.dispose();
        println("decomp export done: " + ok + " ok, " + fail + " failed, " + n + " total");
    }
}
