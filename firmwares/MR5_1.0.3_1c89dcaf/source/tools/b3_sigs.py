#!/usr/bin/env python3
"""B3: mine JieLi SDK static libraries (.a with symbol tables) for function
signatures, and byte-match them against the MR5 firmware.

Method:
  1. Parse each .a (ar archive) -> ELF32 objects.
  2. For every FUNC symbol (GLOBAL/WEAK) take its code bytes from the
     containing section.
  3. Search the first 24 bytes of the function in the MR5 app image
     (exact match, unique hit required).
  4. Emit disasm/b3_signatures.json: {addr: name}.

usage: python b3_sigs.py <dir-with-.a> [more dirs...]
"""
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
SRC = os.path.dirname(HERE)
APP = os.path.join(SRC, 'decrypted', 'app_bin_full.bin')
OUT = os.path.join(SRC, 'disasm', 'b3_signatures.json')

BASE = 0x06000100


def iter_ar(data):
    """Yield (name, bytes) for members of a Unix ar archive."""
    if data[:8] != b'!<arch>\n':
        return
    off = 8
    long_names = []
    while off + 60 <= len(data):
        hdr = data[off:off + 60]
        name = hdr[0:16].decode('ascii', 'replace').strip()
        size = int(hdr[48:58].decode('ascii', 'replace').strip())
        body = data[off + 60:off + 60 + size]
        off += 60 + size + (size & 1)
        if name.startswith('//'):
            # extended names table: '/<n>' style
            long_names = body.split(b'\n')
            continue
        if name.startswith('/'):
            try:
                idx = int(name[1:])
            except ValueError:
                idx = -1
            if idx >= 0 and 0 <= idx - 4 < len(long_names):
                name = long_names[idx - 4].decode('ascii', 'replace').rstrip('/')
        yield name, body


def parse_elf(obj):
    """Return [(name, code_bytes)] for FUNC symbols in an ELF32 object."""
    if obj[:4] != b'\x7fELF':
        return []
    if obj[4] != 1:  # ELFCLASS32
        return []
    e_shoff, = struct.unpack_from('<I', obj, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from('<HHH', obj, 0x2e)
    if not e_shoff or not e_shnum:
        return []
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
    symtabs = [s for s in shs if s['type'] == 2]  # SHT_SYMTAB
    out = []
    for st in symtabs:
        strtab = shs[st['link']]
        n = st['size'] // 16
        syms = []
        for i in range(n):
            nameo, val, sz, info, other, shndx = struct.unpack_from(
                '<IIIBBH', obj, st['offset'] + i * 16)
            if not sz or not shndx or shndx >= len(shs):
                continue
            bind = info >> 4
            typ = info & 0xf
            if typ != 2:  # STT_FUNC
                continue
            if bind not in (1, 2):  # GLOBAL, WEAK
                continue
            sec = shs[shndx]
            if sec['type'] != 1:  # PROGBITS
                continue
            s = obj[sec['offset'] + val: sec['offset'] + val + sz]
            nm = obj[strtab['offset'] + nameo:]
            nm = nm[:nm.find(b'\0')].decode('ascii', 'replace')
            if nm and len(s) == sz:
                syms.append((nm, s))
        out.extend(syms)
    return out


def main():
    data = open(APP, 'rb').read()
    sigs = {}
    stats = {'libs': 0, 'objs': 0, 'funcs': 0, 'unique': 0,
             'multi': 0, 'absent': 0}
    for root in sys.argv[1:]:
        for dirpath, _, files in os.walk(root):
            for fn in sorted(files):
                if not fn.endswith('.a'):
                    continue
                path = os.path.join(dirpath, fn)
                lib = open(path, 'rb').read()
                stats['libs'] += 1
                for oname, obj in iter_ar(lib):
                    stats['objs'] += 1
                    for nm, code in parse_elf(obj):
                        stats['funcs'] += 1
                        if len(code) < 16:
                            continue
                        anchor = code[:24]
                        # skip functions with embedded relocations missing
                        # (zeros are fine; relocation patching may alter
                        # a few words - tolerate by trying 3 anchors)
                        hits = []
                        start = 0
                        while True:
                            p = data.find(anchor, start)
                            if p < 0:
                                break
                            hits.append(p)
                            start = p + 2
                            if len(hits) > 4:
                                break
                        if len(hits) == 1:
                            addr = BASE + hits[0]
                            sigs[f'{addr:08x}'] = {'name': nm,
                                                   'lib': os.path.basename(fn),
                                                   'size': len(code)}
                            stats['unique'] += 1
                        elif hits:
                            stats['multi'] += 1
                        else:
                            # retry with a mid-function anchor
                            if len(code) >= 48:
                                anchor = code[24:48]
                                p = data.find(anchor)
                                if p >= 0 and data.find(anchor, p + 2) < 0:
                                    addr = BASE + p - 24
                                    sigs[f'{addr:08x}'] = {
                                        'name': nm,
                                        'lib': os.path.basename(fn),
                                        'size': len(code), 'mid': True}
                                    stats['unique'] += 1
                                    continue
                            stats['absent'] += 1
        print(f'{root}: {stats}')
    json.dump(sigs, open(OUT, 'w', encoding='utf-8'), indent=0)
    print('unique signatures:', len(sigs))
    print('wrote', OUT)


if __name__ == '__main__':
    main()
