// Dump program statistics after analysis (A2/A3/A4 checkpoint).
// @category JieLi
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class StatsDump extends GhidraScript {

    @Override
    public void run() throws Exception {
        int funcs = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            funcs++;
        }
        long insns = currentProgram.getListing().getNumInstructions();
        long data = currentProgram.getListing().getNumDefinedData();
        int refs = currentProgram.getReferenceManager().getReferenceDestinationCount();
        println(String.format(
                "STATS: functions=%d instructions=%d definedData=%d references=%d",
                funcs, insns, data, refs));
    }
}
