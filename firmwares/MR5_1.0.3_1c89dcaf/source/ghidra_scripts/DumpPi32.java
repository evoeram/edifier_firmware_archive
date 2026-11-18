import ghidra.app.script.GhidraScript;
import ghidra.program.flatapi.FlatProgramAPI;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

public class DumpPi32 extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outpath = args.length > 0 ? args[0] : "listing.txt";

        Program prog = currentProgram;
        Listing listing = prog.getListing();
        FlatProgramAPI flat = new FlatProgramAPI(prog);

        long nInstr = 0;
        for (Instruction i : listing.getInstructions(true)) { nInstr++; }

        if (nInstr < 100) {
            println("Few instructions (" + nInstr + "), disassembling from entry...");
            Address base = prog.getAddressFactory().getDefaultAddressSpace().getAddress(0x06000100L);
            flat.disassemble(base);
            flat.createFunction(base, "entry");
            analyzeAll(prog);
        }

        PrintWriter out = new PrintWriter(new FileWriter(outpath));

        out.println("==== FUNCTIONS ====");
        FunctionManager fm = prog.getFunctionManager();
        List<Function> funcs = new ArrayList<>();
        for (Function f : fm.getFunctions(true)) funcs.add(f);
        funcs.sort((a, b) -> Long.compare(b.getBody().getNumAddresses(), a.getBody().getNumAddresses()));
        out.println("total functions: " + funcs.size());
        for (Function f : funcs) {
            out.printf("%s  size=%d  %s%n", f.getEntryPoint(), f.getBody().getNumAddresses(), f.getName());
        }

        out.println();
        out.println("==== STRINGS ====");
        for (Data d : listing.getDefinedData(true)) {
            Object v = d.getValue();
            if (v instanceof String s && s.length() >= 4) {
                out.printf("%s  \"%s\"%n", d.getAddress(), s.replace("\n", "\\n"));
            }
        }

        out.println();
        out.println("==== LISTING ====");
        TreeMap<Long, List<Function>> byEntry = new TreeMap<>();
        for (Function f : fm.getFunctions(true)) {
            byEntry.computeIfAbsent(f.getEntryPoint().getOffset(), k -> new ArrayList<>()).add(f);
        }

        for (Instruction ins : listing.getInstructions(true)) {
            Address a = ins.getAddress();
            List<Function> fs = byEntry.get(a.getOffset());
            if (fs != null) {
                for (Function f : fs) {
                    out.println();
                    out.println("--- FUNCTION " + f.getName() + " @ " + a + " (size " + f.getBody().getNumAddresses() + ") ---");
                }
            }
            StringBuilder refs = new StringBuilder();
            for (Reference r : prog.getReferenceManager().getReferencesFrom(a)) {
                if (refs.length() > 0) refs.append(',');
                refs.append(r.getToAddress());
            }
            out.printf("%s  %-30s %s%n", a, ins.toString(),
                    refs.length() > 0 ? "; -> " + refs : "");
        }

        out.close();
        println("Dumped to " + outpath);
        println("Functions: " + funcs.size());
    }
}
