import re

f = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\firmware.bin'
data = open(f,'rb').read()
body = data[0x206:]  # after header guess; use whole file too

def scan(d, name):
    calls = len(re.findall(rb'\xbf\xf3', d))
    movs = len(re.findall(rb'[\xc0-\xcf]\xff', d))
    nop = len(re.findall(rb'\x00\x00', d))
    push = len(re.findall(rb'\x74\x01', d))
    print(f'{name:28s} len={len(d)} call={calls} mov32={movs} nop={nop} push={push}')

def cumxor(b):
    out = bytearray(len(b)); x = 0
    for i,v in enumerate(b):
        x ^= v; out[i] = x
    return bytes(out)

def cumadd(b):
    out = bytearray(len(b)); s = 0
    for i,v in enumerate(b):
        s = (s+v) & 0xFF; out[i] = s
    return bytes(out)

def delta(b, op):
    out = bytearray(len(b))
    for i in range(1, len(b)):
        out[i] = (b[i]-b[i-1]) & 0xFF if op=='sub' else b[i]^b[i-1]
    return bytes(out)

def runcum(b):
    # inverse of delta-sub
    out = bytearray(len(b)); s = 0
    for i,v in enumerate(b):
        s = (s+v) & 0xFF; out[i] = s
    return bytes(out)

scan(body, 'raw')
scan(cumxor(body), 'cumxor')
scan(cumadd(body), 'cumadd')
scan(delta(body,'sub'), 'delta-sub')
scan(delta(body,'xor'), 'delta-xor')
# reversed cumulative (from end)
rev = body[::-1]
scan(runcum(rev)[::-1], 'runcum-rev')
