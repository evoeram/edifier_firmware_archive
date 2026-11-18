# ghidra_export/ — архив анализа Ghidra (MR5 1.0.3)

Экспорт состояния Ghidra-анализа из Temp-проекта в постоянное хранилище
(2026-11-18, после реанализа с p-code B1).

## Содержимое

| файл | что это |
|---|---|
| `ghidra_proj_backup/` | полная копия Ghidra-проекта (`MR5.gpr` + `MR5.rep`, 36,8 МБ): программа `app_bin_full.bin` со всей разметкой (RAM-блок A2, 3 222 функции, имена B4, 1 657 строк A4, p-code-анализ) |
| `functions.csv` | все функции: `entry,size,name` |
| `named_functions.md` | именованные функции (не `FUN_*`/`sub_*`/`thunk_*`) с доказательствами (plate-комментарии B2/B4) — входная точка для ручного именования B4.2 |
| `string_xrefs_ghidra.csv` | ссылки на определённые в Ghidra строки (в Ghidra их зарегистрировано мало — авторитетный источник по строкам: `disasm/string_xrefs.md` от B2) |
| `mr5_decomp_all.c` | декомпиляция ВСЕХ функций (~6,8 МБ; заголовок `// ===== имя @ адрес (size N)`). Внимание: 144 функции из RAM-блока (`@ 0010xxxx`) — мусор автоанализа, игнорировать; рабочие — `@ 06xxxxxx` |

## Восстановление проекта

```powershell
# скопировать бэкап обратно в Temp и открыть
Copy-Item source\ghidra_export\ghidra_proj_backup\* C:\Users\User\AppData\Local\Temp\opencode\ghidra_proj\ -Recurse -Force
# затем: analyzeHeadless ... Temp\opencode\ghidra_proj MR5 -process app_bin_full.bin ...
```

Язык `pi32v2:LE:32:default` ставится отдельно из
`source/gen/pi32v2_full.slaspec` → `Ghidra/Processors/JieLi/data/languages/`
(см. §5 `REVERSE_ENGINEERING_PLAN_NEW.MD`).

## Повторный экспорт

Скрипты в `ghidra_scripts/` (Temp): `ExportInventory.java` (инвентарь),
`ExportDecomp.java` (декомпил, несколько минут). После содержательных
сессий анализа экспорт повторить — Temp не для хранения.
