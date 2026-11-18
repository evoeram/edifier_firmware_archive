# MR4.5 — прошивка 1.0.1

## Кратко

| Поле | Значение |
|---|---|
| Модель | MR4.5 |
| product_id в каталоге | 10011 |
| Версия, запрошенная как current_version | `0.0.0` |
| Версия, которую вернул сервер | **1.0.1** |
| Размер | 664229 байт |
| SHA-256 | `df08eb21229ef9e9b93a10f698c0eca5230701bd8ef6605f610e8ad4602e2715` |
| Файл | `firmware.bin` |

## Откуда взята

Запрос эмулирует официальное приложение Edifier ConneX 1.0.32:

```
GET https://foreign-app.edifier.com/home/api/v1/ota-upgrade?product_id=10011&os=1&mac=C8%3A24%3A78%3A12%3A34%3A56&current_version=0.0.0&app_version=1.0.32&app=13&timestamp=1794953505&sign=13ADD99DD58EDA8FFE86D8C0F0D665BD
```

Подпись: `MD5(отсортированные k=v + "7rn$r44-jM").upper()`.
Полный ответ сервера — `api_response.json`, исходный URL запроса — `api_request.txt`.

Прямая ссылка на файл:

```
https://edifier-us-app.s3.us-east-2.amazonaws.com/product_firmware/20261113/MR4.5_V1.0.1_db_update_data_1794533869.bin
```

## Что внутри файла

`firmware.bin` начинается с байт, не похожих на известный заголовок: высокая энтропия =>
сжато и/или зашифровано форматом конкретного чипа (BES / Jieli / Qualcomm и т.п.).
Именованных секций, точных адресов и таблицы версий внутри «как есть» нет.
Это **не** plain-прошивка для прямой записи во Flash.

## Как прошивать

Безопасный путь — официальное приложение Edifier ConneX:

1. Подключить устройство как A2DP и разрешить BLE/локацию.
2. В карточке устройства открыть «Обновление прошивки» — приложение само запросит
   тот же endpoint и скачает файл.
3. Прошивка идёт по BLE GATT / SPP (для USB — HID): команды OTA `0x10`, `0x11`,
   `commonOtaUpdate` / `mixOtaUpdate` в `CommandManager`.

Прямая прошивка «вручную» требует знания bootloader-протокола конкретного чипа
и не описана в приложении: в APK есть только команды передачи блоков, а не
процедура входа в bootloader. Поэтому файл из этого архива стоит считать
**образом для анализа/резерва**, а не готовым (для программатора).

## Как ковырять

```
python3 ../inspect_firmware.py firmware.bin
python3 ../inspect_firmware.py firmware.bin --strings 200 --minlen 5
```

Скрипт печатает размер, SHA-256, энтропию, первые 64 байт и читаемые строки.
Если установлены внешние утилиты, можно дополнительно:

```
binwalk firmware.bin
binwalk -e firmware.bin
strings -n 6 firmware.bin | head -100
xxd -l 256 firmware.bin
```

Полезные проверки:
- сравнить `sha256` двух разных версий — меняется ли целиком образ;
- поискать ASCII-строки версии (`1.0.1`) внутри файла;
- посмотреть `data.upgrade_prompt` в `api_response.json` — там текст диалога и иногда ссылка.

## Описание от сервера (upgrade_prompt, первые 600 символов)

```
<ota-des> <zh-CN> </zh-CN> <zh-TW> 修復了在極低音量下中低音單體出現輕微背景噪音的問題。 </zh-TW> <en-US> Fixed a subtle background noise issue with the mid-bass driver at super low volumes. </en-US> <ja-JP> 極小音量時にミッドバスドライバーから発生していた微小な background ノイズ（背景雑音）の問題を修正しました。 </ja-JP> <ko-KR> 매우 낮은 볼륨에서 미드베이스 드라이버의 미세한 배경 소음 문제를 수정했습니다. </ko-KR> <fr-FR> Correction d'un léger bruit de fond au niveau du haut-parleur médium-grave à très bas volume. </fr-FR> <es-ES> Se corrigió un ligero ruido de fondo en el altavoz de medios-graves a volúmenes muy bajos. </es-ES> <pt-PT> Corrigido um discreto ruído de fundo no alto-falante de médio
```

## Предупреждение

Не прошивайте файл от другой модели: даже если название совпадает, id каталога различаются
(например, MR5 встречается с id 521 и 10016, и только первый отдаёт файл).
