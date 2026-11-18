// A4: mark ASCII strings (from tools/prep_strings.py output, the strings that
// do not overlap decoded instructions) as char arrays / terminated strings.
// @category JieLi
import java.io.FileReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.ArrayDataType;
import ghidra.program.model.data.CharDataType;
import ghidra.program.model.data.TerminatedStringDataType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.Memory;

public class A4MarkStrings extends GhidraScript {

    private static final class Str {
        final long addr;
        final int len;
        final String text;

        Str(long addr, int len, String text) {
            this.addr = addr;
            this.len = len;
            this.text = text;
        }
    }

    private static List<Str> load(String path) throws Exception {
        List<Str> out = new ArrayList<>();
        try (Reader r = new FileReader(path)) {
            JsonArray arr = JsonParser.parseReader(r).getAsJsonArray();
            for (JsonElement el : arr) {
                JsonObject o = el.getAsJsonObject();
                out.add(new Str(o.get("addr").getAsLong(), o.get("len").getAsInt(),
                        o.get("text").getAsString()));
            }
        }
        return out;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        List<Str> strings = load(args[0]);
        println("strings to mark: " + strings.size());
        Memory mem = currentProgram.getMemory();
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int created = 0, skipped = 0, failed = 0;
        int skNoMem = 0, skIns = 0, skData = 0;
        int txid = currentProgram.startTransaction("A4MarkStrings");
        try {
            for (Str st : strings) {
                Address a = space.getAddress(st.addr);
                if (a == null || !mem.getBlock(a).isInitialized()) {
                    skNoMem++;
                    continue;
                }
                if (getInstructionAt(a) != null
                        || currentProgram.getListing().getInstructionContaining(a) != null) {
                    skIns++;
                    continue;
                }
                Data d = currentProgram.getListing().getDataAt(a);
                if (d == null) {
                    d = currentProgram.getListing().getDataContaining(a);
                }
                if (d != null && d.isDefined()) {
                    skData++;
                    continue;
                }
                if (d != null) {
                    // undefined bytes: clear, then create the string
                    currentProgram.getListing().clearCodeUnits(a,
                            a.add(st.len - 1), false, monitor);
                }
                try {
                    Data nd;
                    boolean nul = mem.getByte(space.getAddress(st.addr + st.len)) == 0;
                    if (nul) {
                        nd = createData(a, TerminatedStringDataType.dataType);
                    } else {
                        nd = createData(a, new ArrayDataType(CharDataType.dataType, st.len, 1));
                    }
                    if (nd != null) {
                        created++;
                    } else {
                        failed++;
                    }
                } catch (Exception e) {
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println(String.format(
                "A4 strings: created=%d failed=%d skip(no-mem=%d ins=%d data=%d)",
                created, failed, skNoMem, skIns, skData));
    }
}
