# MR5 1.0.3 — DSP-алгоритмы и маршрутизация (jlstream audio-graph)

Дата: 2026-11-18. Доказательная база: Ghidra-проект `source/ghidra_proj_snapshot`
(app_bin_full.bin, 3 509 функций), `stream.bin` (ресурсный хвост, TLV tag 5),
листинг `source/disasm/mr5_app_disasm.txt`, декомпиляты
`source/disasm/b3_overlay_decomp.c` и временные `dsp_decomp*.c`.

## 1. Архитектура: audio-graph «jlstream»

DSP-подсистема — граф узлов JieLi (jlstream). Ядро:

| Функция | Адрес | Роль |
|---|---|---|
| `effect_nodes_open` | 0600e3d8 | сборка/старт цепочки узлов (выделение 0xd0-байтного контекста, кодек-инициализация, таблица колбэков 0x113524) |
| `effect_nodes_close` | 0604c65c | останов |
| `jlstream_res_init` | 0604b08e | привязка ресурса (config-дескриптор) к потоку; тип узла = байт[8]&0x0f (3=consum, 5=prod) |
| `FUN_06007f3e` | 06007f3e | диспетчер событий/резолвер имя→crc (djb2, seed 0x1505, ×0x21) |
| `FUN_06038bd8` / `FUN_06038d42` | 06038bd8 / 06038d42 | запись/чтение параметра узла по имени (node_param_set/get) |
| `FUN_06037ba4` / `FUN_06037cce` | 06037ba4 / 06037cce | чтение/запись конфиг-БД spi-flash, ключ {type, hash(name), param} |
| `FUN_060389ae` | 060389ae | обходчик цепочки событий (event 0x2000d/0x2001f/0xd88) |
| `FUN_06038540` | 06038540 | привязка vtable-колбэка узла (таблица 0x1124dc) |

**Идентификация узлов**: имя-строка → crc16 (djb2: `h=0x1505; h=h*33+c`).
В stream.bin 62 имени = инстансы **16 шаблонов** (crc):

| crc | Шаблон | Инстансы (param:имя) |
|---|---|---|
| 0x6963 | I2S вход | 1:IIS0_RX1, 2:IIS0_RX2 |
| 0x69a5 | I2S выход | 1:IIS0_TX4, 2:IIS0_TX1, 3:IIS0_TX3 |
| 0x737b | EQ-движок | 17 слотов: EscoUlEq(10), EscoDlEq(11), EQ17(17), BassShelf(49), TrebShelf(50), EQDIY(51), BassShelf_LB2(52), TrebShelf_LB2(53), EQDIY_2(54), Desk_Acoustic_2(56), BassShelf_LB3(57), TrebShelf_LB3(58), EQDIY_3(59), BassShelf_LB4(60), TrebShelf_LB4(61), Desk_Acoustic(62), EQDIY_4(63) |
| 0x74e3 | Цифровая громкость (digvol) | 9 кривых: Vol_SysTone(1), Vol_SysKTone(2), Vol_BtcCall(9), Vol_PcspkMusic(47), Vol_BtmMusic2(49), Vol_LinMusic2(51), Vol_SysRing(53), Vol_LinMusic(81), Vol_BtmMusic(92) |
| 0x9b3b | конфиг-узел | config397392(12), config3973914(14), 9B3B21(21) |
| 0xa248 | Energy-детектор (loudness/AGC-датчик) | EnergyMusic(1), I2SEnergyMusic(2), EnergyMusic2(3), I2SEnergyMusic2(4) |
| 0xa576 | конфиг-узел | config423581(1), config423586(6), A57616(16), config4235818(18), config4235819(19) |
| 0xa904 | Gain-узел | SET_HP_GAIN(1), AUX_DAC_GAIN(2), SET_HP_GAIN2(3), AUX_DAC_GAIN2(4) |
| 0xd06d | АЦП-захват | esco_adc(1), ADC13(13) |
| 0xd0bc | MIC | MIC534361(1) |
| 0xda15 | ChannelExpand (расширение каналов) | ChannelExpand18(18), ChannelExpand42(42) |
| 0xdccd | ЦАП | DAC2(2), DAC3(21), DAC24(24), DAC25(25) |
| 0xdefe | DRC | DRC5(5), DRC31(31) |
| 0xe62a | Микшер | MIXER1(1) |
| 0xeb56 | pcspk | pcspk(1) |
| 0xf975 | A2DP-приёмник | A2DP_RX6(6), A2DP_RX7(7) |

