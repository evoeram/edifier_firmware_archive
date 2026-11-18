# D1 — семейный дифф 12 прошивок Edifier (JieLi pi32v2)

Инструмент: `tools/family_diff.py` (v2). Методы: (а) позиционные совпадения 32-байтных блоков; (б) позиционно-независимые общие 64-байтовые чанки (та же функция на другом адресе). Эталон: MR5 1.0.3.

## 1. Карточки моделей

| модель | образ, Б | app.bin, Б | entry | data_crc покрывает, Б | строк |
|---|---|---|---|---|---|
| ES20_1.0.4_00812d5a | 865555 | 792120 | 0x6000100 | 646383 | 5854 |
| ES60_1.0.3_17302784 | 927747 | 861764 | 0x6000100 | 814969 | 6331 |
| MP330_1.0.2_b77539e8 | 993458 | 855272 | 0x6000100 | 781925 | 6485 |
| MR3_1.0.7_acb5d6b3 | 655013 | 553732 | 0x6000100 | 528647 | 2538 |
| MR4.5_1.0.1_fb09ee14 | 664229 | 572028 | 0x6000100 | 385696 | 2717 |
| MR4_MKII_1.0.1_d5acc167 | 664229 | 572028 | 0x6000100 | 466699 | 2717 |
| MR5_1.0.3_1c89dcaf | 697612 | 585468 | 0x6000100 | 562267 | 2758 |
| QD25_1.0.1_37f4020f | 943284 | 841036 | 0x6000100 | 773295 | 6079 |
| QR30_1.0.2_63197d81 | 721496 | 626068 | 0x6000100 | 616505 | 2697 |
| QS20_1.0.1_f0359f4f | 927529 | 785060 | 0x6000100 | 750689 | 5347 |
| R990BT_1.0.1_f3977118 | 666143 | 562384 | 0x6000100 | 492854 | 2622 |
| S355DB_2.1.1_f49205a2 | 809689 | 695396 | 0x6000100 | 632392 | 4858 |

У всех 12 моделей entry = 0x06000100 (единая флеш-раскладка).

> Примечание к колонке «data_crc покрывает»: показан **самый длинный** префикс, чей jl_crc16 совпадает с полем записи (16-битный CRC даёт случайные коллизии префиксов; для MR5 известная настоящая длина покрытия — 521 780 Б). Трактовать как верхнюю оценку.

## 2. Матрица попарного сходства (общие 64-Б чанки)

Ячейка: количество общих чанков (доля от меньшего набора).

| | ES20 | ES60 | MP330 | MR3 | MR4.5 | MR4 | MR5 | QD25 | QR30 | QS20 | R990BT | S355DB |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| **ES20** | — | 31992 (55%) | 25165 (44%) | 22429 (49%) | 22085 (38%) | 22085 (38%) | 20600 (39%) | 23543 (40%) | 22371 (43%) | 33171 (69%) | 11483 (25%) | 3241 (47%) |
| **ES60** | 31992 (55%) | — | 32735 (57%) | 13481 (29%) | 13720 (23%) | 13720 (23%) | 15079 (29%) | 32173 (55%) | 25616 (49%) | 32297 (67%) | 18047 (40%) | 2959 (42%) |
| **MP330** | 25165 (44%) | 32735 (57%) | — | 12827 (28%) | 11929 (21%) | 11929 (21%) | 14377 (27%) | 37590 (66%) | 14721 (28%) | 20642 (43%) | 25856 (57%) | 2948 (42%) |
| **MR3** | 22429 (49%) | 13481 (29%) | 12827 (28%) | — | 30634 (67%) | 30634 (67%) | 33295 (73%) | 12930 (28%) | 23171 (50%) | 17654 (38%) | 15116 (33%) | 3257 (47%) |
| **MR4.5** | 22085 (38%) | 13720 (23%) | 11929 (21%) | 30634 (67%) | — | 141901 (100%) | 32362 (61%) | 11676 (20%) | 21306 (41%) | 16876 (35%) | 19087 (42%) | 3993 (57%) |
| **MR4** | 22085 (38%) | 13720 (23%) | 11929 (21%) | 30634 (67%) | 141901 (100%) | — | 32362 (61%) | 11676 (20%) | 21306 (41%) | 16876 (35%) | 19087 (42%) | 3993 (57%) |
| **MR5** | 20600 (39%) | 15079 (29%) | 14377 (27%) | 33295 (73%) | 32362 (61%) | 32362 (61%) | — | 15449 (29%) | 29351 (56%) | 18420 (38%) | 21731 (48%) | 3702 (53%) |
| **QD25** | 23543 (40%) | 32173 (55%) | 37590 (66%) | 12930 (28%) | 11676 (20%) | 11676 (20%) | 15449 (29%) | — | 20663 (39%) | 21692 (45%) | 25908 (57%) | 2948 (42%) |
| **QR30** | 22371 (43%) | 25616 (49%) | 14721 (28%) | 23171 (50%) | 21306 (41%) | 21306 (41%) | 29351 (56%) | 20663 (39%) | — | 26801 (55%) | 26653 (59%) | 2645 (38%) |
| **QS20** | 33171 (69%) | 32297 (67%) | 20642 (43%) | 17654 (38%) | 16876 (35%) | 16876 (35%) | 18420 (38%) | 21692 (45%) | 26801 (55%) | — | 12702 (28%) | 2587 (37%) |
| **R990BT** | 11483 (25%) | 18047 (40%) | 25856 (57%) | 15116 (33%) | 19087 (42%) | 19087 (42%) | 21731 (48%) | 25908 (57%) | 26653 (59%) | 12702 (28%) | — | 2671 (38%) |
| **S355DB** | 3241 (47%) | 2959 (42%) | 2948 (42%) | 3257 (47%) | 3993 (57%) | 3993 (57%) | 3702 (53%) | 2948 (42%) | 2645 (38%) | 2587 (37%) | 2671 (38%) | — |

