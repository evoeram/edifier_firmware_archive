# Edifier Cloud API — разбор и верификация

Дата: 2026-11-19. Источник: jadx-декомпил приложения Edifier ConneX
(`C:\Users\User\AppData\Local\Temp\opencode\jadx_out`).

## 1. Подпись запросов (SignTool.kt) — ВЗЛОМАНА И ВЕРИФИЦИРОВАНА

`com/edifier/lib_common/utils/SignTool.java`:

1. Взять все query-параметры БЕЗ `timestamp` и `sign`.
2. Отсортировать ключи по алфавиту.
3. Конкатенировать `key=value` без разделителей.
4. Дописать в конец ключ `7rn$r44-jM` (KEY_TYPE_DEF; второй ключ
   `emm!68pyo1` — для статистики).
5. MD5 от UTF-8 строки, hex в ВЕРХНЕМ регистре.
6. Добавить в запрос `timestamp` (unixtime, сек) и `sign`.

`mac` в подписи — с двоеточиями (URL-кодирование — уже в самом запросе).
Проверено на эталонном запросе из архива (api_request.txt): подпись совпала
символ в символ → `941A34B9DBED2C36806E64B6D280ACD3`.

## 2. Эндпоинты (Api.kt, база https://foreign-app.edifier.com/)

- `GET /home/api/v1/ota-upgrade` — params: product_id, os=1, mac,
  current_version, app_version, app=13. Ответ: FirmwareVersionNo,
  FirmwareLinkUrl (S3), upgrade_prompt и т.д.
- `GET /edifier_connex/api/v1/encrypt-products` — params: os, app,
  app_version. Ответ: base64(AES-CBC(список продуктов)).
- Прочее: ota-item-upgrade, product-light-effects, product-model-materials,
  product-guide, voice-packs и т.д.

Рейт-лимит ota-upgrade: ~5 запросов подряд → 429 «请求过于频繁».
encrypt-products лимита не показал.

## 3. Расшифровка encrypt-products (CipherUtil.kt)

- AES-256-CBC, PKCS7.
- Key (32 Б): `HiO9d5jV0Ln7VNE5M+lM=E&E^Mobt_TA`
- IV (16 Б): `3-eM$+G6-UZBisv$`

Расшифрованный список: 103 продукта →
`C:\Users\User\AppData\Local\Temp\opencode\products_foreign-app.json`.

## 4. Продукты MR5

| id | Name | Model | ServiceUUID | LastFW |
|----|------|-------|-------------|--------|
| 521 | MR5 | MR5 | 48093a01-1a48-11e9-ab14-d663bd873d93 | 1.0.4* |
| 10016 | MR5 | MR5（换功放8625） | 48097e03-… | — (не опубликован) |

- Сервис 48093a01 = сервис живого устройства пользователя → CN «MR5BT»
  мапится на продукт 521.
- `ota-upgrade` для 521: latest = **1.0.3** (при current_version 0.0.0/1.0.0),
  при 1.0.3 → пусто. Файл = тот же .ufw, что уже в архиве.
  (LastFirmwareVersion=1.0.4 в карточке — вероятно, внутреннее поле/задел.)
- Для 10016 OTA нет (data={}).

## 5. Итог для дампа

Сервер отдаёт только app-образ (0xAA50C). Полного дампа 2 МБ (загрузчик,
калибровки, VM) в облаке нет — он никогда не покидает устройство.
S3-листинг бакета закрыт (AccessDenied).