Инстансы в таблице графа (tag 0, 176 записей) появляются парами ×2 —
**стерео-пары L/R** (EQ17 с param 49…63 встречается ×2 — по экземпляру на канал).
Имена вида `DAC24` — это инстанс param=24 шаблона DAC, а не отдельный узел.

## 2. Хранилище конфигураций

1. **Заводские значения** — `stream.bin` (вложенный том ресурсного хвоста,
   hdr@tail+0xc394): 246 дескрипторов × 32 Б
   `{type | crc16 | param | idx | block_off | stride}`:
   - type 1 (EQ): 185 шт., блок 200 Б = шапка 8 Б + N×16 Б бэндов
     `{band u16 | type u16 | freq f32 | gain f32 | Q f32}`;
   - type 2 (DRC): 2 шт., блок 76 Б;
   - type 3 (GAIN/digvol): 59 шт., блоки 8–136 Б;
   - type 4/5/7: групповые записи, ссылающиеся на полосы EQ по индексу
     (кроссоверные наборы: бэнд-индекс + тип + частота — см. вывод
     `dsp_cfgdump.py`).
2. **Текущие/пользовательские значения** — конфиг-БД spi-flash
   (`FUN_06037ba4`/`FUN_06037cce`, VM-записи 32 Б с crc32 имени; размер записи
   возвращается в параметре). Чтение возвращает {offset, len, flag} в буфер
   вызывающего.

## 3. DSP-алгоритмы (код)

### 3.1 EQ — би-квад-движок
- `audio_eq_tab_check` @06065808: валидация таблицы + генерация коэффициентов;
  switch по типу фильтра 0..8 → генераторы по адресам
  06040e64, 06040ecc, 06040f34, 06040fce, 060410b6, 060411aa, 06041272, 06041332, 06041594;
  завершается вызовом `FUN_060417d4` (загрузка в узел).
- `eq_db2mag` @0603c3c6: дБ→амплитуда для EQ-коэффициентов.
- Типы фильтров: 0=bypass/lowpass1, 2=peaking, 3=lowshelf, 4=highshelf,
  5=bandpass, 6=notch, 7=lowshelf2, 8=highshelf2 (соответствие с полями
  «type» в блоках: 2=pk, 3=t3, 4=t4, 7=t7, 8=t8 — см. EQ_TABLES.md).
- Слоты EQ (17): темброблоки, пресеты помещения, пользовательский EQ, ESCO.

### 3.2 DRC — peak-follower компрессор
- `DrcPeakFollowProcess` @06085848 (RAM-оверлей, копия из flash 0x060843cc →
  RAM 0x1094e0): классический DRC — поиск перегиба КНИ в таблице порогов,
  `drc_db2mag` для перевода усиления, поканальное применение гейна
  (int/short-ветки, sat16).
- `drc_db2mag` @06085550 (signature br28).
- `DrcCalcTimeFactor` @0604e496: факторы атаки/восстановления
  (константы 0x57e/0xd7e = 1406/3454, масштаб от частоты дискретизации).
- Инстансы: DRC5(5), DRC31(31) — музыка/вызов.

### 3.3 Громкость и гейны
- digvol-шаблон (0x74e3): 9 кривых — 32-точечные таблицы дБ на источник
  (см. §4).