Позиционные совпадения (32-Б блоки с одного адреса) почти нулевые между разными чип-семействами — SDK-код линкуется по разным адресам; смысл имеет только чанковая метрика.

## 3. Что общего у MR5 с остальными (чанки → функции MR5)

| функция MR5 | чанков | совпадает с моделями |
|---|---|---|
| `sub_06059040` | 11850 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_0607f6ac` | 5718 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_0601ea24` | 5152 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_0606c464` | 2542 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_0605312e` | 982 | MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf |
| `sub_060573ae` | 920 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_06056456` | 911 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_06050d46` | 884 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_06040aa8` | 607 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QS20_1.0.1_f0359f4f |
| `sub_06046c2a` | 600 | ES60_1.0.3_17302784, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0604e388` | 518 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_06054b1a` | 408 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0603c57c` | 352 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0607b1f8` | 348 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0603cf78` | 311 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_0606b6a6` | 277 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_0602829e` | 265 | ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_06043854` | 264 | ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_0607be1e` | 240 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_06028826` | 230 | ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_06079d6e` | 229 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QS20_1.0.1_f0359f4f, S355DB_2.1.1_f49205a2 |
| `sub_0607673e` | 226 | MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, R990BT_1.0.1_f3977118 |
| `sub_0607c42c` | 225 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_060503a2` | 223 | ES20_1.0.4_00812d5a, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f |
| `sub_0604d2be` | 209 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QS20_1.0.1_f0359f4f |
| `sub_06029696` | 196 | ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0603b492` | 187 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_060486bc` | 178 | ES60_1.0.3_17302784, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, R990BT_1.0.1_f3977118 |
| `sub_06033c3e` | 176 | MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf |
| `sub_060560e2` | 173 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_0600fba2` | 172 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81 |
| `sub_06008ff4` | 168 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf |
| `sub_06015684` | 164 | MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf |
| `sub_06029a28` | 163 | ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_06030930` | 163 | MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, R990BT_1.0.1_f3977118 |
| `sub_06071904` | 161 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_060776f0` | 161 | MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, R990BT_1.0.1_f3977118 |
| `sub_06014cb4` | 160 | MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, R990BT_1.0.1_f3977118 |
| `sub_06040204` | 159 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf |
| `sub_0603c146` | 155 | MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0603e4a0` | 155 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf |
| `sub_06032bec` | 143 | MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf |
| `sub_060589c4` | 139 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_0601a618` | 139 | MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_0604c65c` | 132 | ES60_1.0.3_17302784, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_06076cf2` | 130 | MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0603f348` | 127 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118 |
| `sub_0607356c` | 126 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_0601e2b2` | 121 | ES20_1.0.4_00812d5a, MR5_1.0.3_1c89dcaf |
| `sub_0604f95a` | 116 | ES20_1.0.4_00812d5a, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f |
| `sub_06070d56` | 115 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QD25_1.0.1_37f4020f, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f, R990BT_1.0.1_f3977118, S355DB_2.1.1_f49205a2 |
| `sub_06058484` | 110 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, QS20_1.0.1_f0359f4f |
| `sub_06039e4a` | 110 | ES60_1.0.3_17302784, MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81 |
| `sub_06078ffc` | 110 | MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, R990BT_1.0.1_f3977118 |
| `sub_0606b0ec` | 103 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf |
| `sub_06076fa8` | 103 | ES20_1.0.4_00812d5a, ES60_1.0.3_17302784, MP330_1.0.2_b77539e8, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81, R990BT_1.0.1_f3977118 |
| `sub_0606a9aa` | 100 | ES20_1.0.4_00812d5a, MR3_1.0.7_acb5d6b3, MR4.5_1.0.1_fb09ee14, MR4_MKII_1.0.1_d5acc167, MR5_1.0.3_1c89dcaf |
| `sub_0604d85e` | 95 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, S355DB_2.1.1_f49205a2 |
| `sub_06013202` | 94 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, R990BT_1.0.1_f3977118 |
| `sub_0603cdb2` | 93 | MR3_1.0.7_acb5d6b3, MR5_1.0.3_1c89dcaf, QR30_1.0.2_63197d81 |

