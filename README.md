# Edifier Firmware Archive

Архив прошивок Edifier и материалов реверс-инжиниринга (JieLi jl701n / pi32v2).

## Структура

```
firmwares/
  GLOBAL/              # массовая выкачка через ConneX API (foreign-app.edifier.com)
    <pid>_<Model>/firmware_<ver>.bin   # зашифрованный OTA-образ
    <pid>_<Model>/ota_response.json    # метаданные OTA
    _manifest.json                     # статусы всех 103 продуктов
    _provenance_old/                   # request_url+подписи из первой выкачки
  CN/                  # массовая выкачка через Edifier Connect API (admin-app.edifier.com)
    <pid>_<Model>/firmware_<ver>.bin
    <pid>_<Model>/ota_response.json
    _manifest.json                     # статусы всех 349 продуктов
  MR5_1.0.3_1c89dcaf/  # дерево анализа GLOBAL MR5 (не дублировать!)
    firmware.bin, source/ (ANALYSIS.md, ghidra_export, decrypted, tools),
    DSP_ARCH/ (EQ_TABLES, DSP_ALGORITHMS, FLASH_LAYOUT, POWER_AMP)
  MR5BT_1.0.3_CN/      # дерево анализа CN MR5BT (устройство пользователя)
    firmware.bin, source/ (decrypted, products_cn.json), README.md
```

## Содержимое

- **50 уникальных прошивок**: 13 GLOBAL + 37 CN. Полный список с MD5/SHA-256 —
  `MANIFEST_ALL.csv` (52 строки: 50 файлов + 2 записи analysis-tree дублей).
- Шифрование OTA-образов: LFSR (K=0x2BC1, блоки 32 Б, seed=K^((off-2)>>2)) —
  расшифровка в `firmwares/MR5_1.0.3_1c89dcaf/source/tools/decrypt_mr5.py`.
- Продукт пользователя: **CN MR5BT = product_id 497**, прошивка 1.0.3
  (`CN/497_MR5BT`, расшифрованный образ в `MR5BT_1.0.3_CN/source/decrypted/`).

## Инструменты

- `download_all_firmware.py` — массовая выкачка (подпись MD5 `7rn$r44-jM`,
  обработка 429-in-body, ретраи, алиясунг-фолбэк, percent-encoding URL).
  Перезапуск докачивает только новые версии.
- `download_firmware.py`, `inspect_firmware.py` — одиночная выкачка/инспектор.

## Ключевые документы

- `firmwares/MR5_1.0.3_1c89dcaf/source/ANALYSIS.md` — журнал реверса (§1–17).
- `firmwares/MR5_1.0.3_1c89dcaf/source/edifier_api.md` — API Edifier (подпись,
  AES-ключи, эндпоинты, продукты).
- `DSP.html`, `BLE_probe.html` — рабочие стенды (DSP-управление, BLE-пробы).
- `API_NOTES.md`, `MANIFEST.csv` — история первой (точечной) выкачки.

## Правила

- e25HD не трогать. Фаза E (модификация/перепрошивка) — только по явной просьбе.
- Опасные OTA-операции (0xE3/0xE5/0xE7) в BLE-стенде запрещены.
- После каждого коммита обновлять `edifier_re.bundle`.
