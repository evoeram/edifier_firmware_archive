# B3.1 — Реконструкция RAM-оверлеев через копи-таблицу crt0 (2026-11-18)

## 1. Копи-таблица crt0

Таблица — **инлайн-циклы** в crt0 (`0x06000102`–`0x0600018c`,
`disasm/mr5_app_disasm.txt`), не дата-таблица. Разбор
(`tools/b3_overlay.py`, `parse_crt0_copies`):

| # | тип | dst (RAM) | src (flash VA) | size |
|---|---|---|---|---|
| 0 | zero (BSS) | 0x105800 | — | 15 712 |
| 1 | copy | 0x104840 | 0x060834a0 | 3 884 |
| 2 | copy | 0x1094e0 | 0x060843cc | 44 080 |
| 3 | copy | 0x02000000 | 0x0608ef7c | 0 (заполняется позже) |

Далее: `icfg`-настройка, `call 23238`, ROM-вызов, `goto 0x060182d0` (main).

Copy2 (RAM 0x1094e0..0x1140f0 ← flash 0x060843cc..0x0608eefc) ровно
покрывает диапазон главных RAM-целей дальних вызовов — гипотеза
«дальние вызовы уходят в RAM-код, скопированный из flash» подтверждена.

## 2. Дальние вызовы

3 342 call-сайта → **175 уникальных целей** за пределами XIP
(`tools/b3_overlay.py`, `disasm/b3_far_targets.json`):

- **154 RAM-оверлей** (0x10xxxx) — смапплены в flash-эквиваленты через copy2.
- **21 ROM** (0x1fd6e..0x1fe32 + 0x2) — стабы `__stub_memcpy`,
  `__stub_memset`, `__stub_memcmp`, `__stub_strlen`, `__stub___adddf3`,
  `_start` и др. по меткам `rom.lst` (br28); вызовы идут со смещением +2
  от метки стаба (адрес входа после первого слова).

**Валидация маппинга**: независимые байт-совпадения из B3
(`b3_signatures.json`) легли точно на предсказанные flash-эквиваленты:
`p33_soft_reset` 0x10ea22→0x0608990e, `os_sem_create`, `__tcnt_us`,
`msys_to_p11_sync_cmd`, `u_delay`, `sfc_suspend`, `mpu_enter_deep_sleep`,
`xosc_adet_en`, `owner_is_idle_task`, `sbc_cal_energy`, `__hw_clk_limit`,
`core_sfr_enter_deepsleep` — имена получены из байт-матча кода,
RAM-адрес предсказан копи-таблицей. Пересечение — 100 %.

## 3. Именование целей: 39/175

| метод | имён | инструмент |
|---|---|---|
| прямые байт-совпадения (B3) | 12 | `b3_sigs2.py` (ram-direct) |
| имя по flash-эквиваленту (байт-матч/Ghidra-имена) | 24 | `b3_overlay.py` |
| выравнивание кода sdk.elf против flash-источника оверлея | 3 | `b3_overlay_names.py` |
| семантика по декомпиляции | 3 | `b3_finalize.py` |
| ROM-стабы по rom.lst | 21 | `b3_finalize.py` |

Топ целей:

| RAM-цель | сайтов | имя | flash-эквивалент |
|---|---|---|---|
| 0x10dbcc | 434 | **os_exit_critical** | 0x06088ab8 |
| 0x10db7e | 378 | **os_enter_critical** | 0x06088a6a |
| 0x10dd54 | 248 | — (OS-область, декомпил в дампе) | 0x06088c40 |
| 0x10dd86 | 239 | — | 0x06088c72 |
| 0x10fed0 | 207 | — (обёртка вызовов в P33/PMU ROM 0x0bfa****/0x05f9****) | 0x0608adbc |
| 0x1fd76 | 189 | __stub_memcpy+2 | ROM |
| 0x1fd82 | 162 | __stub_memset+2 | ROM |
| 0x11000c | 129 | delay_loop (чистый цикл-счётчик) | 0x0608aef8 |
| 0x10ea22 | 87 | p33_soft_reset | 0x0608990e |

`os_enter_critical`/`os_exit_critical`: пер-ядерные счётчики вложенности
(`cnum*4 + 0x1083dc/0x1083ec`), вход ставит маску IRQ
(`0xffe1a8 + cnum*0x800 := 6`), выход снимает при вложенности 0.

Область copy2 — **ядро ОС/btctrler**: функции оперируют TCB-очередями
событий (вызывают `OS_EventHighestTask`), счетчики задач, `OS_*`-массивы
(0x1082xx–0x1083xx). Декомпиляция всех 139 flash-эквивалентов:
`disasm/b3_overlay_decomp.c`.

## 4. Что не сошлось

- Цепочечное выравнивание (пары якорей с равными flash/elf-дельтами)
  дало 0 — сборки слишком разные (`b3_overlay_chain.py` сохранён).
- 0x0bfa4f5e/0x05f9ac6e/0x0bfa54a8 — вызовы за пределы образа: ROM-окна
  сопроцессора (P33/PMU), образа нет — цели не резолвятся без дампа ROM.
- 136 RAM-целей остаются без имён, но теперь у всех известны
  flash-эквиваленты, размеры, декомпил и call-граф — фундамент для
  последующей идентификации (экспертным анализом или свежим SDK).

## 5. Файлы

- `disasm/b3_far_targets.json` — 175 целей: {kind, name?, via?,
  flash_equiv?, region?, sites, callers[]}
- `disasm/b3_overlay_names.json` — выравнивание sdk.elf↔flash
- `disasm/b3_overlay_decomp.c` — декомпил 139 функций оверлея
- `tools/b3_overlay.py`, `b3_overlay_names.py`, `b3_overlay_chain.py`,
  `b3_finalize.py`
- Ghidra: 115 функций создано в области оверлея (bookmark
  `hidden-func-B3overlay`); данные C4 восстановлены после дизассемблирования.
