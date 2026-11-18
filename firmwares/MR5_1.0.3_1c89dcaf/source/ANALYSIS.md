# MR5 1.0.3 (`1c89dcaf`) — отчёт анализа firmware.bin (ШИФР ВЗЛОМАН)

Дата: 2026-11-18. Файл: `firmware.bin`, 697 612 байт (0xAA50C),
SHA-256 `e9b9b8661014157412884d0bc69c280b62d56b1a24c74b26eb079e058107415e`.
Все смещения — в исходном (зашифрованном) файле, если не сказано иное.

## 1. Главный вывод

Шифрование полностью снято. `firmware.bin` — **JieLi JLFS-контейнер**,
весь файл поблочно скремблирован **SFC-шифром JieLi** с фиксированным
16-битным ключом **K = 0x2BC1**. Расшифрованный образ, записи контейнера и
CRC-верифицированное приложение `app.bin` (ядро **pi32v2**) извлечены:

- `decrypted/MR5_1.0.3_1c89dcaf_dec.bin` — расшифрованный образ (697 612 Б);
- `decrypted/app.bin` — приложение, **521 780 байт**,
  jl_crc16 данных = `0x4934` — совпадает с полем `data_crc` записи (§3);
- `decrypted/app_bin_full.bin` — весь регион данных записи (585 468 Б);
- `decrypted/app_area_tail_res.bin` — ресурсный хвост (111 888 Б,
  ASCII `DAC3`, `DAC25` — DSP-таблицы Edifier);
- `decrypted/decrypt_all.py` — дешифратор: **все 12 прошивок семьи
  расшифровываются одним ключом** (§5);
- `disasm/mr5_app_disasm.txt` — **полноценный дизасм** app.bin
  (120 366 инструкций, 2 778 функций, pi32v2) — §8.

Ядро CPU — **pi32v2** (JieLi, семейство br25/br30-класса): после расшифровки
плотность сигнатур `C0–CF FF` (mov32 imm) 86–120/10К (random 2.4),
`50–5F 04` (pop) 37–68/10К, `?? 16` (mov16) 186–388/10К. Энтропия кодовой
зоны упала 7.94 → 6.89 бит/байт.

## 2. Шифр: схема и взлом

### 2.1 Схема (подтверждена канонической реализацией JieLi)

Совпадает с `jl_sfc_cipher` из открытых реверс-инструментов JieLi
(`kagaimiq/jl-misctools`, `ElectronicCats/jieli-ble-badge-research`):

- файл разбит на 32-байтные блоки; блоки начинаются на смещениях
  **bs ≡ 2 (mod 32)** (первый «блок» начинается на −30, т.е. первые 2 байта
  файла — его хвост);
- seed блока: `seed = K ^ ((bs − 2) >> 2)`, K = **0x2BC1**;
- кейнстрим: 16-битный LFSR, `s' = (s << 1) ^ 0x1021` (если bit15),
  выход — младший байт состояния, MSB-first;
- `ct[i] = pt[i] ^ (ks[i] & 0xFF)`. Шифр XOR-симметричен.

Консистентность формулы по 271 восстановленному seed'у хвоста: **270/271**
(один блок-выброс — в зашифрованной вставке).

### 2.2 Как ключ был найден (без брутфорса 2^16 по энтропии)

Брутфорс SFC по энтропии/сигнатурам на кодовой зоне **не работает**: код
JieLi сам по себе высокоэнтропиен (6.9+). Ключ нашла атака через хвост:

1. В хвосте (0x9B800+) на нулевом плейнтексте шифртекст = кейнстрим.
   Сигнатура шага LFSR: пары `y ∈ {2x, 2x^0x21}` (0x21 = младший байт
   poly) — «удвоения» и сдвиговые серии старого отчёта (§7.3) оказались
   **кейнстримом на нулях**.
2. `state_rec.py`: по нулевой серии перебор старшего байта состояния +
   прогон рекуррентности вперёд — 16-битное состояние восстанавливается
   однозначно (LFSR биективен, откат 4 кандидата с проверкой).
3. `segmap.py`: карта сегментов кейнстрима → пересевы происходят каждые
   **32 байта**, блоки выровнены на ≡ 2 (mod 32).
4. `solve_kb2.py`: для каждого блока seed → перебор base B: при
   `B = 2` величина `seed ^ ((bs−2)>>2)` постоянна по всем 271 блокам
   и равна **0x2BC1**.

### 2.3 Верификация

- Заголовок контейнера расшифровывается в валидные JLFS-записи:
  **jl_crc16 каждой записи сходится** (§3) — это строгий оракул.
- `app.bin`: jl_crc16 данных = `0x4934` = полю `data_crc` записи.
- Строки в расшифрованном коде: `EDIFIER MR5`, `EDIFIER BLE`,
  `jlstream_*`, `usb_stack`, `pmu_task`, `tws_ota_msg`, `MCU+PWR+OFF+0000`
  и т.д. (§4).
- Все 12 прошивок семьи расшифровываются тем же ключом с валидными
  заголовками `app_area_head`/`app.bin` (§5).

## 3. Контейнер (расшифрованный образ)

Канонический JLFS: записи по 32 Б, layout
`hcrc:u16 | data_crc:u16 | offset:u32 | size:u32 | flags:u8 | rsvd:u8 | index:u16 | name[16]`
(CRC16 poly 0x11021, init 0). Первая запись — на смещении **2**.

| @file | имя       | data_crc | offset     | size    | flags | что это |
|-------|-----------|----------|------------|---------|-------|---------|
| 0x002 | app_area_head | 3792 | 0x06000100 | 585724  | 0x83  | заголовок app-области; **offset = точка входа 0x06000100** |
| 0x022 | app.bin   | 4934     | 0x00000100 | 585468  | 0x82  | приложение, данные с файла 0x100 |
| 0x042 | VM        | 01ff     | 0x001E0000 | 0x8000  | 0x12  | reserved-определение (flash-карта) |
| 0x062 | PRCT      | ffff     | 0x00000000 | 0x1E0000| 0x92  | protected-область flash [0, 0x1E0000) |
| 0x082 | BTIF      | ffff     | 0x001FE000 | 0x1000  | 0x92  | reserved (BTIF), последняя (index=1) |

