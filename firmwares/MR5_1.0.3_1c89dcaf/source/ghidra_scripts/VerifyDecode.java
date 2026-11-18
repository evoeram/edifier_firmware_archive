// A1 verification: clear the listing, disassemble at every start address from the
// reference listing (mr5_app_disasm.txt), dump all decoded instructions.
// @category JieLi
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Instruction;

public class VerifyDecode extends GhidraScript {

    private static final Pattern LINE =
            Pattern.compile("^([0-9a-f]{8}): ((?:[0-9a-f]{2} )+)(.+)$");

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String lstPath = args[0];
        String outPath = args[1];

        // 1. read the reference listing
        List<Long> starts = new ArrayList<>();
        List<Integer> sizes = new ArrayList<>();
        List<String> texts = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(lstPath))) {
            String l;
            while ((l = br.readLine()) != null) {
                Matcher m = LINE.matcher(l);
                if (!m.matches()) {
                    continue;
                }
                starts.add(Long.parseLong(m.group(1), 16));
                sizes.add(m.group(2).trim().split(" ").length);
                texts.add(m.group(3).trim());
            }
        }
        println("reference listing: " + starts.size() + " instructions");

        Address base = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x06000100L);

        int txid = currentProgram.startTransaction("VerifyDecode");
        try {
            // 2. clear all code units (keep functions and bookmarks)
            currentProgram.getListing().clearAll(false, monitor);

            // 3. disassemble at every reference start
            AddressSet set = new AddressSet();
            for (long a : starts) {
                set.add(currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(a));
            }
            DisassembleCommand cmd = new DisassembleCommand(set, null, true);
            cmd.applyTo(currentProgram, monitor);
        } finally {
            currentProgram.endTransaction(txid, true);
        }

        // 4. dump decoded instructions
        int decoded = 0;
        try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(outPath)))) {
            for (int k = 0; k < starts.size(); k++) {
                Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(starts.get(k));
                Instruction ins = currentProgram.getListing().getInstructionAt(a);
                if (ins == null) {
                    w.printf("%08x MISSING %s%n", starts.get(k), texts.get(k));
                } else {
                    decoded++;
                    w.printf("%08x %d %s%n", starts.get(k), ins.getLength(),
                            ins.toString().replace('\n', ' '));
                }
            }
        }
        println(String.format("decoded at reference starts: %d / %d (%.2f%%)",
                decoded, starts.size(), 100.0 * decoded / starts.size()));
    }
}