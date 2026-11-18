# MR3 — прошивка 1.0.7

## Кратко

| Поле | Значение |
|---|---|
| Модель | MR3 |
| product_id в каталоге | 430 |
| Версия, запрошенная как current_version | `0.0.0` |
| Версия, которую вернул сервер | **1.0.7** |
| Размер | 655013 байт |
| SHA-256 | `7365fb68c6e62e4cde2a06e42b05d673d090ab0ecbb323d94a95a95c2441209b` |
| Файл | `firmware.bin` |

## Откуда взята

Запрос эмулирует официальное приложение Edifier ConneX 1.0.32:

```
GET https://foreign-app.edifier.com/home/api/v1/ota-upgrade?product_id=430&os=1&mac=C8%3A24%3A78%3A12%3A34%3A56&current_version=0.0.0&app_version=1.0.32&app=13&timestamp=1794953483&sign=0732B806DD314F140B6BA615A82BCEB5
```

Подпись: `MD5(отсортированные k=v + "7rn$r44-jM").upper()`.
Полный ответ сервера — `api_response.json`, исходный URL запроса — `api_request.txt`.

Прямая ссылка на файл:

```
https://edifier-us-app.s3.us-east-2.amazonaws.com/product_firmware/20260112/07c7f2dca2eb1e001aca688a5af41e6a.bin
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
- поискать ASCII-строки версии (`1.0.7`) внутри файла;
- посмотреть `data.upgrade_prompt` в `api_response.json` — там текст диалога и иногда ссылка.

## Описание от сервера (upgrade_prompt, первые 600 символов)

```
<ota-des> <zh-CN> (1) 新增 62Hz、125Hz 和 16kHz 的可調頻段，可在應用程式中的“音效”>“自定義”中設定。 (2) 修正了在長時間開機後音量旋鈕可能停止運作的問題。 </zh-CN> <en-US> (1) Added adjustable frequency bands at 62Hz, 125Hz, and 16kHz, which can be set in the app under "Sound Effects" > "Customized." (2) Fixed an issue where the volume knob would stop working after extended power-on time. </en-US> <ja-JP> (1) 62Hz、125Hz、16kHzの調整可能な周波数帯域が追加され、アプリの「イコライザー」>「カスタマイズ」から設定できます。 (2) 長時間電源を入れたままにすると音量ノブが動作しなくなる問題を修正しました。 </ja-JP> <ko-KR> (1) 62Hz, 125Hz 및 16kHz의 조정 가능한 주파수 대역이 추가되었으며, 앱의 "사운드 효과" > "커스터마이즈"에서 설정할 수 있습니다. (2) 장시간 전원이 켜진 상태에서 음량 노브가 작동하지 
```

## Предупреждение

Не прошивайте файл от другой модели: даже если название совпадает, id каталога различаются
(например, MR5 встречается с id 521 и 10016, и только первый отдаёт файл).
