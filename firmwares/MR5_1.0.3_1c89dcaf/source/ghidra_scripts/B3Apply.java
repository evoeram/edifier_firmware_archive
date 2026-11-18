// B3: apply SDK signature names (disasm/b3_signatures.json:
// {addr: {name, elf_addr, size, words_diff, lib?}}). Renames only functions
// still bearing FUN_/sub_/thunk_ names; plate comment carries the evidence.
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

public class B3Apply extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        JsonObject root;
        try (Reader r = new FileReader(args[0])) {
            root = JsonParser.parseReader(r).getAsJsonObject();
        }
        println("b3 signatures: " + root.size());
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int ok = 0, skip = 0, missing = 0, collision = 0;
        int txid = currentProgram.startTransaction("B3Apply");
        try {
            for (Entry<String, JsonElement> e : root.entrySet()) {
                String key = e.getKey();          // 06001086
                JsonObject v = e.getValue().getAsJsonObject();
                String want = v.get("name").getAsString();
                Address a = space.getAddress(key);
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
                        f.setName(want + "__" + key, SourceType.USER_DEFINED);
                        ok++;
                    } catch (Exception ex2) {
                        collision++;
                        continue;
                    }
                }
                String src = v.has("lib") ? v.get("lib").getAsString()
                        : "br28 sdk.elf (AC701N SDK)";
                f.setComment("B3 SDK signature: " + want
                        + "\n  source: " + src
                        + "\n  elf addr: " + v.get("elf_addr").getAsString()
                        + "\n  size: " + v.get("size").getAsInt()
                        + " B, words diff: " + v.get("words_diff").getAsString()
                        + "\n  method: byte-exact anchor match "
                        + "(tools/b3_sigs2.py)");
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println(String.format(
                "B3 apply: renamed=%d already-named=%d missing=%d collision=%d",
                ok, skip, missing, collision));
    }
}
