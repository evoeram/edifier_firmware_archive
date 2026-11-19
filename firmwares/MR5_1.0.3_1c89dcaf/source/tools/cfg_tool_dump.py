# -*- coding: utf-8 -*-
# MR5BT full flash dumper: JieLi cfg_tool over UART (READ-ONLY).
# Использование: python cfg_tool_dump.py COM5 921600 out.bin [start] [end]
# Опасные команды (0x24 ERASE, 0x25 WRITE, 0x26 ENTER_UPGRADE, 0x505 RESET) не реализованы.
import sys, time, struct
import serial  # pip install pyserial

T_VISUAL = 0x21
OP_QUERY_BASIC_INFO = 0x00000400
OP_QUERY_FILE_SIZE  = 0x0000000B
OP_READ_ADDR_RANGE  = 0x00000027

def crc16_reflect(data, poly_rev, init):
    crc = init
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ poly_rev if crc & 1 else crc >> 1
    return crc

def crc16_ccitt_false(data):
    crc = 0xFFFF
    for b in data:
        crc ^= b << 8
        for _ in range(8):
            crc = ((crc << 1) ^ 0x1021) & 0xFFFF if crc & 0x8000 else (crc << 1) & 0xFFFF
    return crc

CRC_VARIANTS = [
    ("CCITT-FALSE", crc16_ccitt_false),
    ("KERMIT", lambda d: crc16_reflect(d, 0x8408, 0x0000)),
    ("MCRF4XX", lambda d: crc16_reflect(d, 0x8408, 0xFFFF)),
]
crc_fn = crc16_ccitt_false

def frame(t, payload, sq=0):
    body = bytes([t, sq]) + payload
    crc = crc_fn(body)
    return bytes([0x5A, 0xAA, 0xA5, crc & 0xFF, (crc >> 8) & 0xFF]) + \
           struct.pack("<H", len(body)) + body

def parse_reply(buf):
    if len(buf) < 9 or buf[:3] != b"\x5A\xAA\xA5":
        return None, buf
    total = 7 + struct.unpack("<H", buf[5:7])[0]
    if len(buf) < total:
        return None, buf
    rx_crc = buf[3] | (buf[4] << 8)
    ok = rx_crc == crc_fn(buf[5:total])
    return (ok, buf[7], buf[8], buf[9:total]), buf[total:]

def read_exact(ser, n, timeout=2.0):
    acc = bytearray()
    end = time.time() + timeout
    while len(acc) < n and time.time() < end:
        chunk = ser.read(n - len(acc))
        acc.extend(chunk)
    return bytes(acc)

def drain(ser, t=0.3):
    end = time.time() + t
    out = bytearray()
    while time.time() < end:
        b = ser.read(4096)
        if b: out.extend(b)
    return bytes(out)

def main():
    port, baud, out = sys.argv[1], int(sys.argv[2]), sys.argv[3]
    start = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0
    end   = int(sys.argv[5], 0) if len(sys.argv) > 5 else 0x200000
    ser = serial.Serial(port, baud, timeout=0.1)
    print("открыт", port, baud)

    # 1) подобрать CRC и убедиться, что cfg_tool жив
    global crc_fn
    alive = False
    for name, fn in CRC_VARIANTS:
        crc_fn = fn
        ser.reset_input_buffer()
        ser.write(frame(T_VISUAL, struct.pack("<I", OP_QUERY_BASIC_INFO)))
        rep, rest = parse_reply(read_exact(ser, 64, 1.0))
        if rep and rep[0]:
            print(f"CRC={name}: OK, ответ {rep[3][:24].hex()}")
            alive = True
            break
        print(f"CRC={name}: тишина")
    if not alive:
        print("cfg_tool не ответил. Проверь подключение TX/RX/GND и скорость (попробуй 115200).")
        return

    # 2) дамп
    CH = 1024
    with open(out, "wb") as f:
        addr = start
        t0 = time.time()
        while addr < end:
            size = min(CH, end - addr)
            ser.reset_input_buffer()
            ser.write(frame(T_VISUAL, struct.pack("<III", OP_READ_ADDR_RANGE, addr, size)))
            rep, rest = parse_reply(read_exact(ser, 9 + size, 2.0))
            if rep is None or not rep[0]:
                print(f"\nошибка/нет CRC на 0x{addr:06X}, повтор...")
                # ждём остаток как сырые данные
                data = rest + read_exact(ser, size, 2.0)
            else:
                data = rep[3]
            if len(data) != size:
                print(f"\nкороткое чтение 0x{addr:06X}: {len(data)}/{size}")
                data += read_exact(ser, size - len(data), 2.0)
            f.write(data)
            addr += size
            if (addr - start) % (64*1024) == 0:
                el = time.time() - t0
                print(f"  0x{addr:06X} / 0x{end:06X}  {el:.0f}с", flush=True)
    print("готово:", out)

if __name__ == "__main__":
    main()