## 4. Кластеры (ближайшие соседи по чанковой метрике)

- **ES20** ← QS20 (69%, 33171), ES60 (55%, 31992), MR3 (49%, 22429)
- **ES60** ← QS20 (67%, 32297), MP330 (57%, 32735), ES20 (55%, 31992)
- **MP330** ← QD25 (66%, 37590), ES60 (57%, 32735), R990BT (57%, 25856)
- **MR3** ← MR5 (73%, 33295), MR4 (67%, 30634), MR4.5 (67%, 30634)
- **MR4.5** ← MR4 (100%, 141901), MR3 (67%, 30634), MR5 (61%, 32362)
- **MR4** ← MR4.5 (100%, 141901), MR3 (67%, 30634), MR5 (61%, 32362)
- **MR5** ← MR3 (73%, 33295), MR4 (61%, 32362), MR4.5 (61%, 32362)
- **QD25** ← MP330 (66%, 37590), R990BT (57%, 25908), ES60 (55%, 32173)
- **QR30** ← R990BT (59%, 26653), MR5 (56%, 29351), QS20 (55%, 26801)
- **QS20** ← ES20 (69%, 33171), ES60 (67%, 32297), QR30 (55%, 26801)
- **R990BT** ← QR30 (59%, 26653), QD25 (57%, 25908), MP330 (57%, 25856)
- **S355DB** ← MR4 (57%, 3993), MR4.5 (57%, 3993), MR5 (53%, 3702)

## 5. Уникальные значимые строки моделей

### ES20_1.0.4_00812d5a — 2646 уникальных значимых строк

- ` !"#$%ASSERT-FAILD: j < ARRAY_SIZE(PC_valid) Invalid I/O : %c - %d`
- ` %s len %d, sizeof(cfg) %ld`
- ` %s len %d, sizeof(cfg) %lu`
- ` DBG_Q32S_RW`
- ` EMU_CON = `
- ` EMU_MSG = `
- ` FS_IOCTL_FILE_CHECK `
- ` JL_CEMU->MSG0: `
- ` JL_CEMU->MSG1: `
- ` JL_CEMU->MSG2: `
- ` JL_HEMU->MSG0: `
- ` JL_LEMU->MSG0: `
- ` OSMutexDel OSEventType ERR 0x%x!`
- ` OSMutexPend OSEventType ERR %p, %x, %s`
- ` OSMutexPost OSEventType ERR 0x%p!`
- ` OSSemPost OSEventType ERR 0x%x!`
- ` OSSemSet OSEventType ERR 0x%x!`
- ` OTA_UPGRADE_READY (%d):`
- ` OTA_UPGRADE_SEND_DATA (%d):`
- ` T_sco<6 value , please check`
- ` [X-ICACHE] emu err msg : `
- ` [Y-DCACHE] emu err msg : `
- ` _DCU_EMU_MSG: `
- ` _ICU_EMU_MSG: `
- ` `[AUDIO-DAC]dac off`
- ` channel_classification_req `
- ` channel_classification_req %x %x %x`
- ` dac_input > resampled_out :  %d `
- ` default eq0 cfg %d `
- ` default scene %d `
- ` wancy gggggggggggggg:`
- ` wancybbbbbbbbbb:`
- ` wancydddddddddddd:`
- ` wancyeeeeeeeee:`
- `!!!!!unknow:ctrl_type`
- `!DBG_AXI_M1`
- `###file head crc verify fail`
- `###fix ble list:%d`
- `###reset ble list`
- `###verify app_dir file`
- … ещё 2606

