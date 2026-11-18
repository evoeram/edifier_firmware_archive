# Как приложение получает эти файлы (из APK 1.0.32)

ENDPOINT:
  GET https://foreign-app.edifier.com/home/api/v1/ota-upgrade
  (точный путь: /home/api/v1/ota-upgrade)

ЗАПРОС (AppRepository.getOtaUpdate):
  product_id  = id из зашифрованного assets/products_release.json
  os          = 1          (Android)
  mac         = MAC устройства в формате XX:XX:XX:XX:XX:XX
  current_version = версия, которая «уже стоит». 0.0.0 => сервер отдаёт последнюю.
  app_version = 1.0.32
  app         = 13
  lang_code   = опционально
  timestamp   = "%010d" % (unix_time / 1000)
  sign        = MD5( конкатенация отсортированных по ключу "k=v" + секрет ).upper()

СЕКРЕТ ПОДПИСИ (SignTool.sign в APK, открытым текстом):
  7rn$r44-jM

ОТВЕТ:
  code = 200
  data.FirmwareVersionNo -> версия на сервере
  data.FirmwareLinkUrl   -> прямая ссылка на S3 .bin
  data.upgrade_prompt    -> HTML-текст диалога обновления
  data.type / rule_type / upgrade_start_time / upgrade_end_time

ВАЖНО:
  - Если current_version >= версии сервера, приходит code=200 но data:{} (обновлений нет).
  - API возвращает ТОЛЬКО последний файл. Истории версий в приложении нет.
  - Слишком частые запросы => code=429 "请求过于频繁，请稍后再试".
  - Authorization может быть пустым.
  - CORS на API разрешён (*), поэтому HTML-утилита работает из файла.

ПРОТОКОЛ КОЛОНКИ (для контекста, из lib_connect):
  Аудио — classic Bluetooth A2DP; управление — BLE GATT или SPP.
  Склейка по MAC: первые 6 байт manufacturer-data BLE-рекламы = A2DP MAC.
  Manufacturer ID Edifier = 2016 (0x07E0 = LE от 0xE007).
  Кадр V2: AA | appCode(0xEC) | opcode | len(uint16 BE) | payload | CRC8(sum)
  Кадр V1: header | len(uint8) | opcode | payload | CRC16(sum+8217)
  «Шифрование» = XOR payload с 0xA5.