Флеш 2 МБ (карта PRCT/VM/BTIF); код XIP из окна **0x06000000** — точка
входа 0x06000100 = файл 0x100 (начало app.bin). `jl_crc16` данных app.bin
сходится на префиксе **521 780 Б** (0x7F634, выровнено на 4); остальные
63 688 Б региона — продолжение кода/данных (CRC, видимо, считался по версии
без довеска). Хвост файла после app.bin (0x8EFFC…0xAA50C, 111 888 Б) —
ресурсы/DSP-таблицы (`DAC3`, `DAC25`).

## 4. Содержимое app.bin (плейтекст)

Строки подтверждают JieLi SDK нового поколения (jlstream-фреймворк):

- Bluetooth-имена: **`EDIFIER MR5`**, `EDIFIER BLE`;
- задачи/потоки: `jlstream_0..b`, `app_core`, `local_tws`, `pmu_task`,
  `usb_stack`, `iis_player`, `a2dp_dec`, `file_dec`, `audio_enc`,
  `aud_capture`, `tws_ota_msg`, `spec_adv0..2`;
- аудио: `MusicDrc`, `Eq*Media`, `EscoDlEq`, `Hexciter`, `PitchSpeed`,
  `SET_HP_GAIN`, `AUX_DAC_GAIN`, `EnergyMusic`, EQ-пресеты `Desk_Acoustic`,
  `TrebShelf_LB4`, `I2SEnergyMusic2`;
- протокол MCU (UART): `MCU+PWR+OFF+0000`, `BLT+OFF+ACK+0000`,
  `MCU+PWR`-семейство;
- сервисные/тест-команды: `DUT+TST+MAC+GET`, `TST+DUT+BLE+NAM+GET`,
  `BLT+BUTTON+IO1..6`, `TST+CLR+ALL`, `TST+LED+IO1..3`;
- файловая система: `flash/res/p11_code.bin`, `flash/res/effect_cfg.bin`,
  `flash/res/cfg_tool.bin`, `storage/nor_ui`, `mnt/sdfile/boot/otp_cfg`,
  `stream.bin`, `tone_zh/bt.*` и др.; FAT-строки (`MSDOS5.0`, `NTLDR`) —
  USB MSC-стек.

Сигнатуры ISA (на весь app.bin): mov32 100/10К, pop 51/10К, mov16 249/10К —
устойчиво **pi32v2**, не q32s (pop-паттерн 0x0450|r) и не 8051.

## 5. Все 12 прошивок семьи расшифрованы

`decrypted/decrypt_all.py` (в `source/decrypted/`), выход также в
`C:\dev\edifier_firmware_archive\decrypted\*_dec.bin`:

ES20, ES60, MP330, MR3, MR4.5, MR4_MKII, MR5, QD25, QR30, QS20, R990BT,
S355DB — у всех валидный заголовок `app_area_head`/`app.bin`, у всех точка
входа **0x06000100** (единая флеш-раскладка семьи). app.bin разных моделей
совпадает только первые 20 Б (ранний model-specific init; старое
утверждение о «6 КБ общего загрузчика MR3/MR5» в шифротексте не
подтвердилось — LCP шифротекстов тоже 8 Б).
**e25HD — другой формат** (magic `A5 5A`, плейнтекст-8051), ключ к нему
неприменим.

## 6. Инструменты (`source/tools/`)

Цепочка взлома и расшифровки:
- `state_rec.py` — восстановление 16-битного состояния LFSR из нулевых серий;
- `segmap.py` — карта кейнстрим-сегментов, finding: пересев каждые 32 Б;
- `solve_kb2.py` — вывод K=0x2BC1 и base=2 по 271 seed'у;
- `decrypt_blocks2.py` — контрольная расшифровка вокруг серий;
- `decrypt_mr5.py` / `../decrypted/decrypt_all.py` — полная расшифровка
  (одиночный файл / все 12);
- `jlfs_parse.py` — канонический парсер JLFS-записей с CRC-проверкой и
  извлечением app.bin (реализует jl_crc16 без зависимостей).

Ранние инструменты (история отрицательных результатов): `hdrmap.py`,
`entmap.py`, `scanmagic.py`, `rawdeflate.py`, `q32scan.py`, `pi32score.py`,
`xor32.py`, `bitlag.py`, `doubruns.py`, `rec64.py`, `tblcols.py`,
`jl_brute.py` и др.

## 7. Воспроизведение

```python
# суть дешифратора (decrypt_all.py)
def lfsr_stream(seed, n):
    out, s = bytearray(), seed
    for _ in range(n):
        out.append(s & 0xFF)
        s = ((s << 1) ^ (0x1021 if s & 0x8000 else 0)) & 0xFFFF
    return bytes(out)

K, R = 0x2BC1, 2
for bs in range(R, len(data), 32):          # + хвостовой блок первых 2 байт
    ks = lfsr_stream(K ^ ((bs - R) >> 2), 32)
    pt[bs:bs+32] = bytes(c ^ k for c, k in zip(data[bs:bs+32], ks))
```

Далее: `python tools/jlfs_parse.py <dec.bin> <outdir>` — записи контейнера.

## 8. Дизасм (ВЫПОЛНЕН)

- ISA **pi32v2**, little-endian, 32-бит; точка входа **0x06000100**
  (= начало `app.bin`; первое слово `ff ff` — маркер, код с 0x06000102).
- Использован открытый **аппаратно верифицированный** референс ISA
  `jvitkauskas/pi32v2-isa` (таблица `isa/pi32v2.toml` + objdump-кодек;
  подтверждено на железе AC791N). SLEIGH-спека `kagaimiq/ghidra-jieli`
  оказалась частичной — в Ghidra она декодирует слишком мало.
- Рекурсивный дизасм от точки входа (`tools/disasm_mr5.py`, следует
  call/goto-целям): **120 366 инструкций, 2 778 функций, 69.3 % байт**
  app.bin (остальное — таблицы данных/строки, недостижимые прямым потоком
  управления). Результат: `disasm/mr5_app_disasm.txt`.
