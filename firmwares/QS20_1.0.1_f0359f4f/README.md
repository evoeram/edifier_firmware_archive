# QS20 — прошивка 1.0.1

## Кратко

| Поле | Значение |
|---|---|
| Модель | QS20 |
| product_id в каталоге | 520 |
| Версия, запрошенная как current_version | `0.0.0` |
| Версия, которую вернул сервер | **1.0.1** |
| Размер | 927529 байт |
| SHA-256 | `9bb075cbfc0b59a2d6283a085283a128983539a66a13a702b4a2a465c0d3e7f0` |
| Файл | `firmware.bin` |

## Откуда взята

Запрос эмулирует официальное приложение Edifier ConneX 1.0.32:

```
GET https://foreign-app.edifier.com/home/api/v1/ota-upgrade?product_id=520&os=1&mac=C8%3A24%3A78%3A12%3A34%3A56&current_version=0.0.0&app_version=1.0.32&app=13&timestamp=1794953488&sign=2CD3273A9953AE47D131C8B4E5D6F2DA
```

Подпись: `MD5(отсортированные k=v + "7rn$r44-jM").upper()`.
Полный ответ сервера — `api_response.json`, исходный URL запроса — `api_request.txt`.

Прямая ссылка на файл:

```
https://edifier-us-app.s3.us-east-2.amazonaws.com/product_firmware/20251215/10d405bcd9760eb45fb061912649ce4c.bin
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
<android>  <zh-CN>  </zh-CN> <en-US>  </en-US> </android>  <ios> <zh-CN>  </zh-CN> <en-US>  </en-US> </ios> <ota-des> <zh-CN> 1）優化了當連接到外部電源適配器或電腦的USB-A端口時的充電時間。 </zh-CN> <en-US> 1) Optimized the charging time when connected to the USB-A port of an external power adapter or computer. </en-US> <ja-JP> 1）外部電源アダプターまたはコンピュータのUSB-Aポートに接続時に充電時間を最適化しました。 </ja-JP> <ko-KR> 1) 외부 전원 어댑터나 컴퓨터의 USB-A 포트에 연결했을 때 충전 시간을 최적화했습니다. </ko-KR> <fr-FR> 1) Optimisé le temps de charge lorsqu'il est connecté au port USB-A d'un adaptateur secteur externe ou d'un ordinateur. </fr-FR> <es-ES> 1) Optimizado el tiempo de c
```

## Предупреждение

Не прошивайте файл от другой модели: даже если название совпадает, id каталога различаются
(например, MR5 встречается с id 521 и 10016, и только первый отдаёт файл).
