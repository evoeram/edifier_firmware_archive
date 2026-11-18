// Export program inventory: functions (name/entry/size/callers), strings/data
// labels, and plate comments ??? the human-valuable part of the analysis.
// @category JieLi
import java.io.FileWriter;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class ExportInventory extends GhidraScript {

    @Override
    public void run() throws Exception {
        String out = "C:\\dev\\edifier_firmware_archive\\firmwares\\MR5_1.0.3_1c89dcaf\\source\\ghidra_export\\";

        // 1. functions: entry, size, name
        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out + "functions.csv"), java.nio.charset.StandardCharsets.UTF_8))) {
            w.println("entry,size,name");
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            int n = 0;
            while (it.hasNext()) {
                Function f = it.next();
                long sz = f.getBody().getNumAddresses();
                w.printf("%s,%d,%s%n", f.getEntryPoint(), sz,
                        f.getName().replace(',', ' '));
                n++;
            }
            println("functions exported: " + n);
        }

        // 2. functions with evidence comments (B4 renames + anchors)
        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out + "named_functions.md"), java.nio.charset.StandardCharsets.UTF_8))) {
            w.println("# Named functions (B4/anchors) with evidence\n");
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            int n = 0;
            while (it.hasNext()) {
                Function f = it.next();
                String name = f.getName();
                if (name.startsWith("FUN_") || name.startsWith("sub_")) {
                    continue;
                }
                String cmt = f.getComment() == null ? "" : f.getComment();
                w.printf("## %s @ %s (size %d)%n%n", name, f.getEntryPoint(),
                        f.getBody().getNumAddresses());
                if (!cmt.isEmpty()) {
                    w.println(cmt + "\n");
                }
                n++;
            }
            println("named functions exported: " + n);
        }

        // 3. cross-references to defined strings (data -> code evidence)
        try (PrintWriter w = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out + "string_xrefs_ghidra.csv"), java.nio.charset.StandardCharsets.UTF_8))) {
            w.println("from_addr,to_addr,ref_type");
            ReferenceIterator rit = currentProgram.getReferenceManager()
                    .getExternalReferences(); // placeholder, replaced below
            // simple pass: references TO data defined as strings
            int n = 0;
            var listing = currentProgram.getListing();
            var di = listing.getDefinedData(true);
            while (di.hasNext()) {
                var d = di.next();
                String val = d.getValue() != null ? d.getValue().toString() : "";
                if (d.hasStringValue()) {
                    for (Reference r : currentProgram.getReferenceManager()
                            .getReferencesTo(d.getAddress())) {
                        w.printf("%s,%s,%s%n", r.getFromAddress(), d.getAddress(),
                                val.replace(',', ' ').replace('\n', ' '));
                        n++;
                    }
                }
            }
            println("string xrefs exported: " + n);
        }

        println("inventory export done");
    }
}
