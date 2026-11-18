# B3 — SDK-сигнатуры: результаты (2026-11-18)

## 1. Источники (найдены публично)

| источник | что внутри | статус |
|---|---|---|
| **AC701N soundbox SDK** (`UWINGS-KUNYI/ac701n_soundbox`, github) | `cpu/br28/tools/sdk.elf` — слинкованный образ pi32v2 **с символами** (4 142 FUNC), `rom.lst` (ROM-символы до 0xf4348), `sdk.map` | основной |
| AC695N Soundbox SDK (`GizClaw/AC695N_Soundbox_SDK`) | `cpu/br23/tools/sdk.elf` (3 816 FUNC), rom.lst 0x110000..0x1127fc | доп. |
| fw-AC791N SDK (`GizClaw/fw-AC791N_SDK`) | cpu/wl82 — **RISC-V**, другое ядро | не годится |

Поколение SDK определено: MR5 = br28 (AC701N)-родственная платформа:
якоря `btctrler`/`app_core`/`SDFILE` общие; но `jlstream`/`EnergyDet`/
`JL_A2DP`/`app_dir_head` в публичных SDK отсутствуют — Edifier собран на
более новой (или кастомной) версии SDK. Тем не менее библиотеки (btstack,
btctrler, fs, OS, codecs, crypto) байт-в-байт совпадают местами.

## 2. Метод

`tools/b3_sigs2.py`: из `sdk.elf` извлекаются все FUNC-символы с кодом
(полностью слинкованный ELF — байты финальные, без релокаций); код
функции ищется в `app_bin_full.bin` точным вхождением 24-байтных якорных
окон (начало/шаг 24/середина/конец); принимается единственное
согласованное попадание + проверка ≤20 % различающихся 8-байтовых слов
(допуск флагов компиляции). `.a`-библиотеки SDK бесполезны напрямую — их
`.o` хранят **LLVM bitcode** (`BC\C0DE`), не машинный код.

## 3. Результат: 304 именованные функции — ✅ все применены

- br28 sdk.elf: **295** уникальных байт-совпадений (из 4 142 функций;
  180 неоднозначных, 2 899 отсутствуют — другая версия/флаги).
- br23 sdk.elf: +9 новых.
- Примеры: `ASCII_StrCmp`, `__syscfg_read`, `sdfile_str_to_upper`,
  `sdfile_strcase_cmp`, `__write_reg_bdaddr`, `link_conn_set_encrypt`,
  `ccm_memory_v2` (mbedTLS), `clkn0_phase`, `bredr_set_frame_bitoff`,
  `drc_db2mag`, `OSGetTaskTcb`, `os_sem_create`, `sfc_suspend`,
  `p33_soft_reset`, `mpu_enter_deep_sleep`, `clust2sect`, `u_delay`,
  `spi_writebyte`, `vmalloc_`/`vfree_`/`OSCtxSw` (RAM-копии), mp3/mad
  (декодер), lmp/sdp/rfcomm/l2cap (BT-стек).
- Манифест: `disasm/b3_signatures.json`; применено в Ghidra
  (`ghidra_scripts/B3Apply.java`): 134 адреса не были функциями в Ghidra
  (decode-only анализ) — функции созданы (`AddHiddenFuncs`,
  bookmark `hidden-func-B3`), затем все **304/304 переименованы**,
  коллизий 0. Итог: functions 3 227 → **3 361**, definedData 2 433
  (восстановлена после дизассемблирования — C4MarkData),
  references 13 563.

## 4. Дальние вызовы (ROM/RAM)

3342 call-сайта уходят за пределы XIP к 175 целям:

- `0x1fd76/0x1fd82` = `__stub_memcpy`/`__stub_memset` (br28 rom.lst).
- Цели `0x10xxxx` (основная масса: 0x10dbcc ×434, 0x10db7e ×378 — это
  **RAM**-область 0x100000–0x13FFFF, блок A2): функции загружаются из
  flash в RAM при загрузке; 35 RAM-функций naming-а байт-совпали с
  sdk.elf (`OSCtxSw`, `vmalloc_`, `sfc_suspend`, …), но линейной карты
  «offset во flash → RAM-адрес» нет (оверлеи, дельты скачут) — точное
  соответствие целей требует разбора копи-таблицы crt0 (будущая задача).
- Цели `0x11000c…0x1140f2` — ROM старше br28 (у br28 ROM до 0xf4348;
  у br23 ROM начинается с 0x110000) — маска ROM MR5 иная; br23 rom.lst
  покрывает 0x110000–0x1127fc частично.

## 5. Ограничения и следующие шаги

1. 2 899 функций sdk.elf не совпали — Edifier's SDK версия новее;
   при появлении более свежего SDK (jlstream-поколение) прогнать
   `b3_sigs2.py` ещё раз — инфраструктура готова.
2. Разобрать копи-таблицу crt0 → реконструкция RAM-образа → имена
   175 дальне-вызовных целей (снимет шум со всех функций, вызывающих
   memcpy/alloc).
3. `sdk.map`/`sdk.lst` (43 МБ дизассемблер с символами) — резерв для
   fuzzy-matching по структуре, если понадобится.
