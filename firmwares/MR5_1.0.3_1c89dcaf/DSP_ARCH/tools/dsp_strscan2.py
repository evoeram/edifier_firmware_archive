import io
import re

# reuse output of dsp_strscan run saved inline: rerun scan here
data = open(r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source\decrypted\app_bin_full.bin', 'rb').read()
XIP = 0x06000100
pat = re.compile(rb'[\x20-\x7e]{5,}')
kws = ['amp', 'mute', 'AUX', 'XLR', 'linein', 'LineIn', 'LINE_IN', 'gain', 'VOL',
       'src', 'source', 'IIS', 'ADC', 'DAC', 'pa_', 'codec', 'a2dp', 'A2DP', 'esco',
       'usb', 'spdif', 'Sub', 'woofer', 'tweeter', 'hp_', 'HP_', 'Vol_', 'MIXER', 'Energy',
       'Music', 'Bass', 'Treb', 'DRC', 'EQ', 'IIS0', 'adc13', 'ADC13', 'pcspk', 'aux']
found = {}
for m in pat.finditer(data):
    s = m.group().decode('ascii')
    if len(s) > 60:
        continue
    letters = sum(1 for c in s if c.isalpha())
    if letters < len(s) * 0.55:
        continue
    for kw in kws:
        if kw in s:
            found.setdefault(s, m.start())
            break
out = sorted(found.items(), key=lambda x: x[1])
print(len(out))
for s, off in out:
    print(f'{XIP+off:08x}  {s}')
