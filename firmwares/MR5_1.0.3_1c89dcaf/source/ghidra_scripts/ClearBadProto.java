// Clear code units with broken (unresolvable) instruction prototypes - leftovers
// from the era of the partial kagaimiq spec. Takes a file with one 8-hex-digit
// address per line (the addresses logged by PrototypeManager as
// "Bad Instruction Prototype" at program open).
// @category JieLi
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

public class ClearBadProto extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        List<Address> addrs = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(args[0]))) {
            String l;
            while ((l = br.readLine()) != null) {
                l = l.trim();
                if (l.isEmpty() || l.startsWith("#")) {
                    continue;
                }
                addrs.add(currentProgram.getAddressFactory().getDefaultAddressSpace()
                        .getAddress(new BigInteger(l, 16).longValue()));
            }
        }
        int cleared = 0;
        int txid = currentProgram.startTransaction("ClearBadProto");
        try {
            for (Address a : addrs) {
                Instruction ins = currentProgram.getListing().getInstructionAt(a);
                if (ins != null) {
                    currentProgram.getListing().clearCodeUnits(a, a, false, monitor);
                    cleared++;
                }
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        println("cleared bad-prototype code units: " + cleared + " / " + addrs.size());
    }
}
