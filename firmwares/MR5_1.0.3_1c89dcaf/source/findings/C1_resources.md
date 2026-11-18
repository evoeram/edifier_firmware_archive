# C1 — ресурсный хвост MR5 (app_area_tail, 111 888 Б)

Хвост образа (файл 0x8effc…0xaa50c) — самостоятельный **ресурсный том** с JLFS-подобными записями (32 Б, CRC16 0x11021). XIP-адрес начала: `0608effc`.

## 1. Записи тома

| имя | offset (в хвосте) | размер | flags | idx | data_crc | CRC данных |
|---|---|---|---|---|---|---|
| `tone_zh` | 0x20 | 37664 | 83 | 0 | 9653 | нет |
| `index.idx` | 0xa0 | 67 | 82 | 0 | 99cb | нет |
| `bt_conn.mp3` | 0xf0 | 12954 | 82 | 0 | 964d | нет |
| `bt_dconn.mp3` | 0x3390 | 12954 | 82 | 0 | b1ff | нет |
| `bt_dconn2.mp3` | 0x6630 | 11494 | 82 | 1 | eaa3 | нет |

CRC **данных** записей тома не сходится с jl_crc16 (ни init, ни отражённый вариант) — алгоритм сверки данных ресурсного тома отличается; заголовки записей сходятся. TBD.

Извлечено в `source/decrypted/res/`.

## 2. TIDX — индекс тонов (`index.idx`, 67 Б)

## 3. DSP/эффекты: именованные узлы аудио-графа

Формат записи (переменная длина, 21 Б): `tag:u16 = 0x0013 | crc16 | param:u8 | имя z-строка (добито нулями до 16)`. Это **имена узлов аудио-графа Edifier** (= содержимое `effect_cfg`-класса ресурсов; те же имена видны в app.bin: `SET_HP_GAIN`, `AUX_DAC_GAIN`, `MusicEq`, `EscoDlEq`, `EnergyMusic`…). `param` — номер экземпляра узла в своей группе (у DAC24 param=0x18=24, у DAC25 — 0x19=25).

| смещение (хвост) | len | crc | p0 | имя |
|---|---|---|---|---|
| 0xc67c | 17 | 69a5 | 0x01 | `IIS0_TX4` |
| 0xc691 | 17 | 74e3 | 0x01 | `Vol_SysTone` |
| 0xc6a6 | 17 | 74e3 | 0x02 | `Vol_SysKTone` |
| 0xc6bb | 17 | 74e3 | 0x35 | `5Vol_SysRing` |
| 0xc6d0 | 17 | a576 | 0x01 | `config423581` |
| 0xc6e5 | 17 | a576 | 0x13 | `config4235819` |
| 0xc6fa | 17 | da15 | 0x12 | `ChannelExpand18` |
| 0xc70f | 17 | dccd | 0x18 | `DAC24` |
| 0xc724 | 17 | e62a | 0x01 | `MIXER1` |
| 0xc739 | 17 | 6963 | 0x01 | `IIS0_RX1` |
| 0xc74e | 17 | 6963 | 0x02 | `IIS0_RX2` |
| 0xc763 | 17 | 69a5 | 0x02 | `IIS0_TX1` |
| 0xc778 | 17 | 69a5 | 0x03 | `IIS0_TX3` |
| 0xc78d | 17 | 737b | 0x31 | `1BassShelf` |
| 0xc7a2 | 17 | 737b | 0x32 | `2TrebShelf` |
| 0xc7b7 | 17 | 737b | 0x33 | `3EQDIY` |
| 0xc7cc | 17 | 737b | 0x34 | `4BassShelf_LB2` |
| 0xc7e1 | 17 | 737b | 0x35 | `5TrebShelf_LB2` |
| 0xc7f6 | 17 | 737b | 0x36 | `6EQDIY_2` |
| 0xc80b | 17 | 737b | 0x38 | `8Desk_Acoustic_2` |
| 0xc820 | 17 | 737b | 0x39 | `9BassShelf_LB3` |
| 0xc835 | 17 | 737b | 0x3a | `:TrebShelf_LB3` |
| 0xc84a | 17 | 737b | 0x3b | `;EQDIY_3` |
| 0xc85f | 17 | 737b | 0x3c | `<BassShelf_LB4` |
| 0xc874 | 17 | 737b | 0x3d | `=TrebShelf_LB4` |
| 0xc889 | 17 | 737b | 0x3e | `>Desk_Acoustic` |
| 0xc89e | 17 | 737b | 0x3f | `?EQDIY_4` |
| 0xc8b3 | 17 | 74e3 | 0x31 | `1Vol_BtmMusic2` |
| 0xc8c8 | 17 | 74e3 | 0x33 | `3Vol_LinMusic2` |
| 0xc8dd | 17 | 74e3 | 0x51 | `QVol_LinMusic` |
| 0xc8f2 | 17 | 74e3 | 0x5c | `\Vol_BtmMusic` |
| 0xc907 | 17 | 9b3b | 0x0c | `config397392` |
| 0xc91c | 17 | 9b3b | 0x15 | `9B3B21` |
| 0xc931 | 17 | a248 | 0x01 | `EnergyMusic` |
| 0xc946 | 17 | a248 | 0x02 | `I2SEnergyMusic` |
| 0xc95b | 17 | a248 | 0x03 | `EnergyMusic2` |
| 0xc970 | 17 | a248 | 0x04 | `I2SEnergyMusic2` |
| 0xc985 | 17 | a576 | 0x10 | `A57616` |
| 0xc99a | 17 | a576 | 0x12 | `config4235818` |
| 0xc9af | 17 | a904 | 0x01 | `SET_HP_GAIN` |
| 0xc9c4 | 17 | a904 | 0x02 | `AUX_DAC_GAIN` |
| 0xc9d9 | 17 | a904 | 0x03 | `SET_HP_GAIN2` |
| 0xc9ee | 17 | a904 | 0x04 | `AUX_DAC_GAIN2` |
| 0xca03 | 17 | dccd | 0x15 | `DAC3` |
| 0xca18 | 17 | dccd | 0x19 | `DAC25` |
| 0xca2d | 17 | defe | 0x05 | `DRC5` |
| 0xca42 | 17 | defe | 0x1f | `DRC31` |
| 0xca57 | 17 | f975 | 0x06 | `A2DP_RX6` |
| 0xca6c | 17 | f975 | 0x07 | `A2DP_RX7` |
| 0xca81 | 17 | 737b | 0x0a | `
EscoUlEq` |
| 0xca96 | 17 | 737b | 0x0b | `EscoDlEq` |
| 0xcaab | 17 | 74e3 | 0x09 | `	Vol_BtcCall` |
| 0xcac0 | 17 | a576 | 0x06 | `config423586` |
| 0xcad5 | 17 | d06d | 0x01 | `esco_adc` |
| 0xcaea | 17 | d0bc | 0x01 | `MIC534361` |
| 0xcaff | 17 | da15 | 0x2a | `*ChannelExpand42` |
| 0xcb14 | 17 | dccd | 0x02 | `DAC2` |
| 0xcb29 | 17 | 737b | 0x11 | `EQ17` |
| 0xcb3e | 17 | 74e3 | 0x2f | `/Vol_PcspkMusic` |
| 0xcb53 | 17 | 9b3b | 0x0e | `config3973914` |
| 0xcb68 | 17 | d06d | 0x0d | `ADC13` |
| 0xcb7d | 17 | eb56 | 0x01 | `pcspk` |