### ES60_1.0.3_17302784 — 3035 уникальных значимых строк

- ` !"#$%ASSERT-FAILD: j < ARRAY_SIZE(PC_valid) Invalid I/O : %c - %d`
- ` %s len %d, sizeof(cfg) %ld`
- ` %s len %d, sizeof(cfg) %lu`
- ` 4"JKOMN`
- ` DBG_Q32S_RW`
- ` EMU_CON = `
- ` EMU_MSG = `
- ` FS_IOCTL_FILE_CHECK `
- ` JL_CEMU->MSG0: `
- ` JL_CEMU->MSG1: `
- ` JL_CEMU->MSG2: `
- ` JL_HEMU->MSG0: `
- ` JL_LEMU->MSG0: `
- ` OSMutexDel OSEventType ERR 0x%x!`
- ` OSMutexPend OSEventType ERR %p, %x, %s`
- ` OSMutexPost OSEventType ERR 0x%p!`
- ` OSSemPost OSEventType ERR 0x%x!`
- ` OSSemSet OSEventType ERR 0x%x!`
- ` OTA_UPGRADE_READY (%d):`
- ` OTA_UPGRADE_SEND_DATA (%d):`
- ` T_sco<6 value , please check`
- ` [X-ICACHE] emu err msg : `
- ` [Y-DCACHE] emu err msg : `
- ` _DCU_EMU_MSG: `
- ` _ICU_EMU_MSG: `
- ` `[AUDIO-DAC]dac off`
- ` channel_classification_req `
- ` channel_classification_req %x %x %x`
- ` dac_input > resampled_out :  %d `
- ` default eq0 cfg %d `
- ` default scene %d `
- ` wancy gggggggggggggg:`
- ` wancybbbbbbbbbb:`
- ` wancydddddddddddd:`
- ` wancyeeeeeeeee:`
- `!!!!!unknow:ctrl_type`
- `!DBG_AXI_M1`
- `"VV*@XCYB`
- `###file head crc verify fail`
- `###fix ble list:%d`
- … ещё 2995

### MP330_1.0.2_b77539e8 — 2981 уникальных значимых строк

- ` !"#$%ASSERT-FAILD: j < ARRAY_SIZE(PC_valid) Invalid I/O : %c - %d`
- ` %s len %d, sizeof(cfg) %ld`
- ` %s len %d, sizeof(cfg) %lu`
- ` ----music_player_play_prev succ %d-------`
- ` 4"JKOMN`
- ` CiBjAk@nC`
- ` DBG_Q32S_RW`
- ` EMU_CON = `
- ` EMU_MSG = `
- ` FS_IOCTL_FILE_CHECK `
- ` JL_CEMU->MSG0: `
- ` JL_CEMU->MSG1: `
- ` JL_CEMU->MSG2: `
- ` JL_HEMU->MSG0: `
- ` JL_LEMU->MSG0: `
- ` OSMutexDel OSEventType ERR 0x%x!`
- ` OSMutexPend OSEventType ERR %p, %x, %s`
- ` OSMutexPost OSEventType ERR 0x%p!`
- ` OSSemDel OSEventType ERR 0x%x!`
- ` OSSemPost OSEventType ERR 0x%x!`
- ` OSSemSet OSEventType ERR 0x%x!`
- ` OTA_UPGRADE_READY (%d):`
- ` OTA_UPGRADE_SEND_DATA (%d):`
- ` T_sco<6 value , please check`
- ` [X-ICACHE] emu err msg : `
- ` [Y-DCACHE] emu err msg : `
- ` _DCU_EMU_MSG: `
- ` _ICU_EMU_MSG: `
- ` `[AUDIO-DAC]dac off`
- ` app_var.cycle_mode:[%d] set to [%d]`
- ` channel_classification_req `
- ` channel_classification_req %x %x %x`
- ` dac_input > resampled_out :  %d `
- ` default eq0 cfg %d `
- ` default scene %d `
- ` r Iqa!Ip`sfB%c`
- ` wancybbbbbbbbbb:`
- ` wancydddddddddddd:`
- ` wancyeeeeeeeee:`
- `!!!!!unknow:ctrl_type`
- … ещё 2941

### MR3_1.0.7_acb5d6b3 — 179 уникальных значимых строк

