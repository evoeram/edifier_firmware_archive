# MR5 1.0.3 — таблицы коэффициентов EQ (stream.bin, tag 5)

Источник: `stream.bin` (ресурсный хвост, TLV tag 5), блоки типа 1 (stride 200).
Формат блока: шапка 8 Б + count × 16 Б `{band u16 | type u16 | freq f32 | gain f32 | Q f32}`.
Типы фильтров (по `audio_eq_tab_check` 06065808, switch 0..8):

| тип | фильтр |
|---|---|
| 0 | bypass |
| 1 | lowpass1 |
| 2 | peaking |
| 3 | lowshelf |
| 4 | highshelf |
| 5 | bandpass |
| 6 | notch |
| 7 | lowshelf2 |
| 8 | highshelf2 |

Каждая запись = один «слот» EQ-узла; в графе узел применяет выбранный слот по индексу (idx).

## BassShelf (idx=0, off=0x1f94)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=1, off=0x205c)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=2, off=0x2124)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=3, off=0x21ec)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=4, off=0x22b4)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=5, off=0x237c)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=6, off=0x2444)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=7, off=0x250c)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=8, off=0x25d4)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=9, off=0x269c)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=10, off=0x2764)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=11, off=0x282c)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=12, off=0x28f4)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=13, off=0x29bc)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=14, off=0x2a84)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=15, off=0x2b4c)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=16, off=0x2c14)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=17, off=0x2cdc)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=18, off=0x2da4)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=19, off=0x2e6c)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=20, off=0x2f34)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=21, off=0x2ffc)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=22, off=0x30c4)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=23, off=0x318c)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=24, off=0x3254)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf (idx=25, off=0x331c)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=0, off=0x33e4)

- band0 lowshelf@0Гц -6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=1, off=0x34ac)

- band0 lowshelf@0Гц -5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=2, off=0x3574)

- band0 lowshelf@0Гц -4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=3, off=0x363c)

- band0 lowshelf@0Гц -3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=4, off=0x3704)

- band0 lowshelf@0Гц -2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=5, off=0x37cc)

- band0 lowshelf@0Гц -1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=6, off=0x3894)

- band0 lowshelf@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=7, off=0x395c)

- band0 lowshelf@0Гц +1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=8, off=0x3a24)

- band0 lowshelf@0Гц +2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=9, off=0x3aec)

- band0 lowshelf@0Гц +3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=10, off=0x3bb4)

- band0 lowshelf@0Гц +4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=11, off=0x3c7c)

- band0 lowshelf@0Гц +5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf (idx=12, off=0x3d44)

- band0 lowshelf@0Гц +6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EQDIY (idx=0, off=0x3e0c)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=0, off=0x1f94)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=1, off=0x205c)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=2, off=0x2124)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=3, off=0x21ec)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=4, off=0x22b4)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=5, off=0x237c)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=6, off=0x2444)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=7, off=0x250c)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=8, off=0x25d4)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=9, off=0x269c)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=10, off=0x2764)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=11, off=0x282c)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=12, off=0x28f4)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=13, off=0x29bc)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=14, off=0x2a84)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=15, off=0x2b4c)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=16, off=0x2c14)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=17, off=0x2cdc)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=18, off=0x2da4)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=19, off=0x2e6c)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=20, off=0x2f34)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=21, off=0x2ffc)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=22, off=0x30c4)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=23, off=0x318c)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=24, off=0x3254)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB2 (idx=25, off=0x331c)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=0, off=0x33e4)

- band0 lowshelf@0Гц -6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=1, off=0x34ac)

- band0 lowshelf@0Гц -5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=2, off=0x3574)

- band0 lowshelf@0Гц -4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=3, off=0x363c)

- band0 lowshelf@0Гц -3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=4, off=0x3704)

- band0 lowshelf@0Гц -2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=5, off=0x37cc)

- band0 lowshelf@0Гц -1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=6, off=0x3894)

- band0 lowshelf@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=7, off=0x395c)

- band0 lowshelf@0Гц +1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=8, off=0x3a24)

- band0 lowshelf@0Гц +2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=9, off=0x3aec)

- band0 lowshelf@0Гц +3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=10, off=0x3bb4)

- band0 lowshelf@0Гц +4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=11, off=0x3c7c)

- band0 lowshelf@0Гц +5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB2 (idx=12, off=0x3d44)

- band0 lowshelf@0Гц +6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EQDIY_2 (idx=0, off=0x3ed4)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=0, off=0x3f9c)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=1, off=0x4064)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -1.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=2, off=0x412c)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -2.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=3, off=0x41f4)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -3.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=4, off=0x42bc)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -4.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=5, off=0x4384)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=6, off=0x444c)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -1.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=7, off=0x4514)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -2.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=8, off=0x45dc)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -3.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=9, off=0x46a4)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -4.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic_2 (idx=10, off=0x476c)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=0, off=0x1f94)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=1, off=0x205c)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=2, off=0x2124)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=3, off=0x21ec)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=4, off=0x22b4)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=5, off=0x237c)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=6, off=0x2444)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=7, off=0x250c)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=8, off=0x25d4)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=9, off=0x269c)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=10, off=0x2764)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=11, off=0x282c)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=12, off=0x28f4)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=13, off=0x29bc)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=14, off=0x2a84)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=15, off=0x2b4c)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=16, off=0x2c14)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=17, off=0x2cdc)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=18, off=0x2da4)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=19, off=0x2e6c)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=20, off=0x2f34)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=21, off=0x2ffc)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=22, off=0x30c4)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=23, off=0x318c)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=24, off=0x3254)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB3 (idx=25, off=0x331c)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=0, off=0x33e4)