- Точка входа (crt0) читается осмысленно: `sp = 0x103840`, `ssp = ...`,
  сохранение {r2-r0}, вызовы инициализаторов, очистка BSS (0x105540…),
  копирование .data из флеша в RAM (3884 + 44 080 байт), настройка `icfg`,
  затем `r0 = 0x06018310; goto r0` — переход в main.
- Пример функции (хвост, 0x0607f70e): стандартный пролог-эпилог pi32v2
  (`sp += -312`, байтовые загрузки `r9 = b[r6+1] (u)`, call) — код
  полностью консистентен.

## 8b. Полная SLEIGH-спека (ВЫПОЛНЕНО 2026-11-18)

Decode-only спека сгенерирована из таблицы `pi32v2-isa` скриптом
`tools/gen_sleigh.py` (части: `_gen_p1.py + _gen_p2.py + _gen_display_pcode.py +
_gen_p3.py`), выход — `gen/pi32v2_full.slaspec` (1171 конструктор, 169
токен-поля, 10 bt-сабтаблиц); скомпилированный `pi32v2_full.sla` установлен в
Ghidra (`Processors/JieLi/data/languages/pi32v2.sla`, бэкап оригинала —
`pi32v2_kagaimiq.*.bak`).

Результаты верификации (tools/compare_decode.py, `tools/branch_check.py`):
- декодировано 120 271 / 120 366 стартов листинга (**99,92 %**), критерий A1
  (≥ 95 %) закрыт; size mismatches = 0;
- branch-цели: 21 828 строк подтверждены формулой
  `target = (addr + size + value) & ~1`; остальные расхождения — только
  форматирование (hex vs десятичные, `{0x7}` vs `{r2-r0}`), целей по существу нет;
- self-check генератора: 114 branch-формул vs codec.value — 0 расхождений.

Ключевые технические решения (важно при доработке спеки):
- ОДИН 16-битный LE-токен `instr` (= чтение слова кодеком); многословные
  инструкции — через `;`-секции паттерна (как 6502/68000). Первая версия с
  BE-токенами t16/t32/t48 была ошибочной: BE-токен байто-свопит каждое слово
  относительно кодека → Ghidra матчил сдвинутые constraint'ы.
- Bit-порядок полей — по `field_bits` таблицы (порядок бит ЗНАЧЕНИЯ, MSB
  первым; может быть не позиционным, напр. call.xl: старший кусок в word2,
  младший в word1). Индекс слова закодирован в имени поля (`c16w1_0_7`).
- Spanning-цели (goto.l, call.l, call.xl, gotoss.xl) — dedicated-сабтаблицы
  `btN: res is ... { export *:4 res; }` с `res = expr + inst_next`:
  inv_w=0 (goto.l, call.l) → корень держит один word0-якорь + `... & btX`,
  остальные word0-constraint'ы уходят в сабтаблицу; inv_w>0 (call.xl,
  gotoss.xl) → корень хранит все секции (различающий constraint `c16w1_0_0`),
  секция inv_w получает `... & btX`, сабтаблица держит только куски офсета.
- Семантика — ветвления/вызовы/возвраты (реальный control flow) плюс
  p-code данных для 293/1171 форм (B1, см. §8d): флаговые условия через
  биты psr (N=3,Z=2,C=1,V=0), `??` → pcodeop cond_unspec, tbb/tbh читают
  таблицу через `*:1`/`*:2`, возвраты → `return [rets|rete|reti|retx]`;
  формы без семантики пока `{ }` (decode-only, 598 SIMD/DSP-форм — фаза 2).
- Гоча 1: `??`-условия не выражаются стандартными операторами → pcodeop
  cond_unspec(a:4, b:4) (не-регистровые аргументы требуют `:4`).
- Гоча 2: display, начинающийся с «голого» идентификатора поля, SLEIGH
  компилирует как литерал → префикс `""^`.
- Гоча 3: `;`-секции позиционны (секция k = токен k); `...` допустим только
  после одного constraint в своей секции; attach-списки — ровно 2^width
  значений; slaspec без BOM.

Инструменты: `tools/gen_sleigh.py` (генератор), `tools/debug_decode.py`
(пер-адресная отладка декода), `tools/compare_decode.py` (сравнение с
эталонным листингом), `tools/branch_check.py` (проверка branch-целей).

## 8d. B1: p-code данных (первый рабочий контур, 2026-11-18)

В `tools/gen_sleigh.py` добавлен компилятор выражений (`tools/_gen_pcode.py`):
синтаксис формы из таблицы pi32v2-isa → SLEIGH p-code. Покрыто **293/1171
форм** с семантикой (остальные 684 — decode-only, из них ~598 SIMD/DSP):

- скалярная ALU: mov/add/sub/and/or/xor/cmp и семейства rr-rrr (в т.ч.
  нестандартные abs/negs/umax/smax/umin/smin/sat8 через goto+labels), сдвиги,
  mul/div/remw;
- ld/st: b/h/w с `+offset`, post-inc `[sp++]`/`[r++]`, pre-dec `[--sp]`,
  pre-inc `[++r=n]`, накопители `++=`;
- константы: li.u8/neg5/modimm/s16/u32 (48-бит), запись в SR-литералы;
- rmw (read-modify-write), sp/usp/ssp-операции, cc→psr, testset (pcodeop
  testset_unspec), rep/swi (pcodeop), системные no-op'ы — пусто;
- не-смежные регистровые поля 4 форм add.rrr решены per-register
  сабтаблицами `rsN` (дисплей через `{ export rK; }`).

Технически: `imm_expr` даёт sized local (для simm — `t:2 = поле; t:4 =
sext(t)`); узкие store — через truncation `tm = (rhs):N`. Разделяемая
финализация `finish()` собирает объявления local + statements (все ветки,
включая rep/testset).

Результат: спека компилируется SLEIGH; декодирование не деградировало
(120 271/120 366 = 99,92 %, size mismatches = 0 — tools/compare_decode.py);
sr/pair-дисплей не изменился. Декомпилятор даёт осмысленный C на реальных
функциях (key_scan_send и др., см. `decomp_sample.c`; скрипт
`ghidra_scripts/DecompilerSample.java`). Флаговые формы (cmp с условием) пока
не пишут psr — точность флагов и SIMD/DSP — фаза 2 B1.