- ` DBG_Q32S_RW`
- ` `DUT+TST+BLE+NAM+GET+`
- `!DBG_AXI_M1`
- `*PjBx>C!`
- `2usb_stack`
- `36<BHNTZ`fl`
- `@eh%CXa0`
- `A2DP_RX6`
- `A2DP_RX7`
- `A8E?D<F;G`
- `A@"YhZi*`
- `AUX_DAC_GAIN`
- `AUX_DAC_GAIN2`
- `BLT+BUTTON+IO4+1`
- `BLT+BUTTON+IO5+1`
- `BLT+BUTTON+IO6+1`
- `BassShelf`
- `BassShelf_LB2`
- `BassShelf_LB3`
- `BassShelf_LB4`
- `Bjqg@a%aJ`
- `BzC"K{@zA`
- `CcBfAe@a3b`
- `DBG_ALNK0`
- `DBG_AUDIO`
- `DBG_AXI_1F`
- `DBG_AXI_M2`
- `DBG_AXI_M3_DCP`
- `DBG_AXI_M4_JPG`
- `DBG_AXI_M5_IMB`
- `DBG_AXI_M6_IMD`
- `DBG_AXI_M7_IMG`
- `DBG_AXI_M8`
- `DBG_AXI_M9`
- `DBG_AXI_MA`
- `DBG_AXI_MB`
- `DBG_AXI_MC`
- `DBG_AXI_MD`
- `DBG_AXI_ME`
- `DBG_AXI_MF`
- … ещё 139

### MR4.5_1.0.1_fb09ee14 — 176 уникальных значимых строк

- ` '.7ALXer`
- ` DBG_Q32S_RW`
- ` `DUT+TST+BLE+NAM+GET+`
- `!'-4<ENYcoz`
- `!DBG_AXI_M1`
- `#*1:DNZfs`
- `$)07>GPZeoz`
- `$*1:BLWbnz`
- `36<BHNTZ`fl`
- `@eh%CXa0`
- `A2DP_RX6`
- `A2DP_RX7`
- `A8E?D<F;G`
- `A@"YhZi*`
- `AUX_DAC_GAIN`
- `AUX_DAC_GAIN2`
- `BLT+BUTTON+IO4+1`
- `BLT+BUTTON+IO5+1`
- `BLT+BUTTON+IO6+1`
- `BassShelf_LB3`
- `BassShelf_LB4`
- `Bjqg@a%aJ`
- `BzC"K{@zA`
- `CcBfAe@a3b`
- `DBG_ALNK0`
- `DBG_AUDIO`
- `DBG_AXI_1F`
- `DBG_AXI_M2`
- `DBG_AXI_M3_DCP`
- `DBG_AXI_M4_JPG`
- `DBG_AXI_M5_IMB`
- `DBG_AXI_M6_IMD`
- `DBG_AXI_M7_IMG`
- `DBG_AXI_M8`
- `DBG_AXI_M9`
- `DBG_AXI_MA`
- `DBG_AXI_MB`
- `DBG_AXI_MC`
- `DBG_AXI_MD`
- `DBG_AXI_ME`
- … ещё 136

### MR4_MKII_1.0.1_d5acc167 — 176 уникальных значимых строк

- ` '.7ALXer`
- ` DBG_Q32S_RW`
- ` `DUT+TST+BLE+NAM+GET+`
- `!'-4<ENYcoz`
- `!DBG_AXI_M1`
- `#*1:DNZfs`
- `$)07>GPZeoz`
- `$*1:BLWbnz`
- `36<BHNTZ`fl`
- `@eh%CXa0`
- `A2DP_RX6`
- `A2DP_RX7`
- `A8E?D<F;G`
- `A@"YhZi*`
- `AUX_DAC_GAIN`
- `AUX_DAC_GAIN2`
- `BLT+BUTTON+IO4+1`
- `BLT+BUTTON+IO5+1`
- `BLT+BUTTON+IO6+1`
- `BassShelf_LB3`
- `BassShelf_LB4`
- `Bjqg@a%aJ`
- `BzC"K{@zA`
- `CcBfAe@a3b`
- `DBG_ALNK0`
- `DBG_AUDIO`
- `DBG_AXI_1F`
- `DBG_AXI_M2`
- `DBG_AXI_M3_DCP`
- `DBG_AXI_M4_JPG`
- `DBG_AXI_M5_IMB`
- `DBG_AXI_M6_IMD`
- `DBG_AXI_M7_IMG`
- `DBG_AXI_M8`
- `DBG_AXI_M9`
- `DBG_AXI_MA`
- `DBG_AXI_MB`
- `DBG_AXI_MC`
- `DBG_AXI_MD`
- `DBG_AXI_ME`
- … ещё 136

