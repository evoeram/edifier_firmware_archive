#!/usr/bin/env python3
"""Анализ контейнера Edifier OTA (MR5 и других моделей архива).

Воспроизводит проверки из ANALYSIS.md:
  1. карта общего заголовка по всем прошивкам;
  2. энтропия по блокам;
  3. частотные аномалии по классам i mod 32;
  4. повторяющиеся 4-грамы и их смещения (доказательство S-box);
  5. структура 32-байтовых записей в области 0x9C000;
  6. проверка кандидатов S-box (rotl5^05, xor A5).

Запуск:  python analyze_container.py [path\\to\\firmware.bin]
"""
import collections
import glob
import math
import os
import sys

ARCHIVE = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))


def entropy(b):
    c = collections.Counter(b)
    n = len(b)
    return -sum(v / n * math.log2(v / n) for v in c.values())


def header_map():
    files = sorted(glob.glob(os.path.join(ARCHIVE, "firmwares", "*", "firmware.bin")))
    data = {os.path.basename(os.path.dirname(f)): open(f, "rb").read() for f in files}
    big = [n for n in data if not n.startswith("e25HD")]
    ref = data["MR5_1.0.3_1c89dcaf"]
    print("=== 1. Общий заголовок (первые 0x220 байт) ===")
    diffs = []
    for i in range(0x220):
        vals = {data[n][i] for n in big}
        if len(vals) > 1:
            diffs.append(i)
    print(f"общих байт: {0x220 - len(diffs)} из 0x220; пер-файловые смещения:")
    runs = []
    for i in diffs:
        if runs and runs[-1][1] == i:
            runs[-1][1] = i + 1
        else:
            runs.append([i, i + 1])
    for a, b in runs:
        print(f"  {a:#06x}-{b - 1:#06x}")


def entropy_map(path):
    data = open(path, "rb").read()
    print("=== 2. Энтропия по блокам 4K (провалы = структура) ===")
    for i in range(0, len(data), 0x1000):
        e = entropy(data[i:i + 0x1000])
        if e < 7.88:
            print(f"  {i:08x}  {e:.2f}  <-- структурная область")


def ngram_proof(path):
    data = open(path, "rb").read()
    print("=== 3. Доказательство позиционно-независимой подстановки ===")
    c4 = collections.Counter(data[i:i + 4] for i in range(len(data) - 4))
    for g, n in c4.most_common(3):
        pos = []
        i = data.find(g)
        while i >= 0:
            pos.append(i)
            i = data.find(g, i + 1)
        offs = sorted({p % 32 for p in pos})
        print(f"  {g.hex()} x{n}, внутриблочные смещения: {[hex(o) for o in offs]}")


def records(path):
    data = open(path, "rb").read()
    print("=== 4. 32-байтовые записи области 0x9C000 ===")
    fields = collections.Counter(data[0x9C000 + c * 32 + 4:0x9C000 + c * 32 + 8]
                                 for c in range(64))
    for f, n in fields.most_common(10):
        print(f"  {f.hex()} x{n}")


def sbox_candidates(path):
    data = open(path, "rb").read()
    print("=== 5. Кандидаты S-box ===")
    def rotl(x, n): return ((x << n) | (x >> (8 - n))) & 0xFF
    def rotr(x, n): return ((x >> n) | (x << (8 - n))) & 0xFF
    for name, dec in [
        ("rotl5^05", bytes(rotr((b ^ 0x05), 5) for b in data[:0x400])),
        ("xor A5  ", bytes(b ^ 0xA5 for b in data[:0x400])),
    ]:
        printable = sum(1 for b in dec if 32 <= b < 127)
        print(f"  {name}: печатных из первых 0x400: {printable} "
              f"(случайный уровень ~179)")


def main(argv):
    path = argv[1] if len(argv) > 1 else os.path.normpath(
        os.path.join(os.path.dirname(__file__), "..", "firmware.bin"))
    data = open(path, "rb").read()
    print(f"файл: {path}\nразмер: {len(data)}\n")
    header_map()
    print()
    entropy_map(path)
    print()
    ngram_proof(path)
    print()
    records(path)
    print()
    sbox_candidates(path)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
