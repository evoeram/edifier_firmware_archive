# Edifier Firmware Archive — reverse engineering workspace

Репозиторий переносит всю работу по реверсу прошивок Edifier (JieLi
pi32v2) на другую машину. Основной кейс: **MR5 1.0.3** (`1c89dcaf`).

## Структура

```
├── MANIFEST.csv/.json, catalog_products.json   # каталог прошивок + зашифрованные образы (см. download_firmware.py)
├── download_firmware.py                        # скачивание/расшифровка прошивок
├── decrypted/                                  # расшифрованные образы 12 моделей (*_dec.bin)
├── DISASM.7z                                   # архив первичного дизассемблера (этап A)
├── API_NOTES.md, README.md
└── firmwares/
    └── MR5_1.0.3_1c89dcaf/
        └── source/                             # ← ВЕСЬ рабочий контекст
            ├── REVERSE_ENGINEERING_PLAN_NEW.MD     # основной план (A–E, статусы)
            ├── REVERSE_ENGINEERING_PLAN_NEW2.MD    # план фазы F (RAM-оверлей)
            ├── ANALYSIS.md                         # журнал + выводы (§8, B3, B3.1, B3.2…)
            ├── findings/                           # отчёты B2/B3/B3_1/B3_2/B4_2/C1.2/D2.2/…
            ├── tools/                              # python-инструменты (70 шт.)
            ├── disasm/                             # листинг, манифесты, JSON-слои, декомпилы
            ├── ghidra_export/                      # functions.csv, mr5_decomp_all.c, named_functions.md
            ├── gen/                                # генератор slaspec (B1.3 p-code)
            ├── decrypted/                          # app.bin, app_bin_full.bin (образ для Ghidra)
            ├── ghidra_scripts/                     # все headless-скрипты (java/py) + адресные файлы
            ├── ghidra_proj_snapshot/               # ГОТОВЫЙ Ghidra-проект (MR5 / app_bin_full.bin)
            └── ghidra_language_JieLi/              # модуль процессора JieLi/pi32v2 (с B1.3 p-code)
```

## Быстрое развёртывание на новой машине

1. **Установить JDK 21 + Ghidra 12.2 PUBLIC**
   (использовалась: `ghidra_12.2_PUBLIC`, путь в скриптах не зашит жёстко).
2. **Установить языковой модуль** — скопировать:
   ```
   firmwares/MR5_1.0.3_1c89dcaf/source/ghidra_language_JieLi
     → <ghidra>/Ghidra/Processors/JieLi
   ```
   (модуль уже содержит собранный `pi32v2.sla` с p-code B1.3; при
   необходимости пересборки — `gen/gen_sleigh.py` → `pi32v2_full.slaspec`
   → скопировать в languages-каталог).
3. **Разместить проект Ghidra** (или открыть прямо из снапшота):
   ```
   firmwares/MR5_1.0.3_1c89dcaf/source/ghidra_proj_snapshot
     → C:\Users\<u>\AppData\Local\Temp\opencode\ghidra_proj
   ```
   Внутри: проект `MR5`, программа `app_bin_full.bin` — состояние на
   конец сессии (3 509 функций, 130 589 инструкций, все имена применены).
4. **Типовой вызов headless** (один headless за раз!):
   ```
   <ghidra>\support\analyzeHeadless.bat <путь>\ghidra_proj MR5 ^
     -process app_bin_full.bin -noanalysis ^
     -scriptPath <репо>\...\source\ghidra_scripts ^
     -postScript <Script>.java <args>
   ```
5. **Python** — только стандартная библиотека. Инструменты:
   `source/tools/*.py` (якоря, диффы, сигнатуры SDK, оверлеи).

## Порядок восстановления анализа с нуля (если снапшот не используется)

1. Import: `analyzeHeadless <proj> MR5 -import source/decrypted/app_bin_full.bin -processor pi32v2:LE:32:default`
2. Рекурсивный дизассемблер по потоку (этап A, см. ANALYSIS.md §A).
3. Скрипты по фазам плана: `A4MarkStrings` → `B4Rename`/`B42Apply` →
   `B3Apply` (SDK-сигнатуры) → `C4MarkData` (разметка данных — всегда
   последней после любых дизассемблирующих скриптов!) → `StatsDump`.
4. Контроль: `VerifyDecode` + `compare_decode.py`
   (120 366 инструкций, missing 0.079 %, mismatches 0).

## Эталонные SDK (не входят в репо, скачать при необходимости)

- AC701N soundbox (br28, pi32v2, **sdk.elf с символами**):
  `https://github.com/UWINGS-KUNYI/ac701n_soundbox` — файл
  `sdk/cpu/br28/tools/sdk.elf`, `rom.lst`, `sdk.map`. Ожидался в
  `%TEMP%\opencode\sdk\ac701n\...`
- AC695N Soundbox SDK (br23): `https://github.com/GizClaw/AC695N_Soundbox_SDK`
- fw-AC791N (RISC-V, не годится для pi32v2): `https://github.com/GizClaw/fw-AC791N_SDK`

Инструменты, которым нужны эталоны: `tools/b3_sigs2.py` (путь к sdk.elf
передаётся аргументом), `tools/b3_overlay_names.py` / `b3_overlay_chain.py`
(константа SDK_ELF внутри — поправить под новое расположение).

## Ключевые документы

- `firmwares/MR5_1.0.3_1c89dcaf/source/ANALYSIS.md` — вся история и выводы
- `findings/B3_sdk_signatures.md` — 304 SDK-функции
- `findings/B3_1_ram_overlay.md` — копи-таблица crt0, 175 дальних вызовов
- `findings/B3_2_overlay_expert.md` — uCOS-II ядро, 24 экспертных имени
- `findings/D2_2_funcdiff.md` — семейный дифф (близнецы MR4.5 ≡ MR4 MKII)
