// C4: restore data markup wiped by the full disassembly. Reads
// disasm/c4_manifest.json: {strings:[{addr,len,src}], tables:[{addr,n}]}.
// Strings: clear junk code units, then terminated string (if NUL follows)
// or char array. Tables: clear, then 32-bit pointer arrays.
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
import ghidra.program.model.data.Pointer32DataType;
import ghidra.program.model.data.TerminatedStringDataType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.Memory;

public class C4MarkData extends GhidraScript {

    private static final class Item {
        final long addr;
        final int len;
        final String src;

        Item(long addr, int len, String src) {
            this.addr = addr;
            this.len = len;
            this.src = src;
        }
    }

    private static List<Item> loadStrings(String path) throws Exception {
        List<Item> out = new ArrayList<>();
        try (Reader r = new FileReader(path)) {
            JsonObject root = JsonParser.parseReader(r).getAsJsonObject();
            for (JsonElement el : root.get("strings").getAsJsonArray()) {
                JsonObject o = el.getAsJsonObject();
                out.add(new Item(o.get("addr").getAsLong(),
                        o.get("len").getAsInt(),
                        o.has("src") ? o.get("src").getAsString() : "?"));
            }
        }
        return out;
    }

    private static List<Item> loadTables(String path) throws Exception {
        List<Item> out = new ArrayList<>();
        try (Reader r = new FileReader(path)) {
            JsonObject root = JsonParser.parseReader(r).getAsJsonObject();
            for (JsonElement el : root.get("tables").getAsJsonArray()) {
                JsonObject o = el.getAsJsonObject();
                out.add(new Item(o.get("addr").getAsLong(),
                        o.get("n").getAsInt() * 4, "table"));
            }
        }
        return out;
    }

    private int clearAndCreate(Address a, int len, boolean isTable)
            throws Exception {
        Address end = a.add(len - 1);
        currentProgram.getListing().clearCodeUnits(a, end, false, monitor);
        Data nd;
        if (isTable) {
            nd = createData(a, new ArrayDataType(
                    Pointer32DataType.dataType, len / 4, 4));
        } else {
            Memory mem = currentProgram.getMemory();
            boolean nul = mem.getByte(a.add(len)) == 0;
            nd = nul
                    ? createData(a, TerminatedStringDataType.dataType)
                    : createData(a, new ArrayDataType(
                            CharDataType.dataType, len, 1));
        }
        return nd != null ? 1 : 0;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        List<Item> strings = loadStrings(args[0]);
        List<Item> tables = loadTables(args[0]);
        println("c4: strings=" + strings.size() + " tables=" + tables.size());
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int okS = 0, failS = 0, okT = 0, failT = 0;
        int txid = currentProgram.startTransaction("C4MarkData");
        try {
            for (Item it : strings) {
                try {
                    Address a = space.getAddress(it.addr);
                    if (a == null) {
                        failS++;
                        continue;
                    }
                    okS += clearAndCreate(a, it.len, false);
                } catch (Exception e) {
                    failS++;
                }
            }
            for (Item it : tables) {
                try {
                    Address a = space.getAddress(it.addr);
                    if (a == null) {
                        failT++;
                        continue;
                    }
                    okT += clearAndCreate(a, it.len, true);
                } catch (Exception e) {
                    failT++;
                }
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println(String.format(
                "C4: strings ok=%d fail=%d; tables ok=%d fail=%d",
                okS, failS, okT, failT));
    }
}
