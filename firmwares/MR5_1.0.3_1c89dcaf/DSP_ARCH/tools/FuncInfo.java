import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class FuncInfo extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(args[0]));
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            String n = f.getName();
            if (n.startsWith("f_eq") || n.startsWith("dut") || n.startsWith("f_tst") ||
                n.startsWith("f_dut") || n.contains("eq_media") || n.startsWith("f_iis0") ||
                n.startsWith("f_mixer") || n.startsWith("FUN_0600b1") || n.startsWith("FUN_0600b2")) {
                w.println(n + " @ " + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
            }
        }
        // callers of f_eq_media / f_tst_btn_sta
        String[] targets = args.length > 1 ? new String[]{args[1]} : new String[0];
        w.close();
    }
}