- Gain-шаблон (0xa904): фиксированные гейны:
  - `SET_HP_GAIN` = **+8.3 дБ** (наушники, норма);
  - `SET_HP_GAIN2` = **+2.3 дБ** (наушники, пониженный);
  - `AUX_DAC_GAIN` = 0.0 дБ / **−1.3 дБ**;
  - `AUX_DAC_GAIN2` = **+6.5 дБ**.
- `set_hp_gain` @06006390: обработчик клавиш громкости/наушников;
  счётчики состояния 0x106060+0x14/0x15/0x16 (диапазоны до 0x33=51),
  режим `FUN_060745c6` (mode==0x33 и т.п.), анти-pop пульсация GPIO
  (см. POWER_AMP.md).

### 3.4 Прочее
- `audio_cfifo_mix_data` @0604bea4 — суммирование потоков в cfifo (mixer).
- `premute` @0604dc98 — перестановка каналов (матрица 4×4).
- `soc_sync_matched_sample_rate` @06070220 — синхронизация sample rate.
- Энергодетектор EnergyMusic/I2SEnergyMusic (0xa248) — детектор сигнала для
  auto-standby/loudness (GAIN-конфиг EnergyMusic: 14 Б, пороги 0xbb8=3000,
  0x64=100).

## 4. Кривые громкости по источникам (дБ, шаг 0→31)

| Источник | Кривая (дБ) |
|---|---|
| Vol_BtmMusic (BT music) | −70, −66, −62, −58, −54, −50, −47, −44, −41, −38, −35, −32, −30, −28, −26, −24, −22, −20, −18, −16, −15, −14, −13, −12, −11, −10, −9, −8, −7.5, −7 … |
| Vol_BtmMusic2 (BT alt) | −63 … −5.5 (шаг 4→1→0.5) |
| Vol_LinMusic (Line In) | −63 … −1, 0 |
| Vol_LinMusic2 (Line In alt) | −58 … 0 |
| Vol_SysTone / Vol_BtcCall / Vol_PcspkMusic | 16-байтные конфиги digvol-группы (fade/step) |

Максимальная громкость различается по источникам (BT −7 дБ, Line 0 дБ) —
защита тракта.

## 5. Приложения конфигов (кто куда пишет)

- Прикладной слой (обработчики источников, 0600b000–0600d900 и 0600f5xx–0600f7xx)
  вызывает стабы узлов (`f_aux_dac_gain`, `f_trebshelf_lb3/4`, `f_ext_reserved`,
  `f_jlstream` @06001dba–06001e76) — те через `FUN_0600b5ae` → `FUN_06038bd8`
  (node_param_set) применяют конфиг по имени узла.
- Переключение источника: `effect_nodes_open` @06018e4a-сайт (обработчик
  режима), `effect_nodes_close` @0603b592; микшер `f_mixer7`
  open 0600a0b6 / close 0600b0a4 вызываются из 0600bf86/0600bf82 (mode A) и
  0600c81e/0600c852 (mode B).
- Тон-сигналы: `tone_zh/*.mp3` (bt_conn, power_on/off, vol_max, key_tone,
  ring, game_in/out, linein) → `FUN_0606fc52` (выбор слота громкости
  0x10689e/0x1068a0) → `f_energymusic(mode)` — применяет громкость тона.

## 6. Не раскрыто (ограничения)

- Точная топология рёбер L/R внутри графа: 176 записей tag 0 — список
  инстансов (crc,param), рёбра собираются в рантайме (`effect_nodes_open`),
  статически видны только косвенно.
- Содержимое RAM-ядра оверлея 0x060866e6–0x0608efde декомпилировано
  (`b3_overlay_decomp.c`), 139 функций; имена новых алгоритмов туда не
  проставлены (см. b3_signatures: DrcPeakFollowProcess/drc_db2mag покрыты).
- Кодеки A2DP (SBC/AAC/LDAC) — библиотеки SDK (mpegaudio_synth_full и др.),
  вне объема этого отчета.