### MR5_1.0.3_1c89dcaf — 186 уникальных значимых строк

- ` '.7ALXer`
- ` DBG_Q32S_RW`
- ` `DUT+TST+BLE+NAM+GET+`
- `!'-4<ENYcoz`
- `!DBG_AXI_M1`
- `#*1:DNZfs`
- `$)07>GPZeoz`
- `$*1:BLWbnz`
- `2usb_stack`
- `36<BHNTZ`fl`
- `@eh%CXa0`
- `A2DP_RX6`
- `A2DP_RX7`
- `A8E?D<F;G`
- `A@"YhZi*`
- `AUX_DAC_GAIN`
- `AUX_DAC_GAIN2`
- `BLT+BUTTON+IO4+1`
- `BLT+BUTTON+IO5+1`
- `BLT+BUTTON+IO6+1`
- `BassShelf_LB3`
- `BassShelf_LB4`
- `Bjqg@a%aJ`
- `BzC"K{@zA`
- `CcBfAe@a3b`
- `DBG_ALNK0`
- `DBG_AUDIO`
- `DBG_AXI_1F`
- `DBG_AXI_M2`
- `DBG_AXI_M3_DCP`
- `DBG_AXI_M4_JPG`
- `DBG_AXI_M5_IMB`
- `DBG_AXI_M6_IMD`
- `DBG_AXI_M7_IMG`
- `DBG_AXI_M8`
- `DBG_AXI_M9`
- `DBG_AXI_MA`
- `DBG_AXI_MB`
- `DBG_AXI_MC`
- `DBG_AXI_MD`
- … ещё 146

### QD25_1.0.1_37f4020f — 2676 уникальных значимых строк

- ` !"#$%ASSERT-FAILD: j < ARRAY_SIZE(PC_valid) Invalid I/O : %c - %d`
- ` %s len %d, sizeof(cfg) %ld`
- ` %s len %d, sizeof(cfg) %lu`
- ` 4"JKOMN`
- ` DBG_Q32S_RW`
- ` EMU_CON = `
- ` EMU_MSG = `
- ` FS_IOCTL_FILE_CHECK `
- ` JL_CEMU->MSG0: `
- ` JL_CEMU->MSG1: `
- ` JL_CEMU->MSG2: `
- ` JL_HEMU->MSG0: `
- ` JL_LEMU->MSG0: `
- ` OSMutexDel OSEventType ERR 0x%x!`
- ` OSMutexPend OSEventType ERR %p, %x, %s`
- ` OSMutexPost OSEventType ERR 0x%p!`
- ` OSSemPost OSEventType ERR 0x%x!`
- ` OSSemSet OSEventType ERR 0x%x!`
- ` T_sco<6 value , please check`
- ` [X-ICACHE] emu err msg : `
- ` [Y-DCACHE] emu err msg : `
- ` _DCU_EMU_MSG: `
- ` _ICU_EMU_MSG: `
- ` `[AUDIO-DAC]dac off`
- ` channel_classification_req `
- ` channel_classification_req %x %x %x`
- ` dac_input > resampled_out :  %d `
- ` debug CPU`
- ` default eq0 cfg %d `
- ` default scene %d `
- `!!!!!unknow:ctrl_type`
- `!DBG_AXI_M1`
- `"VV*@XCYB`
- `###file head crc verify fail`
- `###fix ble list:%d`
- `###reset ble list`
- `###verify app_dir file`
- `##A2DP header error : %d`
- `#B0RK 8RQ`
- `$CXD%FUD.F`
- … ещё 2636

### QR30_1.0.2_63197d81 — 168 уникальных значимых строк

- ` DBG_Q32S_RW`
- ` `DUT+TST+BLE+NAM+GET+`
- `!DBG_AXI_M1`
- `"VV*@XCYB`
- `2o1n4lSfVgUh )@`
- `36<BHNTZ`fl`
- `@eh%CXa0`
- `A8E?D<F;G`
- `A@"YhZi*`
- `Audve :@`
- `BLT+BUTTON+IO4+1`
- `BLT+BUTTON+IO5+1`
- `BLT+BUTTON+IO6+1`
- `BLT+BUTTON+IO7+1`
- `BdAcDaumvn@`
- `Bjqg@a%aJ`
- `BzC"K{@zA`
- `CcBfAe@a3b`
- `DBG_ALNK0`
- `DBG_AUDIO`
- `DBG_AXI_1F`
- `DBG_AXI_M2`
- `DBG_AXI_M3_DCP`
- `DBG_AXI_M4_JPG`
- `DBG_AXI_M5_IMB`
- `DBG_AXI_M6_IMD`
- `DBG_AXI_M7_IMG`
- `DBG_AXI_M8`
- `DBG_AXI_M9`
- `DBG_AXI_MA`
- `DBG_AXI_MB`
- `DBG_AXI_MC`
- `DBG_AXI_MD`
- `DBG_AXI_ME`
- `DBG_AXI_MF`
- `DBG_CPU0_IF`
- `DBG_CPU0_RD`
- `DBG_CPU0_WR`
- `DBG_CPU1_IF`
- `DBG_CPU1_RD`
- … ещё 128

