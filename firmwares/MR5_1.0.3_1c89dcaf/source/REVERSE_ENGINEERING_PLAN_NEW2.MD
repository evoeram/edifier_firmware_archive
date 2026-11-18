# REVERSE ENGINEERING PLAN — NEW 2 (фаза F: RAM-оверлей)

Продолжение `REVERSE_ENGINEERING_PLAN_NEW.MD`. Предмет: **RAM-оверлей
(copy2: RAM 0x1094e0 ← flash 0x060843cc, 44 080 Б — ядро ОС/btctrler)**,
см. `findings/B3_1_ram_overlay.md`.

Исходное состояние: 175 дальне-вызовных целей классифицированы, 39 имён,
136 RAM-целей без имён (flash-эквиваленты, декомпил `disasm/b3_overlay_decomp.c`
и call-граф известны).

---

## Фаза F — экспертная идентификация функций оверлея

- [x] **F1. Досье функций**: ✅ 2026-11-18 — `tools/b5_dossier.py` →
  `disasm/b5_dossiers.md`/`.json` (декомпил, вызываемые, глобалы, строки
  вызывающих); + 94 хелпера декомпилированы (`disasm/b5_helpers_decomp.c`).
- [x] **F2. Кластеризация**: ✅ — 5 кластеров: uCOS-II ядро,
  частотно-критическая секция (PLL+SFC), таймеры/время (PMU-ROM),
  IRQ-обработчики, аудио-фреймворк (vtable-объекты).
- [x] **F3. Семантическое именование**: ✅ — 24 имени
  (`disasm/b5_names.json`): 11 high (os_mutex_create/pend/post,
  os_sem_pend/post, os_task_ready/unready, os_event_task_unlink,
  os_critical_nest_get, os_spin_lock/unlock — свидетельства структурные:
  OSEventType, ready-list 0x108228 + bitmap 0x108210, testset 0x108404),
  8 med (os_taskq_post, os_time_dly, os_sched, sysclk_cs_enter/exit,
  os_int_state_get, os_sem_del), 5 low (delay_ms, sys_time_ms, PMU-обёртки).
- [x] **F4. Применение**: ✅ — 23/24 имён применено в Ghidra
  (`B5Apply.java`, plate-комментарии с evidence), 1 уже была названа;
  `b3_far_targets.json`: 53/175 целей именованы; отчёт
  `findings/B3_2_overlay_expert.md`; ANALYSIS.md §B3.2.

## Правила

- Не выдумывать имена без свидетельства: каждая имя → evidence-строка.
- Приоритет: функции с наибольшим числом call-сайтов и вызываемые из
  именованных функций.
- Незнакомое остаётся `ovl_<flash_off>` с пометкой «unknown».
- После любых дизассемблирующих скриптов — `C4MarkData.java` + StatsDump.