- band0 lowshelf@0Гц -6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=1, off=0x34ac)

- band0 lowshelf@0Гц -5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=2, off=0x3574)

- band0 lowshelf@0Гц -4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=3, off=0x363c)

- band0 lowshelf@0Гц -3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=4, off=0x3704)

- band0 lowshelf@0Гц -2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=5, off=0x37cc)

- band0 lowshelf@0Гц -1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=6, off=0x3894)

- band0 lowshelf@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=7, off=0x395c)

- band0 lowshelf@0Гц +1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=8, off=0x3a24)

- band0 lowshelf@0Гц +2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=9, off=0x3aec)

- band0 lowshelf@0Гц +3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=10, off=0x3bb4)

- band0 lowshelf@0Гц +4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=11, off=0x3c7c)

- band0 lowshelf@0Гц +5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB3 (idx=12, off=0x3d44)

- band0 lowshelf@0Гц +6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EQDIY_3 (idx=0, off=0x3ed4)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=0, off=0x1f94)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=1, off=0x205c)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=2, off=0x2124)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=3, off=0x21ec)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=4, off=0x22b4)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=5, off=0x237c)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=6, off=0x2444)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=7, off=0x250c)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=8, off=0x25d4)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=9, off=0x269c)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=10, off=0x2764)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=11, off=0x282c)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=12, off=0x28f4)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 lowshelf@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=13, off=0x29bc)

- band0 highshelf@0Гц -6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=14, off=0x2a84)

- band0 highshelf@0Гц -5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=15, off=0x2b4c)

- band0 highshelf@0Гц -4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=16, off=0x2c14)

- band0 highshelf@0Гц -3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=17, off=0x2cdc)

- band0 highshelf@0Гц -2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=18, off=0x2da4)

- band0 highshelf@0Гц -1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=19, off=0x2e6c)

- band0 highshelf@0Гц +0.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=20, off=0x2f34)

- band0 highshelf@0Гц +1.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=21, off=0x2ffc)

- band0 highshelf@0Гц +2.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=22, off=0x30c4)

- band0 highshelf@0Гц +3.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=23, off=0x318c)

- band0 highshelf@0Гц +4.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=24, off=0x3254)

- band0 highshelf@0Гц +5.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## BassShelf_LB4 (idx=25, off=0x331c)

- band0 highshelf@0Гц +6.0дБ Q0.70
- band1 highshelf@0Гц +4.0дБ Q0.70
- band2 lowshelf@0Гц +3.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=0, off=0x33e4)

- band0 lowshelf@0Гц -6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=1, off=0x34ac)

- band0 lowshelf@0Гц -5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=2, off=0x3574)

- band0 lowshelf@0Гц -4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=3, off=0x363c)

- band0 lowshelf@0Гц -3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=4, off=0x3704)

- band0 lowshelf@0Гц -2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=5, off=0x37cc)

- band0 lowshelf@0Гц -1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=6, off=0x3894)

- band0 lowshelf@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=7, off=0x395c)

- band0 lowshelf@0Гц +1.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=8, off=0x3a24)

- band0 lowshelf@0Гц +2.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=9, off=0x3aec)

- band0 lowshelf@0Гц +3.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=10, off=0x3bb4)

- band0 lowshelf@0Гц +4.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=11, off=0x3c7c)

- band0 lowshelf@0Гц +5.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## TrebShelf_LB4 (idx=12, off=0x3d44)

- band0 lowshelf@0Гц +6.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=0, off=0x3f9c)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=1, off=0x4064)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -1.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=2, off=0x412c)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -2.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=3, off=0x41f4)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -3.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=4, off=0x42bc)

- band0 peaking@0Гц +0.0дБ Q2.00
- band1 highshelf@0Гц -4.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=5, off=0x4384)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=6, off=0x444c)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -1.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=7, off=0x4514)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -2.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=8, off=0x45dc)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -3.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=9, off=0x46a4)

- band0 peaking@0Гц -4.0дБ Q2.00
- band1 highshelf@0Гц -4.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## Desk_Acoustic (idx=10, off=0x476c)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EQDIY_4 (idx=0, off=0x3ed4)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EscoUlEq (idx=0, off=0x4834)

- band0 bypass@0Гц +0.0дБ Q0.70
- band1 bypass@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EscoDlEq (idx=0, off=0x48fc)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

## EQ17 (idx=0, off=0x49c4)

- band0 peaking@0Гц +0.0дБ Q0.70
- band1 peaking@0Гц +0.0дБ Q0.70
- band2 peaking@0Гц +0.0дБ Q0.70
- band3 peaking@0Гц +0.0дБ Q0.70
- band4 peaking@0Гц +0.0дБ Q0.70
- band5 peaking@0Гц +0.0дБ Q0.70
- band6 peaking@0Гц +0.0дБ Q0.70
- band7 peaking@0Гц +0.0дБ Q0.70
- band8 peaking@0Гц +0.0дБ Q0.70
- band9 peaking@0Гц +0.0дБ Q0.70
- band10 lowshelf2@0Гц +0.0дБ Q0.70
- band11 highshelf2@0Гц +0.0дБ Q0.70