### QS20_1.0.1_f0359f4f — 2089 уникальных значимых строк

- ` $1ZjOkN`
- ` %s len %d, sizeof(cfg) %ld`
- ` %s len %d, sizeof(cfg) %lu`
- ` DBG_Q32S_RW`
- ` FS_IOCTL_FILE_CHECK `
- ` OSMutexDel OSEventType ERR 0x%x!`
- ` OSMutexPend OSEventType ERR %p, %x, %s`
- ` OSMutexPost OSEventType ERR 0x%p!`
- ` OSSemPost OSEventType ERR 0x%x!`
- ` OSSemSet OSEventType ERR 0x%x!`
- ` T_sco<6 value , please check`
- ` `[AUDIO-DAC]dac off`
- ` channel_classification_req `
- ` channel_classification_req %x %x %x`
- ` dac_input > resampled_out :  %d `
- ` default eq0 cfg %d `
- ` default scene %d `
- `!!!!!unknow:ctrl_type`
- `!DBG_AXI_M1`
- `###file head crc verify fail`
- `###fix ble list:%d`
- `###reset ble list`
- `###verify app_dir file`
- `##A2DP header error : %d`
- `$QE`%OXKI`
- `%d: led ui uuid 0x%x not found`
- `%s bit_wide, %d %d %d`
- `%s len %d, sizeof(cfg) %lu`
- `%s() PINR_CON %x PORT_SEL %x`
- `%s, read node data err`
- `&Eli$@ah`
- `--- iis_file_init ---`
- `-------hfp----->prepare send fail buf %x`
- `----fs_open_dir_info----`
- `---spp connect:%x`
- `---spp disconnect:%x`
- `--FR_FIND_FILE `
- `--check_rec_ext %s   ext %s`
- `--enter_esco_cb: %d`
- `--monitor_start_play`
- … ещё 2049

### R990BT_1.0.1_f3977118 — 163 уникальных значимых строк

- ` CiBjAk@nC`
- ` DBG_Q32S_RW`
- ` THEF G!A!`
- `!DBG_AXI_M1`
- `#B0RK 8RQ`
- `$CXD%FUD.F`
- `%X,VBT*V0`
- `%Z.XOSXC^C`
- `&jbdAfpdvdYc`
- `'LMD7H5H@FIFf!m`
- `+@sT+BsR*e`
- `,T^RXRZRKB`
- `,x+xht$zHv`
- `36<BHNTZ`fl`
- `7F9FETFT;V1V8F/F`
- `>HGF9H8HhD`
- `@eh%CXa0`
- `A8E?D<F;G`
- `A@"YhZi*`
- `AUX_Energy`
- `BLT+BUTTON+IO6+1`
- `BT_Energy`
- `BZC"O[@ZA`
- `BdPd!jBv2x`
- `Bjqg@a%aJ`
- `Bt?tMt.x |`
- `CRY574Pro`
- `CcBfAe@a3b`
- `D&D'Ddb#hcb`
- `DBG_ALNK0`
- `DBG_AUDIO`
- `DBG_AXI_1F`
- `DBG_AXI_M2`
- `DBG_AXI_M3_DCP`
- `DBG_AXI_M4_JPG`
- `DBG_AXI_M5_IMB`
- `DBG_AXI_M6_IMD`
- `DBG_AXI_M7_IMG`
- `DBG_AXI_M8`
- `DBG_AXI_M9`
- … ещё 123

### S355DB_2.1.1_f49205a2 — 2000 уникальных значимых строк

