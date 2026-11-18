// Print the p-code of the instructions at given hex addresses (args: comma list).
// @category JieLi
import java.math.BigInteger;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

public class PsDump extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        java.util.List<String> list = new java.util.ArrayList<>();
        for (String a : args) {
            for (String part : a.split(",")) {
                if (!part.isBlank()) {
                    list.add(part.trim());
                }
            }
        }
        String[] addrs = list.toArray(new String[0]);
        for (String a : addrs) {
            Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace()
                    .getAddress(new BigInteger(a, 16).longValue());
            Instruction ins = currentProgram.getListing().getInstructionAt(addr);
            println("=== " + a + " " + (ins == null ? "(none)" : ins.toString()));
            if (ins != null) {
                for (var op : ins.getPcode()) {
                    println("   " + op.toString());
                }
            }
        }
    }
}
