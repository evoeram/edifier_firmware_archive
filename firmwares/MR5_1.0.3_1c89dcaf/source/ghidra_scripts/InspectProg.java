// Inspect memory layout and function counts of the current program.
// @category JieLi
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;

public class InspectProg extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("program: " + currentProgram.getName());
        println("image base: " + currentProgram.getImageBase());
        println("language: " + currentProgram.getLanguage().getLanguageID());
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            println(String.format("block %-20s %s..%s size=0x%x init=%s",
                    b.getName(), b.getStart(), b.getEnd(), b.getSize(), b.isInitialized()));
        }
        ghidra.program.model.listing.FunctionManager fmm = currentProgram.getFunctionManager();
        int inFuncs = 0;
        int fcount = 0;
        for (Function f : fmm.getFunctions(true)) {
            fcount++;
            if (currentProgram.getMemory().getBlock(f.getEntryPoint()) != null) inFuncs++;
        }
        println("functions total: " + fcount + " (with memory block: " + inFuncs + ")");
        println("instructions total: " + currentProgram.getListing().getNumInstructions());
        // first 5 function entries
        int n = 0;
        for (Function f : fmm.getFunctions(true)) {
            println("  fn " + f.getEntryPoint() + " body=" + f.getBody().getNumAddresses());
            if (++n >= 5) break;
        }
    }
}
