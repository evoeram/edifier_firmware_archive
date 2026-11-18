// B5: apply expert names (disasm/b5_names.json: {addr: {name, conf, evidence}}).
// Renames only FUN_/sub_/thunk_-named functions; comment carries evidence.
// @category JieLi
import java.io.FileReader;
import java.io.Reader;
import java.util.Map;
import java.util.Map.Entry;

import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class B5Apply extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        JsonObject root;
        try (Reader r = new FileReader(args[0])) {
            root = JsonParser.parseReader(r).getAsJsonObject();
        }
        println("b5 names: " + root.size());
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int ok = 0, skip = 0, missing = 0;
        int txid = currentProgram.startTransaction("B5Apply");
        try {
            for (Entry<String, JsonElement> e : root.entrySet()) {
                JsonObject v = e.getValue().getAsJsonObject();
                String want = v.get("name").getAsString();
                Address a = space.getAddress(e.getKey());
                Function f = a == null ? null : getFunctionAt(a);
                if (f == null) {
                    missing++;
                    continue;
                }
                String cur = f.getName();
                if (!cur.startsWith("FUN_") && !cur.startsWith("sub_")
                        && !cur.startsWith("thunk_")) {
                    skip++;
                    continue;
                }
                try {
                    f.setName(want, SourceType.USER_DEFINED);
                    ok++;
                } catch (Exception ex) {
                    try {
                        f.setName(want + "__" + e.getKey(),
                                  SourceType.USER_DEFINED);
                        ok++;
                    } catch (Exception ex2) {
                        continue;
                    }
                }
                String conf = v.has("conf") ? v.get("conf").getAsString() : "?";
                String ev = v.has("evidence") ? v.get("evidence").getAsString()
                        : "";
                f.setComment("B5 expert name (" + conf + "): " + want
                        + "\n  evidence: " + ev
                        + "\n  method: decompile + call-context (plan NEW2 F3)");
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println(String.format("B5 apply: renamed=%d already-named=%d missing=%d",
                ok, skip, missing));
    }
}
