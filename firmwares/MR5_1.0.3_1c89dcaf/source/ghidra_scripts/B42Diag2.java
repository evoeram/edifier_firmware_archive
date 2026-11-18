// B42Diag2: report which manifest addresses have no function.
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

public class B42Diag2 extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        JsonObject root;
        try (Reader r = new FileReader(args[0])) {
            root = JsonParser.parseReader(r).getAsJsonObject();
        }
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        for (Entry<String, JsonElement> e : root.entrySet()) {
            String key = e.getKey();
            String want = e.getValue().getAsJsonObject().get("name").getAsString();
            Address a = space.getAddress(key.substring(4));
            Function f = a == null ? null : getFunctionAt(a);
            if (f == null) {
                println("NO FUNC: " + key + " want=" + want);
            } else {
                String cur = f.getName();
                if (!cur.equals(want)) {
                    println("MISMATCH: " + key + " want=" + want
                            + " cur=" + cur);
                }
            }
        }
        println("diag done");
    }
}
