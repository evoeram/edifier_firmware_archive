// A2: create the RAM data blocks referenced by crt0 (BSS clear 0x105780+0x3d60,
// .data copies to 0x104840 and 0x1094e0, sp=0x103840). Plan: 0x100000-0x140000.
// Also disables the Decompiler Parameter ID analyzer (p-code is decode-only;
// parameter ID cannot work and is the slowest analyzer).
// @category JieLi
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Program;
import ghidra.program.model.mem.MemoryBlock;

public class A2CreateRam extends GhidraScript {

    @Override
    public void run() throws Exception {
        var space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Address start = space.getAddress(0x100000L);
        Address end = space.getAddress(0x13ffffL);
        int txid = currentProgram.startTransaction("A2CreateRam");
        try {
            if (currentProgram.getMemory().getBlock(start) == null) {
                MemoryBlock b = currentProgram.getMemory().createUninitializedBlock(
                        "RAM", start, end.getOffset() - start.getOffset() + 1, false);
                b.setRead(true);
                b.setWrite(true);
                b.setExecute(false);
                b.setComment("pi32v2 data RAM (crt0: sp=0x103840, bss 0x105780+0x3d60, "
                        + ".data 0x104840/0x1094e0)");
                println("created RAM block 0x100000-0x13ffff");
            } else {
                println("RAM block already exists");
            }
        } finally {
            currentProgram.endTransaction(txid, true);
        }
        var opts = currentProgram.getOptions(Program.ANALYSIS_PROPERTIES);
        opts.setBoolean("Decompiler Parameter ID", false);
        println("Decompiler Parameter ID analyzer disabled");
    }
}
