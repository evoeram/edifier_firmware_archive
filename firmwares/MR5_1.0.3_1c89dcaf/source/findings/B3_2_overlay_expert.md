# B3.2 — Экспертная идентификация функций RAM-оверлея (2026-11-18)

План: `REVERSE_ENGINEERING_PLAN_NEW2.MD`, фаза F (F1–F4). База:
`findings/B3_1_ram_overlay.md` (копи-таблица crt0, 175 дальне-вызовных
целей, декомпил `disasm/b3_overlay_decomp.c`).

## F1. Досье

`tools/b5_dossier.py` → `disasm/b5_dossiers.md`/`.json`: для каждой из 136
безымянных целей — декомпил, вызываемые (именованные/оверлей), трогаемые
глобалы, строки вызывающих app-функций, размер, частота. Дополнительно
декомпилированы 94 хелпера, на которые ссылаются цели
(`decomp_helpers.c` → сохранён в `disasm/b5_helpers_decomp.c`).

## F2. Кластеры (по call-графу и глобалам)

1. **Ядро ОС = uCOS-II** (наибольший): OSEventType-дискриминатор (2=SEM,
   3=MUTEX по `ucos_ii.h` из публичного SDK), готовность-списки
   `0x108228[prio*8]` + битовая карта `0x108210`, per-core массивы
   `0x1083dc…0x108404`, spin-lock `testset 0x108404`.
2. **Частотно-критическая секция**: счётчики 0x1083f4/fc[cnum], ожидание
   PLL (0xfe0200), перконфигурация SFC (0xfd55xx), таблица частот 0x06088da0.
3. **Таймеры/время**: списки +0x24/+0x28, глобал темпа 0x1079c0, чтение
   T2 (0xffe0f0), вызовы в PMU-ROM (0x0BFAxxxx).
4. **IRQ-обработчики**: обращения к core/IRQ-регистрам.
5. **Аудио-фреймворк (jlstream-подобный)**: vtable-объекты
   (`(*puVar3)()`), поля-счётчики, callback-таблица 0x1134bc.

## F3. Имена (24 записи, `disasm/b5_names.json`)

### Высокая уверенность (структурные свидетельства)

| flash | RAM-цель | имя | свидетельство |
|---|---|---|---|
| 06087398 | 0x10c4ac | **os_mutex_post** | type==3; восстановление priо владельца (inheritance); OS_EventHighestTask |
| 0608718a | 0x10c29e | **os_mutex_pend** | type==3; timeout=-1 ∞; повышение priо задачи |
| 06086daa | 0x10bebe | **os_mutex_create** | пишет OSEventType=3, cnt=1, owner=0xff |
| 06087ace | 0x10cbe2 | **os_sem_pend** | type==2; декремент OSEventCnt |
| 06087a88 | 0x10cb9c | **os_sem_post** | type==2; инкремент/передача семафора |
| 06086dd0 | — | **os_task_unready** | исключение из ready-list + bitmap |
| 06086eda | — | **os_task_ready** | вставка в ready-list + bitmap |
| 0608732c | — | **os_event_task_unlink** | unlink из wait-list (+0x18/+0x1c) |
| 0608978a | — | **os_critical_nest_get** | чтение 0x1083dc[cnum] |
| 06087610 | — | **os_spin_lock** | `testset 0x108404` |
| 0608761e | — | **os_spin_unlock** | сброс 0x108404 |

### Средняя уверенность

| flash | RAM-цель | имя | свидетельство |
|---|---|---|---|
| 060874c8 | — | os_taskq_post_core | OSGetTaskTcb; вставка в очередь; sched |
| 060875c2 | 0x10c6d6 | os_taskq_post | обёртка + флага 0x1083e4[cnum] |
| 060876d0 | 0x10c7e4 | os_time_dly | запрет в irq/critical; tail в tick-wait |
| 06087740 / 060878c8 | 0x10c9dc | os_sem_del(_core) | type==2, flush wait-list |
| 0608eaba | — | os_sched | enter_critical; switch-out без возврата |
| 06088c40 | 0x10dd54 | sysclk_cs_enter | PLL+SFC+таблица частот |
| 06088c72 | 0x10dd86 | sysclk_cs_exit | зеркало enter |
| 06086dc8 / 0608eab2 | — | os_int_state_get_a/b | чтение icfg.b0 |

### Низкая уверенность (гипотезы, помечены в JSON)

- 0608aee6 (RAM 0x10fffa) = `delay_ms` (цикл по параметру, темп из 0x1079c0)
- 060885ca/06088538 = `sys_time_ms` (T2 0xffe0f0, /1000)
- Трио 0608adbc/0608adc6/0608adae (RAM 0x10fed0/0x10feda/0x10fec2,
  384 сайта суммарно) = обёртки вызовов в PMU-ROM-окно 0x0BFAxxxx —
  образ ROM недоступен, семантика не установлена.

## F4. Применение

- `b3_far_targets.json`: **53/175 целей именованы** (было 39).
- Ghidra: 24 имени применено к flash-функциям через `B3Apply.java`
  (plate-комментарии с evidence и уровнем уверенности).
- Итог программы: functions ≈ 3 476+33 (хелперы), definedData 2 427.

## Не решено

- 122 RAM-цели без имён; кластеры 4–5 (IRQ, аудио-фреймворк) — требуют
  отдельного прохода.
- PMU-ROM (0x0BF8xxxx–0x0BFAxxxx): нужен дамп ROM чипа MR5.
- Массовые вызовы `sysclk_cs_*` (487 сайтов) из boot-кода наводят на
  мысль, что это может быть другая пара (например, кэш/SFC suspend) —
  проверить при наличии эталонного ROM.
