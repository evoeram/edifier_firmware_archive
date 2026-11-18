# MR5 — прошивка 1.0.3

## Кратко

| Поле | Значение |
|---|---|
| Модель | MR5 |
| product_id в каталоге | 521 |
| Версия, запрошенная как current_version | `0.0.0` |
| Версия, которую вернул сервер | **1.0.3** |
| Размер | 697612 байт |
| SHA-256 | `e9b9b8661014157412884d0bc69c280b62d56b1a24c74b26eb079e058107415e` |
| Файл | `firmware.bin` |

## Откуда взята

Запрос эмулирует официальное приложение Edifier ConneX 1.0.32:

```
GET https://foreign-app.edifier.com/home/api/v1/ota-upgrade?product_id=521&os=1&mac=C8%3A24%3A78%3A12%3A34%3A56&current_version=0.0.0&app_version=1.0.32&app=13&timestamp=1794953486&sign=941A34B9DBED2C36806E64B6D280ACD3
```

Подпись: `MD5(отсортированные k=v + "7rn$r44-jM").upper()`.
Полный ответ сервера — `api_response.json`, исходный URL запроса — `api_request.txt`.

Прямая ссылка на файл:

```
https://edifier-us-app.s3.us-east-2.amazonaws.com/product_firmware/20260202/9fa3e87f97e2786c320061bf0b26b0a0.bin
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
- поискать ASCII-строки версии (`1.0.3`) внутри файла;
- посмотреть `data.upgrade_prompt` в `api_response.json` — там текст диалога и иногда ссылка.

## Описание от сервера (upgrade_prompt, первые 600 символов)

```
<ota-des> <zh-CN> （1）修正了在長時間開機後音量旋鈕可能停止運作的問題。 </zh-CN> <zh-TW> （1）修正了在長時間開機後音量旋鈕可能停止運作的問題。 </zh-TW> <en-US> (1) Fixed an issue where the volume knob would stop working after extended power-on time. </en-US> <ja-JP> （1）長時間電源を入れたままにすると音量ノブが動作しなくなる問題を修正しました。 </ja-JP> <ko-KR> （1）장시간 전원이 켜진 상태에서 음량 노브가 작동하지 않던 문제를 수정했습니다. </ko-KR> <fr-FR> (1) Correction d’un problème où le bouton de volume cessait de fonctionner après une longue période de mise sous tension. </fr-FR> <es-ES> (1) Se corrigió un problema por el cual el control de volumen dejaba de funcionar después de un tiempo prolongado de encendid
```

## Предупреждение

Не прошивайте файл от другой модели: даже если название совпадает, id каталога различаются
(например, MR5 встречается с id 521 и 10016, и только первый отдаёт файл).