### B1.2: флаги psr для add/sub-семейств (2026-11-18)

Источник модели — `docs/COMPILER.md` из `jvitkauskas/pi32v2-isa` (аппаратно
верифицировано: psr биты N=3, Z=2, C=1 — у вычитания 1 = нет заёма, V=0 —
знаковое переполнение). Реализовано в `tools/_gen_pcode.py`:

- **add/sub/rsub/addc/subc** (все формы, включая `.p`-близнецы) пишут N,Z,C,V.
  C: `(res < a)` для сложения (беззнаковое, = перенос), `zext(a >= b)` для
  вычитания (нет заёма); V: `((a ^ be) & (a ^ res)) s< 0`, где `be` —
  b_eff (для addc/subc: b + carry-in); addc: C = c1 | c2 (перенос суммы +
  перенос от carry-in); subc: C = «нет заёма» = !((a < b) | (t==0 & !C)).
- carry-in-литералы дисплея `+ c` / `- !c` теперь компилируются
  (`zext(psr[1,1])` / `zext((psr[1,1]) == 0)`).
- Логика/сдвиги (N,Z / N,Z,C по модели) НЕ эмитятся: в MR5 нет ни одного
  `bc.*`-ветвления (0 в листинге), эти флаги мертвы; записи psr всё равно
  убил бы DCE декомпилятора. testset.b/rep — pcodeop'ы без флагов.

Важно: операторы сравнения SLEIGH беззнаковые по умолчанию (`<`, `>=`),
знаковые — `s<`, `s>=`; `u<` не существует.

Верификация: спека компилируется (297 форм с семантикой, +4); декодирование
без регресса (120 366 total, missing 95 = 0,079 %, size mismatches 0);
p-code `sub`/`subc` сверен по инструкциям (PsDump.java) с моделью COMPILER.md;
декомпил не засорён (0 упоминаний psr в сэмпле — DCE убивает мёртвые записи,
35 сайтов `rN = psr` — 64-битные сравнения — теперь получают корректный
dataflow). Проверка декода: `ghidra_dump_b12.txt` + compare_decode.

### B1.3: SIMD/DSP — pcodeop-заглушки + pair-регистры (2026-11-18)

Покрытие **1171/1171 форм**: 403 реальная семантика + 574 заглушки
`local sret:N = op_<form>(args…); dst = sret;` + ветвления. Механика
(`tools/_gen_p*.py`):

- **Pair-компаньоны**: 3-битные pair-поля получили companion-поля с
  attach_vars на 8-байтные регистры `r0_r1…r14_r15`; дисплей сохраняет
  порядок objdump (`r1_r0` = high,low). В p-code пары — настоящие varnode.
- **Реальная семантика**: `mov.pair`/`li.zero_pair` (64-бит COPY/очистка,
  `0:8`), `ld.d`/`st.d` — 16 форм 8-байтной памяти (снят запрет width==8
  в parse_mem). P-code st.d сверен: STORE размером 8 из pair-varnode.
- **Заглушки** (op_<id> с реальными операндами): pair-формы с расширением
  разрядности (mul.u.prr, div.*.ppr, shl3.pair — компилятор выражений не
  расширяет операнды, 32×32→64 усёкся бы), lane-compare `all/any/cmp[s]`
  → `all_eq(a,b)` и т.п., функции (`clz`, `popcnt`, `ftoi`, `rev8`,
  `align8`, `sat16`…) → pcodeop с result-temp, SIMD-формы с `+|+`/`<<<`/
  `><`/`<c>`, push/pop (sp не пишется — долг B1.4).
- **Гочаи SLEIGH**: (1) «голое» токен-поле и даже `zext(поле)` не имеют
  резолвимого размера как input callother — только присваивание в sized
  local (`local sarg1:4 = поле;`, паттерн imm_expr); (2) результат
  callother — тоже через sized local; (3) размер для pair-dst — 8 (kind
  поля 'pair', не имя varnode); (4) `u16w1`/`vp_*` — имена полей, а не
  регистров — attach_vars даёт размер.
- **Пойман тихий баг B1**: `r2 <<<= r1` (shl3.rr) компилировался как
  копия `r2 = r1` (`<<<=` был в ASSIGN_TOKENS, но отсутствовал в aarith-
  карте) — теперь заглушка op_shl3_rr. 403 vs прежних 407.

Верификация: slaspec компилируется (0 ошибок после 7 итераций); декод без
регресса (120 366 total, missing 95, size mismatches 0 — `ghidra_dump_b13b.txt`);
p-code: st.d (8-байтный STORE из pair), clz (CALLOTHER), shl3.rr (заглушка).

**Долг (не от B1.3)**: полный дизассембл при VerifyDecode (ещё в фазе B1)
затёр разметку данных в живом проекте (definedData 4073 → 0, instructions
106921 → 125726 — мусорные «инструкции» на данных). Бэкап
`ghidra_export/ghidra_proj_backup` содержит то же состояние. Разметка
воспроизводима скриптами A2/A4 — переразметить при случае (очистить код на
данных → прогнать A2/A4/B4 заново). Восстановлено в C4 (§8e), см. ниже.

### C4: восстановление разметки данных (2026-11-18)

Долг definedData закрыт: `ghidra_scripts/C4MarkData.java` по манифесту
`disasm/c4_manifest.json` (генератор `tools/c4_scan.py`):

- **Строки**: 2 426 из A4-набора `disasm/strings_for_ghidra.json`; все
  136 B2-якорей из `string_xrefs.md` уже внутри него (0 дополнений).
  Перед созданием данных поверх них очищаются мусорные «инструкции»
  (clearCodeUnits); terminated string при следующем NUL, иначе char-массив.
  Создано 2 422, 4 отказа (пересечения).
- **Таблицы указателей**: 11 плотных последовательностей u32 (≥2, шаг 4),
  цели — XIP-окно приложения, вне функций; всего 29 слотов
  (крупнейшая 06062efc ×5). Созданы как pointer32-массивы, 11/11.
- **Снято**: мотивы `10 20 40 80` / `30 60 c0` в дешифрованном образе
  отсутствуют (байтовый поиск: 0 хитов) — наблюдение из зашифрованного
  вида; подзадача удалена. Косвенных `goto rN` в листинге всего 4 —
  таблиц переходов в app.bin нет.

