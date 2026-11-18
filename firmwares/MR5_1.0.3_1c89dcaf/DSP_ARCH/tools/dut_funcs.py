import json
import io

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
fs = json.load(io.open(SRC + r'\disasm\function_strings.json', encoding='utf-8'))
# find functions whose strings include DUT/TST patterns
for fname, strs in fs.items():
    if isinstance(strs, dict):
        vals = list(strs.values())
    else:
        vals = strs
    hits = [s for s in vals if 'DUT' in s or 'TST' in s]
    if hits:
        print(fname, '->', hits)
