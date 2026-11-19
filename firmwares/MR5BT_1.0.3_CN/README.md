# MR5BT (CN) 1.0.3 — происхождение

Дата: 2026-11-19. Устройство пользователя: **CN EDIFIER MR5BT**, FW 1.0.0.

## Получение

1. Приложение **Edifier Connect** (CN, package `com.edifier.edifierconnect`)
   — базовый URL `https://admin-app.edifier.com/` (ConstantUtil.java).
2. Ключи подписи и AES — **те же**, что в международном ConneX:
   - sign: MD5(sorted `key=value` + `7rn$r44-jM`), timestamp в сек;
   - encrypt-products: AES-256-CBC, key `HiO9d5jV0Ln7VNE5M+lM=E&E^Mobt_TA`,
     IV `3-eM$+G6-UZBisv$`.
3. `GET /home/api/v1/encrypt-products` → **349 продуктов** (vs 103 у ConneX).
   Продукт: **MR5BT, id 497**, SearchUuid `00000a03-…`,
   Service `48090a03-1a48-11e9-ab14-d663bd873d93`,
   Read `48090001-…`, Write `48090002-…` (совпадают с живым устройством).
   LastFirmwareVersion в карточке: 1.0.4 (файла на сервере пока нет —
   ota-upgrade отдаёт 1.0.3 при current_version 0.0.0 и 1.0.0).
4. `GET /home/api/v1/ota-upgrade?product_id=497...` →
   `https://edifier-provider-oss.edifier.com/product_firmware/20260204/438539b2bd0039521d2d885ad62e1d6f.bin`
   (прямой домен edifier-provider-oss.edifier.com из сети пользователя не
   доступен; скачано через `edifier-provider.oss-cn-shenzhen.aliyuncs.com`).

## Файлы

- `firmware.bin` — зашифрованный OTA-образ (696 140 Б, MD5
  `4C2010E170E4B8545C76D40FA6F5EE21`).
- `source/decrypted/MR5BT_1.0.3_CN_dec.bin` — расшифрован тем же
  LFSR-алгоритмом (K=0x2BC1, блоки по 32, seed=K^((off-2)>>2)), что и
  Global MR5 1.0.3. Заголовок валиден: `app_area_head`.
- `source/products_cn.json` — полный CN-каталог продуктов (349 шт).

## Отличия от Global MR5 1.0.3 (697 612 Б)

- Размер: 696 140 Б (−1472 Б).
- ~91% байт различаются (перекомпиляция, сдвиги адресов).
- В CN-образе есть строка **`EDIFIER MR5BT`** (имя BT по умолчанию).
- Это ОТДЕЛЬНАЯ сборка для CN-железа (service 48090a03 vs 48093a01 у
  Global MR5).

## Важно

CN-каталог содержит 349 продуктов — потенциальный источник прошивок
других моделей (MR3BT id 432 LastFW 1.0.7, MR4BT id 580 и др.).
Листинг OSS-бакета закрыт; доступны только файлы, на которые есть
прямая ссылка из ota-upgrade.
