// B4.2: apply the rename manifest (disasm/b42_manifest.json:
// {sub_ADDR: {name, strings, how}}). Renames only functions still bearing
// FUN_/sub_/thunk_ names; adds a plate comment with the evidence.
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

public class B42Apply extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        JsonObject root;
        try (Reader r = new FileReader(args[0])) {
            root = JsonParser.parseReader(r).getAsJsonObject();
        }
        println("b42 manifest entries: " + root.size());
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();

        int ok = 0, skipNamed = 0, missing = 0, collision = 0;
        int txid = currentProgram.startTransaction("B42Apply");
        try {
            for (Entry<String, JsonElement> e : root.entrySet()) {
                String key = e.getKey();          // sub_0600ba7c
                JsonObject v = e.getValue().getAsJsonObject();
                String want = v.get("name").getAsString();
                Address a = space.getAddress(key.substring(4));
                Function f = a == null ? null : getFunctionAt(a);
                if (f == null) {
                    missing++;
                    continue;
                }
                String cur = f.getName();
                boolean expert = "expert".equals(v.get("how").getAsString());
                boolean unnamed = cur.startsWith("FUN_")
                        || cur.startsWith("sub_") || cur.startsWith("thunk_");
                boolean weakAuto = cur.startsWith("f_") && expert;
                if (!unnamed && !weakAuto) {
                    skipNamed++;
                    continue;
                }
                try {
                    f.setName(want, SourceType.USER_DEFINED);
                    ok++;
                } catch (Exception ex) {
                    try {
                        f.setName(want + "_" + key.substring(4),
                                  SourceType.USER_DEFINED);
                        ok++;
                    } catch (Exception ex2) {
                        collision++;
                        continue;
                    }
                }
                StringBuilder cmt = new StringBuilder();
                cmt.append("B4.2 rename (").append(v.get("how").getAsString())
                        .append("); evidence: disasm/b42_manifest.json");
                if (v.has("strings") && v.get("strings").isJsonArray()
                        && v.getAsJsonArray("strings").size() > 0) {
                    cmt.append("; strings:");
                    for (JsonElement s : v.getAsJsonArray("strings")) {
                        String one = s.getAsString();
                        if (one.length() > 70) {
                            one = one.substring(0, 70) + "...";
                        }
                        cmt.append("\n  \"").append(one).append("\"");
                    }
                }
                f.setComment(cmt.toString());
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println(String.format(
                "B4.2 apply: renamed=%d already-named=%d missing=%d collision=%d",
                ok, skipNamed, missing, collision));
    }
}