Итог: definedData 0 → 2 433, instructions 125 726 → 125 245 (мусор снят),
functions 3 222, references 13 414 (`headless_c4_stats.txt`). Декод без
регресса: `ghidra_dump_c4.txt` — 120 366 total, missing 95, mismatches 0.

### B4.2: ручное именование функций (2026-11-18)

**29 имён применено** (из манифеста 31; 2 адреса — Ghidra не создаёт
функции). Инфраструктура: `tools/b42_collect.py` → `disasm/b42_funcs.json`
(2 554 функции, call-граф 5 055 рёбер, 398 функций со строками;
imm→строка с дистанцией), `tools/b42_names.py` →
`disasm/b42_manifest.json`, `ghidra_scripts/B42Apply.java`,
досье `tools/b42_dossier.py`, C-тела `tools/show_c.py`.

- **11 экспертных** (asm-разбор, цепочки в `findings/B4_2_names.md`):
  dut_tst-кластер собран целиком — `dut_tst_cmd_handler` (0600ba7c,
  2 742 Б, главный диспетчер DUT+TST+*SET, косвенный вызов),
  `dut_tst_get_resp` (06013202), `dut_tst_get_send` (06014348),
  `dut_tst_strtbl_get_a/b` (060109f0/06010a06, таблицы
  06062ba4/06062b94 «режим → команда»); эффекты — `effect_cfg_mgr`
  (0605312e, 5 282 Б), `effect_nodes_open/close` (0600e3d8/0604c65c),
  `jlstream_res_init` (0604b08e); ресурсы — `ota_file_lookup` (06072d92,
  таблица Zedr_ota2.bin/…), `sdfile_dev_tbl_scan` (060724f4, не создана).
- **18 по строкам** (B4-конвенция `f_<строка>` с фильтрами: шум общих
  таблиц — 79 строк; бинарный мусор — маркеры/дистанция ≤128 Б).
  Пять скрытых стартов функций созданы (`AddHiddenFuncs`,
  bookmark `hidden-func-B42`).
- Не 100–200: B3 (SDK-сигнатуры) заблокирован; остаток — 060724f4,
  06074948 (создание функции не удалось), 06013cf2 (вне программы).
- **Порядок операций (урок)**: `AddHiddenFuncs` (DisassembleCommand по
  потоку) затёр разметку данных C4 (definedData 2 433 → 0, инструкции
  +481) — разметка данных всегда последней, либо после любых
  дизассемблирующих скриптов перезапускать `C4MarkData.java`
  (манифест `disasm/c4_manifest.json` сохранён; восстановлено).

### D2.2: function-level дифф семейства (2026-11-18)

`tools/d22_funcdiff.py` + `tools/d22_twindiff.py`, отчёт
`findings/D2_2_funcdiff.md`:

- **MR5 ↔ MR4.5/MR4_MKII**: из 116 именованных функций 2 идентичны,
  11 почти идентичны (sim 0.89–0.99 — модельные константы), 103 заметно
  различаются (между поколениями код реально менялся). Ловушка: размер
  функции брать из листинга (`b42_funcs.json`), а не из `functions.csv`
  (decode-only тела Ghidra — 4–44 Б).
- **Близнецы MR4.5 ≡ MR4_MKII**: при размере app.bin 572 028 Б различий
  всего **8 байт** (0.0014 %), три области: константа инициализации
  дефолтов (35 vs 42; MR5 — 58, эквивалент `sub_060047d0`), параметр
  конфига эффектов (99 vs 106), имя модели (`EDIFIER MR4.5` vs
  `EDIFIER MR4 MKⅡ`, UTF-8 U+2161). Модельная специфика близнецов
  исчерпывается этими тремя точками.

### B3: SDK-сигнатуры (2026-11-18)

**304 SDK-функции названы** (`findings/B3_sdk_signatures.md`). Источники
найдены публично: AC701N soundbox SDK (`cpu/br28/tools/sdk.elf` —
слинкованный pi32v2 ELF с 4 142 FUNC-символами, rom.lst, sdk.map),
AC695N SDK (br23); AC791N — RISC-V, не годится. Метод
`tools/b3_sigs2.py`: точный байт-матч (24-Б якорные окна по телу,
допуск ≤20 % 8-байтовых слов; `.a` SDK бесполезны — их `.o` хранят
LLVM bitcode). 134 адреса не были функциями Ghidra — созданы
(`AddHiddenFuncs`); применено 304/304, коллизий 0. functions 3 227 →
**3 361**. Примеры: `ccm_memory_v2`, `ASCII_StrCmp`, `sdfile_*`,
`OS*`, `lmp/sdp/rfcomm/l2cap`, `__stub_memcpy/memset` (по rom.lst).
Дальние вызовы: 3 342 сайта к 175 целям за XIP; цели 0x10xxxx —
RAM-функции (35 опознаны байт-матчем), точная карта оверлеев — через
копи-таблицу crt0 (будущая задача). Остаток: 2 899 функций sdk.elf не
совпали (SDK Edifier новее, jlstream-поколение не опубликовано) —
инфраструктура готова к повторному прогону.

### B3.1: RAM-оверлеи через копи-таблицу crt0 (2026-11-18)

`tools/b3_overlay.py` (+ `_names`, `_chain`, `_finalize`), отчёт
`findings/B3_1_ram_overlay.md`:

- **Копи-таблица — инлайн-циклы crt0**: BSS 0x105800 (15 712 Б),
  copy1 RAM 0x104840 ← 0x060834a0 (3 884 Б), copy2 RAM 0x1094e0 ←
  0x060843cc (44 080 Б, ядро ОС/btctrler), + пустой copy в 0x02000000.
- **Все 175 дальне-вызовных целей (3 342 сайта) классифицированы**:
  154 RAM — смапплены в flash-эквиваленты через copy2 (валидация 100 %:
  имена из независимого байт-матча легли на предсказанные адреса);
  21 ROM-стаб `__stub_*` по br28 rom.lst (вызов = метка+2).