## 4. Ссылки из кода в хвост

Прямых ссылок почти нет: том адресуется **по имени через файловый API** (`flash/res/...`, `tone_zh/...`). Единственная найденная ссылка — crt0 (`0x06000176`): `r1 = 0x0608EFFC` — регистрация базы ресурсного тома (копия длиной 0 → передача адреса):

```
06000170: c4 ff 00 00 00 02    r4 = 33554432
06000176: c1 ff fc ef 08 06    r1 = 101249020  ; 0x0608EFFC
0600017c: c2 ff 00 00 00 00    r2 = 0
```

| target | ссылка из | x | контекст |
|---|---|---|---|
| `0608effc` (tail+0x0) | `(raw)` | 1 |  |
| `0608effc` (tail+0x0) | `?` | 1 |  |

## 5. Выводы

1. Хвост — **автономный ресурсный том** (JLFS-записи, base=2):
   `tone_zh` (подтом тонов, 37 664 Б), `index.idx` (TIDX), 3 mp3-тона
   (bt_conn, bt_dconn, bt_dconn2).
2. `TIDX` — индекс тонов: пары (crc16, id) + имена mp3.
3. Зона DSP-конфигов (tail+0xC67C…): **62 записи** имён узлов аудио-графа
   `tag 0x0013 | crc16 | param u8 | имя` — узлы DAC*/ADC*/MIXER*/IIS0_*/
   BassShelf*/TrebShelf*/EQDIY*/Desk_Acoustic*/Vol_*/EnergyMusic*/
   ChannelExpand*/config*/SET_HP_GAIN/AUX_DAC_GAIN/Esco*/DRC*/A2DP_RX*.
   `DAC3`/`DAC25` из старого отчёта — просто имена узлов DAC (param 21/25).
4. После блока имён (tail+0xCB92…) идут двоичные структуры узлов —
   коэффициенты/конфиги (следующий шаг C1: связать размер блока имён
   с парсером effect_cfg в коде).
5. Код обращается к тому **по имени через файловый API**; единственная
   прямая ссылка — crt0 регистрирует базу тома 0x0608EFFC (копия длиной 0).
   Привязку «узел → код» делать через парсер effect_cfg (якоря B2:
   `Eq*Media`, `SET_HP_GAIN` → sub_06006390, sub_06013cf2, sub_06016d36).
