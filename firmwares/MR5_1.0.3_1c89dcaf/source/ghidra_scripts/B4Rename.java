// B4: rename functions using the B2 string map (disasm/function_strings.json)
// and the B2 anchors (findings/B2_anchors.md section 4). Every renamed function
// gets a plate comment with the evidence.
// @category JieLi
import java.io.FileReader;
import java.io.Reader;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class B4Rename extends GhidraScript {

    private static final Map<String, String> ANCHORS = new LinkedHashMap<>();

    static {
        // findings/B2_anchors.md section 4 (subsystem anchors)
        ANCHORS.put("sub_06002224", "key_scan_send");
        ANCHORS.put("sub_0600a278", "mcu_msg_send");
        ANCHORS.put("sub_0600ac08", "dut_tst_cluster");
        ANCHORS.put("sub_0600d698", "dut_tst_cluster_2");
        ANCHORS.put("sub_0602b98c", "dut_tst_cluster_3");
        ANCHORS.put("sub_06017c92", "dut_tst_cluster_4");
        ANCHORS.put("sub_0600a6a2", "bt_name_config");
        ANCHORS.put("sub_06038554", "jlstream_cluster");
        ANCHORS.put("sub_06038892", "jlstream_caller");
        ANCHORS.put("sub_06013cf2", "music_eq_1");
        ANCHORS.put("sub_06016d36", "music_eq_2");
        ANCHORS.put("sub_06006390", "set_hp_gain");
        ANCHORS.put("sub_0602c2c0", "usb_stack_cluster");
        ANCHORS.put("sub_06007d8c", "tone_load");
    }

    private static String sanitize(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c) || c == '_') {
                sb.append(c);
            } else {
                sb.append('_');
            }
        }
        String r = sb.toString().replaceAll("_+", "_").replaceAll("^_+|_+$", "");
        if (r.length() > 40) {
            r = r.substring(0, 40);
        }
        return r.toLowerCase();
    }

    private static Map<String, String[]> load(String path) throws Exception {
        Map<String, String[]> out = new LinkedHashMap<>();
        try (Reader r = new FileReader(path)) {
            JsonObject root = JsonParser.parseReader(r).getAsJsonObject();
            for (Entry<String, JsonElement> e : root.entrySet()) {
                JsonArray arr = e.getValue().getAsJsonArray();
                String[] vals = new String[arr.size()];
                for (int i = 0; i < arr.size(); i++) {
                    vals[i] = arr.get(i).getAsString();
                }
                out.put(e.getKey(), vals);
            }
        }
        return out;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Map<String, String[]> map = load(args[0]);
        println("function->strings entries: " + map.size());
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();

        int renamedAnchor = 0, renamedStr = 0, missing = 0, collision = 0;
        int txid = currentProgram.startTransaction("B4Rename");
        try {
            // 1. anchors first (they win over string-derived names)
            for (Entry<String, String> e : ANCHORS.entrySet()) {
                Address a = space.getAddress(e.getKey().substring(4));
                Function f = getFunctionAt(a);
                if (f == null) {
                    println("  anchor missing function: " + e.getKey());
                    missing++;
                    continue;
                }
                f.setName(e.getValue(), SourceType.USER_DEFINED);
                f.setComment("B2 anchor (findings/B2_anchors.md): subsystem named by string "
                        + "anchors; see string_xrefs.md for the evidence chain. Former name: "
                        + e.getKey());
                renamedAnchor++;
            }
            // 2. string-derived names
            for (Entry<String, String[]> e : map.entrySet()) {
                Address a = space.getAddress(e.getKey().substring(4));
                Function f = getFunctionAt(a);
                if (f == null) {
                    missing++;
                    continue;
                }
                StringBuilder comment = new StringBuilder(
                        "B2: strings referenced by this function (disasm/function_strings.json):");
                for (String s : e.getValue()) {
                    String one = s.length() > 90 ? s.substring(0, 90) + "..." : s;
                    comment.append("\n  \"").append(one).append("\"");
                }
                String base = "f_" + sanitize(e.getValue()[0]);
                if (base.length() < 4) {
                    base = "f_str_" + e.getKey().substring(4);
                }
                if (f.getName().startsWith("sub_") || f.getName().startsWith("FUN_")) {
                    try {
                        f.setName(base, SourceType.USER_DEFINED);
                        renamedStr++;
                    } catch (Exception ex) {
                        collision++;
                    }
                }
                String old = f.getComment();
                f.setComment((old == null ? "" : old + "\n") + comment);
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println(String.format(
                "B4 rename: anchors=%d by-strings=%d missing-func=%d collisions=%d",
                renamedAnchor, renamedStr, missing, collision));
    }
}