- **Именовано 39/175**: `os_enter_critical`/`os_exit_critical` (812
  сайтов; пер-ядерные счётчики вложенности 0x1083dc/ec, маска IRQ
  0xffe1a8+cnum*0x800), `p33_soft_reset`, `delay_loop`, `os_sem_create`,
  `__tcnt_us`, `sfc_suspend`, `mpu_enter_deep_sleep`, …
- Декомпиляция 139 flash-эквивалентов → `disasm/b3_overlay_decomp.c`;
  в Ghidra создано 115 функций оверлея (bookmark `hidden-func-B3overlay`).
  Итог: functions=3 476, instructions=130 589.
- Не резолвится без дампа ROM: вызовы в P33/PMU-окна (0x0bfa****/0x05f9****).

### B3.2: экспертная идентификация оверлея (2026-11-18, план NEW2 фаза F)

`tools/b5_dossier.py` + `b5_names.py`, отчёт `findings/B3_2_overlay_expert.md`:

- **Ядро ОС = uCOS-II** — доказано структурно: OSEventType (2=sem, 3=mutex
  по `ucos_ii.h` публичного SDK), ready-list `0x108228[prio*8]` + bitmap
  `0x108210`, per-core счётчики `0x1083dc…`, spin-lock `testset 0x108404`.
- **24 имени** (`disasm/b5_names.json`, применены `B5Apply.java`):
  high: `os_mutex_create/pend/post`, `os_sem_pend/post`,
  `os_task_ready/unready`, `os_event_task_unlink`, `os_critical_nest_get`,
  `os_spin_lock/unlock`; med: `os_taskq_post(_core)`, `os_time_dly`,
  `os_sched`, `sysclk_cs_enter/exit` (PLL+SFC, 487 сайтов), `os_sem_del`;
  low: `delay_ms`, `sys_time_ms`, PMU-обёртки (0x0BFAxxxx, без дампа ROM
  не резолвятся).
- Цели дальних вызовов: **53/175 именованы**; досье всех 136 +
  декомпилы (`disasm/b5_dossiers.md`, `b5_helpers_decomp.c`).

### C1.2: stream.bin — аудио-граф и конфиги эффектов (2026-11-18)

В ресурсном хвосте найдены три вложенных JLFS-тома: `cfg_tool.bin` (234 Б),
`p11_code.bin` (12 КБ) и **`stream.bin`** (61 820 Б, hdr@tail+0xc394,
данные tail+0xc3b4) — это «effect_cfg». Полный разбор: `tools/stream_parse.py`
→ `findings/C1_audio_graph.md` + `.json`. TLV-поток `tag:u16|len:u16|payload`:
tag 0 — 176 рёбер графа (crc16, u16); tag 2 — 62 имени
(`tag 0x0013|crc16|param u8|name[16]`); tag 5 — хранилище конфигов
(246 дескрипторов × 32 Б: type|crc16|param|id_a|id_b|idx|block_off|stride;
тип 1 = EQ, блок 200 Б = count × `{band|type|freq u32|Q float}`; тип 2 = DRC,
76 Б float; тип 3 = гейны, 12 Б float в дБ). Узел адресуется парой
(crc16 jl_crc16, param). Не разобраны: tag 0 w-семантика, tag 3/6/8/10,
групповые записи 04/05/07.

## 8c. Разметка программы в Ghidra (A2/A4/B4, 2026-11-18)

- **A2**: RAM-блок 0x100000–0x13FFFF (uninitialized) создан по следам crt0
  (sp=0x103840, BSS 0x105780+0x3D60, .data → 0x104840/0x1094E0);
  `ghidra_scripts/A2CreateRam.java`. Автоанализ (Decompiler Parameter ID
  отключён — p-code decode-only): функций 2812 → 3068, references 11 868.
- **A4**: `tools/prep_strings.py` отобрал 2 426 строк, не пересекающихся с
  декодированными инструкциями (из 6 072); `A4MarkStrings.java` создал
  1 657 строк (terminated string при следующем NUL, иначе char-массив),
  206 уже были определены автоанализатором, 563 лежат внутри инструкций
  (кандидаты «данные, дизассемблированные как код» — отдельный разбор).
  Остаток A4: u32-таблицы (мотивы `10 20 40 80` / `30 60 c0`).
- **B4**: `B4Rename.java` — 13 якорных функций из §4 `findings/B2_anchors.md`
  (key_scan_send, mcu_msg_send, dut_tst_cluster*, bt_name_config,
  jlstream_cluster, music_eq_*, set_hp_gain, usb_stack_cluster, tone_load)
  + 91 функция по карте «функция → строки» `disasm/function_strings.json`
  (имена `f_<строка>`, plate comment со списком строк-доказательств);
  коллизий 0, не найдено 9 адресов (в т.ч. sub_06013cf2 — вне программы).
- Гоча headless: несколько `-postScript` — по одному на скрипт (иначе
  хвостовые скрипты съедаются как аргументы первого); числовые аргументы
  PowerShell калечит (ведущие нули) — передавать через файл.

## 8a. Как повторить дизасм

```bash
pip install tomli  # или python3.11+
git clone https://github.com/jvitkauskas/pi32v2-isa
python disasm_mr5.py source/decrypted/app.bin out.txt   # tools/disasm_mr5.py
```

Скрипт использует `pi32v2isa.table.load()` + `objdump.Decoder`; цели
ветвлений: `target = (addr + insn_len + field_value) & ~1` (для
call/goto-форм с полем `{n}`; см. `BRANCH_FIELD` в objdump.py).

## 9. Исторические результаты (до взлома)

Сохранены как история поиска (детали в git-истории отчёта и в `tools/`):

- «Заголовок 0x000–0x205 — плейнтекст» — на деле он SFC-зашифрован тем же
  ключом; его «общность» у 12 моделей — следствие детерминированного шифра
  над общим плейнтекстом.
- «Хвост — фазовый аккумулятор/DDS» — на деле кейнстрим LFSR на нулевом
  плейнтексте (именно он дал ключ, §2.2).
