#!/usr/bin/env python3
"""B3 v2: mine the JieLi SDK's linked sdk.elf (br28 / pi32v2) for function
signatures and byte-match them against the MR5 firmware.

sdk.elf is fully linked -> bytes are final (no relocations). For every
FUNC symbol (GLOBAL/WEAK, size > 0) take the code bytes and search the
MR5 app image for an exact, unique match (several anchor windows are
tried to tolerate compile-flag differences inside a function).

usage: python b3_sigs2.py <sdk.elf> [out.json]
"""
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
APP = os.path.join(SRC, 'decrypted', 'app_bin_full.bin')


def load_elf_funcs(path):
    """Return [(name, addr, code_bytes)] for FUNC symbols of a 32-bit LE ELF."""
    obj = open(path, 'rb').read()
    assert obj[:4] == b'\x7fELF' and obj[4] == 1, 'not ELF32'
    e_shoff, = struct.unpack_from('<I', obj, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from('<HHH', obj, 0x2e)
    shs = []
    for i in range(e_shnum):
        sh = struct.unpack_from('<10I', obj, e_shoff + i * e_shentsize)
        shs.append(dict(zip(
            ('name', 'type', 'flags', 'addr', 'offset', 'size',
             'link', 'info', 'addralign', 'entsize'), sh)))
    shstr = shs[e_shstrndx]

    def sname(n):
        s = obj[shstr['offset'] + n:]
        return s[:s.find(b'\0')].decode('ascii', 'replace')

    # section index by (offset,size) for VA->file mapping; linked ELF has
    # addr set, so use addr directly
    funcs = []
    for st in (s for s in shs if s['type'] == 2):
        strtab = shs[st['link']]
        for i in range(st['size'] // 16):
            nameo, val, sz, info, other, shndx = struct.unpack_from(
                '<IIIBBH', obj, st['offset'] + i * 16)
            if not sz or shndx >= len(shs):
                continue
            if info & 0xf != 2:  # STT_FUNC
                continue
            if info >> 4 not in (0, 1, 2):  # LOCAL too: rom/local labels ok
                continue
            sec = shs[shndx]
            if sec['type'] != 1 and sec['type'] != 8:
                continue
            nm = obj[strtab['offset'] + nameo:]
            nm = nm[:nm.find(b'\0')].decode('ascii', 'replace')
            if not nm or '.' in nm.split('__')[-1][:1] and False:
                continue
            if sec['type'] == 1:
                code = obj[sec['offset'] + (val - sec['addr']):
                           sec['offset'] + (val - sec['addr']) + sz]
            else:
                code = b''
            if len(code) == sz:
                funcs.append((nm, val, code))
    return funcs


def main():
    elf_path = sys.argv[1]
    out = sys.argv[2] if len(sys.argv) > 2 else \
        os.path.join(SRC, 'disasm', 'b3_signatures.json')
    data = open(APP, 'rb').read()
    funcs = load_elf_funcs(elf_path)
    print(f'sdk.elf FUNC symbols with code: {len(funcs)}')

    sigs = {}
    st_unique = st_multi = st_absent = 0
    for nm, addr, code in funcs:
        if len(code) < 16:
            continue
        hit = None
        # anchor windows across the body (reloc-free zones vary)
        cands = list(range(0, min(len(code), 160), 24))
        if len(code) > 200:
            cands += [len(code) // 2, len(code) // 2 - 24,
                      len(code) - 24, len(code) - 48]
        for ao in cands:
            if ao + 24 > len(code):
                continue
            anchor = code[ao:ao + 24]
            if anchor.count(b'\0\0\0\0') > 1:
                continue
            hits = []
            start = 0
            while True:
                p = data.find(anchor, start)
                if p < 0:
                    break
                hits.append(p)
                start = p + 2
                if len(hits) > 2:
                    break
            if len(hits) == 1:
                cand = hits[0] - ao
                if hit is None:
                    hit = cand
                    n_hits_total = 1
                elif cand == hit:
                    n_hits_total += 1
                else:
                    hit = None
                    break
        if hit is not None and hit >= 0 and hit + len(code) <= len(data):
            # verify at least 80% of 8-byte words match (flag tolerance)
            body = data[hit:hit + len(code)]
            diff = sum(1 for i in range(0, len(code) - 7, 8)
                       if body[i:i + 8] != code[i:i + 8])
            nw = max(1, len(code) // 8)
            if diff / nw <= 0.2:
                sigs[f'{BASE + hit:08x}'] = {
                    'name': nm, 'elf_addr': f'{addr:08x}',
                    'size': len(code), 'words_diff': f'{diff}/{nw}'}
                st_unique += 1
                continue
        if hit is None:
            st_absent += 1
        else:
            st_multi += 1
    print(f'unique byte-matched: {st_unique}; ambiguous: {st_multi}; '
          f'absent: {st_absent}')
    json.dump(sigs, open(out, 'w', encoding='utf-8'), indent=0)
    print('wrote', out, f'({len(sigs)} entries)')


BASE = 0x06000100

if __name__ == '__main__':
    main()
