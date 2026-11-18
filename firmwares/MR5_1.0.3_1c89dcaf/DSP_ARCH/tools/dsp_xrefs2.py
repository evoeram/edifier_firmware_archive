import io
import struct

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
data = open(SRC + r'\decrypted\app_bin_full.bin', 'rb').read()

strs = {
    0x0605fc14: 'linein_dev', 0x0605fc5d: 'Vol_FileMusic', 0x0605fc6b: 'Vol_FmMusic',
    0x0605fc77: 'Vol_SpdMusic', 0x0605fc84: 'Vol_IISMusic', 0x0605fc91: 'Vol_MicMusic',
    0x0605fc9e: 'Vol_USBMusic', 0x0605fcab: 'Vol_SysKTone', 0x0605fcc9: 'esco_tx',
    0x0605fcd6: 'local_tws_source', 0x0605fceb: 'esco_adc', 0x0605fe44: 'resample',
    0x06061e0f: 'spdif', 0x06061e1b: 'VBass', 0x06061e92: 'Music2', 0x06061eae: 'MIXER7',
    0x06061eb5: 'linein', 0x06061efe: 'Vol_Btc', 0x06061f06: 'Vol_Btm', 0x06061f0e: 'Vol_Lin',
    0x06061f16: 'Vol_Sys', 0x06061f1e: 'MusicEq', 0x06061f6e: 'a2dp_dec', 0x06061f80: 'a2dp_dut',
    0x06061f92: 'IIS0_TX3', 0x06061f9b: 'MusicDrc', 0x06061fc8: 'A2DP_RX7', 0x06061fd1: 'A2DP_RX6',
    0x06061fda: 'IIS0_RX1', 0x06061fe3: 'IIS0_RX2', 0x06061fff: 'EnergyDet',
    0x06062048: 'tws_source', 0x06062074: 'SET_HP_GAIN', 0x0606208c: 'EnergyMusic',
    0x06062098: 'Vol_SysTone', 0x060620a4: 'Vol_BtcCall', 0x0606214e: 'AUX_DAC_GAIN',
    0x0606215b: 'SET_HP_GAIN2', 0x06062168: 'EnergyMusic2', 0x06062182: 'Vol_BtmMusic',
    0x0606219c: 'Vol_LinMusic', 0x060621dd: 'BassShelf_LB3', 0x060621eb: 'BassShelf_LB4',
    0x060621f9: 'TrebShelf_LB3', 0x06062207: 'TrebShelf_LB4', 0x06062223: 'AUX_DAC_GAIN2',
    0x06062231: 'Vol_BtmMusic2', 0x0606223f: 'Vol_LinMusic2', 0x060622d9: 'I2SEnergyMusic',
    0x060622e8: 'a2dp_always_on', 0x06062353: 'I2SEnergyMusic2', 0x060624a7: 'tone_zh/linein.*',
    0x060739e0: 'JL_A2DP', 0x060837f6: 'EQDIY', 0x06083800: 'EQDIY_2', 0x0608380a: 'EQDIY_3',
    0x06083814: 'EQDIY_4', 0x06084168: 'DBG_EQ',
}

hits = {}
for va, nm in strs.items():
    for delta in (0, -2, 2):
        b = struct.pack('<I', va + delta)
        start = 0
        while True:
            p = data.find(b, start)
            if p < 0:
                break
            tag = nm if delta == 0 else f'{nm}{delta:+d}'
            hits.setdefault(nm, set()).add((p, delta))
            start = p + 1

for nm in sorted(hits):
    sites = sorted(hits[nm])
    print(f'{nm:20s} sites={len(sites):3d}  offs={" ".join(hex(o) for o, d in sites[:8])}')