- Отрицательные результаты остаются в силе: не компрессор (zlib/lzma/lz4/
  zstd/bz2/raw-deflate брутфорс — пусто), не голый newfw ENC-LFSR
  (65 536 ключей × варианты — пусто; не хватало адресного seed'а SFC),
  не простые накопительные/дельта-преобразования, не S-box, не 7-битные
  символы. Брутфорс SFC по энтропии кодовой зоны тоже не работал бы:
  код JieLi высокоэнтропиен сам по себе.

## 10. Источники

- `jvitkauskas/pi32v2-isa` — **открытый аппаратно верифицированный референс
  ISA pi32v2**: таблица инструкций, ассемблер, линкер, objdump; им выполнен
  дизасм (§8).
- `ElectronicCats/jieli-ble-badge-research` — схема SFC-скремблера
  (`jl_sfc_decrypt.py`), идея 16-битного chipkey.
- `kagaimiq/jl-misctools` — канонические `jltech/cipher.py` (`jl_sfc_cipher`)
  и парсер JLFS (`fwunpack_newfw.py`); формат записей и CRC сверены с ними.
- `GizClaw/AC695N_Soundbox_SDK` — эталонные plaintext/шифрованные образы
  (jl_isd.bin, update.ufw, std_app.bin), isd_config.ini (ENTRY=0x1E00100).
- `kagaimiq/ghidra-jieli` — SLEIGH pi32v2/q32s для Ghidra.

## 11. DSP_ARCH — DSP-подсистема MR5 (2026-11-18)

Полный разбор DSP вынесен в `DSP_ARCH/` (README, DSP_ALGORITHMS, SIGNAL_PATHS,
POWER_AMP, EQ_TABLES + decomp/ и tools/). Ключевое:

- Граф jlstream: 16 шаблонов узлов (crc djb2 seed 0x1505 x0x21), 62 имени =
  инстансы (param), 176 записей графа, 246 конфиг-дескрипторов (185 EQ /
  2 DRC / 59 GAIN). Конфиги: заводские в stream.bin (tag 5), текущие в
  конфиг-БД spi-flash (FUN_06037ba4/cce, ключ {type,crc32(name),param}).
- Алгоритмы: EQ би-квад типов 0..8 (audio_eq_tab_check 06065808, генераторы
  06040e64..06041594), DRC peak-follower (DrcPeakFollowProcess 06085848,
  drc_db2mag 06085550, DrcCalcTimeFactor 0604e496), микшер cfifo (0604bea4),
  premute 0604dc98. Слоты EQ: тембр Bass -6..+6 дБ @125 Гц (26 табл.),
  Treble -6..+6 дБ @10 кГц (13), Desk_Acoustic_2 (pk@200+t4@500), EQDIY x4.
- Громкость: digvol-шаблон 0x74e3, 9 кривых по источникам
  (BT -70..-7 дБ, Line -63..0 дБ ...). Гейны: SET_HP_GAIN +8.3 дБ /
  -90.3 дБ (mute), SET_HP_GAIN2 +2.3 дБ, AUX_DAC_GAIN 0/-1.3 дБ,
  AUX_DAC_GAIN2 +6.5 дБ.
- Выходы: 4 инстанса DAC (DAC2/DAC3/DAC24/DAC25, tri-amp НЧ/СЧ/ВЧ +
  наушники), IIS0_TX1/3/4. Наушники через SET_HP_GAIN, mute -90.3 дБ.
  Управление PA/anti-pop — стробы PORTA (0xfd5000 OUT / 0xfd5008 DIR):
  PA1 (bit2), PA6 (bit40) из set_hp_gain 06006390 и 06009ebc.
- Источники: A2DP_RX6/7 (BT music), esco_adc+EscoUl/DlEq (разговор),
  ADC13/linein (Line In задний + XLR, XLR — тот же тракт с усилением
  AUX_DAC_GAIN2 +6.5 дБ), AUX фронтальный. Переключение — effect_nodes_open
  0600e3d8 (site 06018e4a) + стабы узлов 06001dba-06001e76 ->
  node_param_set FUN_06038bd8 (46 сайтов).

Инструменты: DSP_ARCH/tools/*.py (шаблоны узлов, дамп конфигов, EQ-таблицы),
CallersDump.java (ghidra_scripts), декомпиляты DSP_ARCH/decomp/.

## 12. Flash-layout: origin of effect configs (2026-11-18)

Answered the «effect_cfg ≡ resource tail volume» hypothesis: **REFUTED**.
The TLV volume from C1.2 (hdr@0x9B390) is the embedded flash file
**stream.bin** (jlfs inode: magic 0x4C689141, hdr 0x20, size 0xF17C, name
inside the inode; ends exactly at EOF 0xAA50C).

Embedded jlfs files found in the tail (packed end-to-end, size = inode+data):
- `cfg_tool.bin` @0x9831E, 234 B, id 0xED909943 — product config
  (soundbox / JL701N / 1.0.0 / patch_01, BT MAC A4:DB:A5:DB:A6:DB,
  device name **EDIFIER MR5**);
- `p11_code.bin` @0x98408, 12 168 B, id 0x3B4FF3FC — P11 (PMU/touch) core code;
- `stream.bin` @0x9B390, 61 820 B, id 0x4C689141 — audio graph + factory
  effect configs (already decoded in C1.2 / DSP_ARCH).

Chain check: 0x9831E+0xEA=0x98408 → +0x2F88=0x9B390 → +0xF17C=0xAA50C=EOF ✓.

`flash/res/effect_cfg.bin` is referenced by code (VA 0x0605FAAF, near tag
`bt_test.base`; `flash/res/stream.bin` @0x0605FEFA near task tags
`aec`/`jlstream`) but its inode is NOT in our dump — needs full OTA/ufw or
service flash dump. Factory effect values are already covered by stream.bin;
only the user-override layer is missing.

NEW uncovered code region: dec 0x8EEFC..0x9831E (VA 0x0608EFFC..0x0609841E,
~37.9 KB) is continuing XIP pi32v2 code NOT covered by app_bin_full.bin
(current Ghidra project ends at 0x8EEFC). Rebuild project on the full
MR5_1.0.3_1c89dcaf_dec.bin for full coverage.

Details: `DSP_ARCH/FLASH_LAYOUT.md`.

## 13. STOCK_MODS — модификационные поверхности стока (2026-11-18)

Вопрос: что можно выжать из стока без перепрошивки — max L/R PEQ, мьют
источника (ADC1/BT), наушники как SUB-OUT. Ответ в `DSP_ARCH/STOCK_MODS.md`.

- Главный примитив: `node_param_set` `FUN_06038bd8(crc_шаблона, имя_узла,
  buf, len)` — запись параметра любого узла графа в рантайме; устройственный
  код сам им пользуется (f_config397392: digvol 0x74e3 + gain 0xa904 12 Б;
  dut_tst_cluster @0600ac08: EQ 0x737b, buf 0x24).
- Формат gain-параметра (0xa904): 8 нулевых байт + f32 дБ.
  SET_HP_GAIN +8.3 / −90.3 (mute), SET_HP_GAIN2 +2.4 (0x40133333),
  AUX_DAC_GAIN 0/−1.3, AUX_DAC_GAIN2 +6.5.
- PEQ-ёмкость: все 17 EQ-слотов имеют ровно 12 бэндов (stride 200);
  11 слотов существуют отдельными L/R-инстансами (EQDIY×4, Desk_Acoustic×2,
  BassShelf/TrebShelf_LB3/LB4, EQ17) → потолок 132 полосы/канал в музыке.
  Валидатор audio_eq_tab_check: типы 0..8.
- Мьют источника: mute-гейн −90.3 дБ на узел тракта через node_param_set;
  либо DUT/AT-канал прод. тестов: f_tst_btn_sta @06018a8e парсит ASCII-
  команды ("TST+BTN+STA", "DUT+TST+TXS+0/1", "DUT+TST+DUT+0",
  "TST+LED+IO1..3+n", "DUT+TST+SAV+00/01", "DUT+TST+VER+GET+") и две
  десятичные цифры превращает в прямой вызов effect_nodes_open(N) (N<0x4F).
  Транспорт канала (UART/BLE) не атрибутирован ⚠️.
- HP→SUB: расмьют SET_HP_GAIN + LPF через свободный EQDIY-слот
  (type 1/3/7 @80–120 Гц) — firmware-часть решаема; аппаратный предел —
  разделительные конденсаторы HP-выхода при низкоомной нагрузке (fc до
  ~180 Гц @ 4 Ом) — годится только на высокоомный вход сабового усилителя.
- Безопасность: DUT-канал + открытая конфиг-БД = одновременная поверхность
  атаки (перезапись конфигов, переключение режимов без аутентификации).

## 14. DSP.html — хак-инструмент управления DSP (без перепрошивки)

Коммит 9edce25. Итоговый артефакт: `DSP.html` (репозиторий, ~34 КБ, единый файл).
Макет — EdifierConnectX/ai_studio_code.html (только вёрстка), логика — из DSP_ARCH.

### 14.1 Уточнение формата ключа узла (важно)
- В tag2/tag5 stream.bin поле crc — это djb2 **имени шаблона**, а не инстанса.
  Проверено прямым вычислением: EQ=0x737B, Gain=0xA904, DAC=0xDCCD, DRC=0xDEFE,
  MIXER=0xE62A, ADC=0xD06D, A2DP_RX=0xF975, IIS0_TX=0x69A5, MIC=0xD0BC.
  djb2(имя_инстанса) (напр. "EQDIY"=0x30A1, "Vol_BtmMusic"=0x17D9) crc-полю НЕ равен.
- Ключ узла в графе/конфиге = (crc шаблона, param); у L/R-пар инстансов
  param_R = param_L + 256 (кроме DAC).
- Раскладка tag2-записи (21 Б): {len=0x13 u8, 00 u8, crc u16, param u8, name[16]}.
  Ранние парсеры читали crc со смещением +2 — фактически crc @+2 от len-поля,
  т.е. @байт 2 записи; имя @байт 5.
- Имена остальных шаблонов (0x74e3 digvol, 0xa248, 0xda15, 0x6963 IIS0_RX, 0xeb56,
  0x9b3b, 0xa576, 0xd911, 0x7de5, 0xed7f, 0x1ecd, 0x7674, 0x768a, 0x1a85, 0x0a2c)
  строковым перебором/сканом .rodata не восстановлены (возможно, существуют только
  в хост-конфигураторе JieLi). На функциональность не влияет: используется числовой crc.

### 14.2 Состав DSP.html
1. Транспорт: Web Bluetooth (SVC 48093a01-…, notify …0001 / write …0002), сырые
   app-кадры `AA app op len payload crc8`, DUT-терминал ASCII (транспорт не
   атрибутирован — помечено в UI).
2. Режимы/мьюты: DUT+TST+TXS+nn (effect_nodes_open), SAV, мьют-пейлоады
   digvol (0x74E3) Vol_BtmMusic=92 / Vol_LinMusic=81, −90.3 дБ = заводской mute.
3. HP→SUB-визард: LPF (type 1) band0 + SET_HP_GAIN-компенсация, предупреждение
   об ограничении разделительных конденсаторов HP-выхода.
4. PEQ Studio: 17 слотов × 12 бэндов, типы 0–8, АЧХ-превью (RBJ), слоты
   помечены активностью в BT-цепи (EQDIY 51/59 + Desk_Acoustic 62 + Shelf 57/58).
   Экспорт: BLE 0x44/0x46 (app-протокол), нативный 200-Б блок EQ, cfg-DB blob
   (32-Б дескриптор + блок).
5. Gain-лаборатория: 12-Б пейлоад (8×00 + f32 дБ), заводские значения.
6. cfg-DB: crc/desc/node_param_set-генератор (FUN_06037cce/06037ba4).
7. Карта графа из tag10 (8 строк: каналы 0/3/4/6/7/10/13/17).

### 14.3 Статус
- Форматы байт-точные (сверены с stream.bin): EQ 200 Б = 8-Б шапка
  {00 00 00 00 00 0C 00 00} + 12×{band u16, type u16, freq f32, gain f32, Q f32};
  gain 12 Б; digvol 136 Б.
- Доставка параметров по BLE не подтверждена на живом аппарате (op 0x2B/0x44/0x46 —
  гипотезы из app-протокола); cfg-DB blob и DUT-команды — рабочие пути.
- Бандл edifier_re.bundle обновлён (9edce25).
