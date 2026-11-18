// Add hidden-function starts (recovered from mov32 sweep, see B2/A3-prep)
// into the current program: disassemble, create function, bookmark+comment.
// @category JieLi
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class AddHiddenFuncs extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String path = args.length > 0 ? args[0] : "hidden_funcs.txt";
        String category = args.length > 1 ? args[1] : "hidden-func-B2";

        List<String> lines = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String l;
            while ((l = br.readLine()) != null) {
                l = l.trim();
                if (!l.isEmpty() && !l.startsWith(";")) {
                    lines.add(l);
                }
            }
        }

        int created = 0, exists = 0, failed = 0;
        int txid = currentProgram.startTransaction("Add hidden funcs from B2 sweep");
        try {
            for (String l : lines) {
                Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(l.split("\\s+")[0]);
                if (addr == null) {
                    failed++;
                    continue;
                }
                if (getFunctionAt(addr) != null) {
                    exists++;
                    continue;
                }
                try {
                    new DisassembleCommand(addr, null, true).applyTo(currentProgram, monitor);
                } catch (Exception e) {
                    // partial language may not decode; still record the start
                }
                boolean ok = new CreateFunctionCmd(addr).applyTo(currentProgram, monitor);
                Function fn = getFunctionAt(addr);
                if (ok && fn != null) {
                    created++;
                } else {
                    failed++;
                }
                currentProgram.getBookmarkManager().setBookmark(addr, "Note", category, l);
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }

        println("AddHiddenFuncs: total=" + lines.size() + " created=" + created
                + " already=" + exists + " failed=" + failed);
        println("program: " + currentProgram.getName() + " @ base " + currentProgram.getImageBase());
    }
}