- `      Max channels: %d`
- `      Supported sample rates (kHz): `
- `      Supported sample sizes (bits): `
- `     Source physical address: %02X %02X`
- `  Basic audio support`
- `  Revision: 3`
- `  Supports YCbCr 4:4:2`
- `  Supports YCbCr 4:4:4`
- `  Underscans IT Video Formats by default`
- ` %s len %d, sizeof(cfg) %d`
- ` '.7ALXer`
- ` =lmp_default_stage= no hci cmd,please check  `
- ` CEC_MUTE CTL %d `
- ` Ca`!AB P`
- ` FS_IOCTL_FILE_CHECK `
- ` HDMI_DET_BY_IO `
- ` Native detailed modes:%d`
- ` OSMutexPend OSEventType ERR %p, %x, %s`
- ` OTA_UPGRADE_READY (%d):`
- ` OTA_UPGRADE_SEND_DATA (%d):`
- ` TV > SB  Vol +u8SbVol=%x, u8AudioVolume=%d`
- ` default eq0 cfg %d `
- ` default scene %d `
- ` iic scl[%x]sda[%x] `
- ` share conn HCI_EVENT_CONNECTION_COMPLETE`
- ` wancybbbbbbbbbb:`
- ` wancydddddddddddd:`
- ` wancyeeeeeeeee:`
- `!'-4<ENYcoz`
- `!Ph0q1B!C`
- `!Ph0q2B!C`
- `!ph0y<B!C`
- `###file head crc verify fail`
- `###verify app_dir file`
- `##A2DP header error : %d`
- `#*1:DNZfs`
- `#fail:config_le_gatt_client_num = 0!!!`
- `$)07>GPZeoz`
- `$*1:BLWbnz`
- `$JRj"BIg!@.`
- … ещё 1960

## 6. Общие строки всех 12 моделей (ядро SDK)

Всего 540; примеры:

- `         (((((                  `
- ` "$&(*,.`
- ` "$&H1`
- ` $9Gp`
- ` 0EiG`u`
- ` 8B8T`
- ` @!B!`
- ` @3B!`
- ` A 0H`
- ` A F `
- ` A!@!`
- ` B C!F q`
- ` M$Tc`
- ` R3C `
- ` `A B `
- ` i@Eo`
- `!@ A?C @`
- `!@ C `
- `!@$z<c'`
- `!@'A$C `
- `!@*A$B&`
- `!@?{>@`
- `!A B$C `
- `!A C `
- `!A#C `
- `!HAIC`
- `!PA!C'@`
- `!`#a b%``
- `!z<[+`
- `"3DUf`
- `"D E `
- `#@ A `
- `#B C `
- `#D E C F `
- `#HJII`
- `$B C A `
- `%A C!`
- `%A r-E `
- `%A@ A `
- `%AB C `
- `&@ A `
- `':B9A8@q`
- `'B C `
- `(@B`xB3`
- `(BC A`
- `,pA B`
- `0 A @`
- `0 ic@0!`
- `0Ph@P`
- `1111C0101`
- `111C014`
- `112222`
- `11C010`
- `141C010`
- `1C004`
- `1C008`
- `1C016`
- `1H11A`
- `1H11A2221`
- `1H122`
- `1H222`
- `1HA11`
- `1Hc08`
- `1b0`!`
- `22222`
- `4)C+B`
- `4PiIhJ`
- `4b5c6b`
- `5)C+B`
- `7`&`d`
- `8BAlBi```
- `8F9AR`
- `:3r.O`
- `<bb @`
- `?@ B `
- `?E G `
- `?Mf3/`
- `?pZx`E `
- `@ @`U`
- `@ A P`

## 7. Выводы

1. **MR4.5 ≡ MR4_MKII** — образы практически идентичны
   (141 901 общий чанк, ~99 %); это одна прошивка под двумя именами.
2. **Линейка MR** (MR3, MR4/MR4.5, MR5) — ближайшие родственники
   (61–73 % общих чанков), общий SDK-слой + продуктовые отличия.
3. **Кластер ES20/QS20/ES60** (67–69 %) — вторая ветка (большие образы,
   780–860 КБ, другой набор задач); MP330 тяготеет к QD25/R990BT.
4. **S355DB** — самая обособленная (доля общих чанков от её набора мала,
   но ~3К чанков всё же общие с MR-линейкой) — другой чип/поколение SDK.
5. Позиционные совпадения почти нулевые ⇒ каждая модель слинкована
   независимо; сравнивать можно только по чанкам/функциям.
6. У MR5 **969 функций** имеют хотя бы один 64-Б чанк, совпадающий с
   другой моделью; топ общих регионов — кандидаты в «SDK-слой» (B3):
   байты в них можно считать эталонными для сигнатурного матчинга.
