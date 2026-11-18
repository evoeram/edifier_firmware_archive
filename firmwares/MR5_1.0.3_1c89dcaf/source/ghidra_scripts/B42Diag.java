// Diagnose B4.2 manifest addresses: entry vs containing function.
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

public class B42Diag extends GhidraScript {

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
            Address a = space.getAddress(key.substring(4));
            Function at = a == null ? null : getFunctionAt(a);
            Function in = a == null ? null : getFunctionContaining(a);
            String atN = at == null ? "-" : at.getName() + "@" + at.getEntryPoint();
            String inN = in == null ? "-" : in.getName() + "@" + in.getEntryPoint();
            println(key + "  at=" + atN + "  containing=" + inN);
        }
    }
}
