#!/usr/bin/env python3
"""Edifier ConneX 1.0.32 — загрузчик прошивок по каталогу моделей.

Воспроизводит запрос /home/api/v1/ota-upgrade:
  product_id, os, mac, current_version, app_version, app, [lang_code],
  timestamp, sign = MD5(sorted(k=v) + secret).toUpperCase()

Standard library only. Примеры:
  python edifier_firmware_downloader.py --model MR5
  python edifier_firmware_downloader.py --all --out ~/firmware
  python edifier_firmware_downloader.py --model S355DB --versions 0.0.0,2.0.0 --dry-run
"""
import argparse
import csv
import hashlib
import json
import re
import sys
import time
import urllib.parse
import urllib.request
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

SIGN_SECRET = "7rn$r44-jM"                    # SignTool.sign(), APK 1.0.32
API_URL = "https://foreign-app.edifier.com/home/api/v1/ota-upgrade"
PRODUCTS = [{'id': 316, 'name': 'D32', 'ota': True, 'last': ''}, {'id': 318, 'name': 'S3000MKII', 'ota': False, 'last': ''}, {'id': 319, 'name': 'NeoBuds Pro 2', 'ota': False, 'last': ''}, {'id': 320, 'name': 'e25HD', 'ota': True, 'last': '1.2.0'}, {'id': 321, 'name': 'QR65', 'ota': True, 'last': ''}, {'id': 323, 'name': 'X5 Pro', 'ota': False, 'last': ''}, {'id': 332, 'name': 'Comfo Run', 'ota': False, 'last': ''}, {'id': 334, 'name': 'W260NC', 'ota': False, 'last': ''}, {'id': 365, 'name': 'R990BT', 'ota': True, 'last': '1.0.2'}, {'id': 369, 'name': 'STAX SPIRIT S5', 'ota': False, 'last': ''}, {'id': 376, 'name': 'W830NB', 'ota': True, 'last': '1.0.7'}, {'id': 377, 'name': 'NeoBuds Pro', 'ota': False, 'last': ''}, {'id': 378, 'name': 'STAX SPIRIT S3', 'ota': False, 'last': ''}, {'id': 379, 'name': 'W240TN', 'ota': False, 'last': ''}, {'id': 380, 'name': 'W220T', 'ota': True, 'last': ''}, {'id': 381, 'name': 'TWS1 Pro 2', 'ota': False, 'last': ''}, {'id': 382, 'name': 'X5 Lite', 'ota': False, 'last': ''}, {'id': 383, 'name': 'MP85', 'ota': False, 'last': ''}, {'id': 389, 'name': 'QS30', 'ota': True, 'last': ''}, {'id': 390, 'name': 'D32', 'ota': True, 'last': ''}, {'id': 393, 'name': 'MG250', 'ota': False, 'last': ''}, {'id': 394, 'name': 'STAX SPIRIT S10', 'ota': True, 'last': '1.1.1'}, {'id': 395, 'name': 'QD35', 'ota': False, 'last': ''}, {'id': 396, 'name': 'X2s', 'ota': False, 'last': ''}, {'id': 397, 'name': 'W320TN', 'ota': True, 'last': ''}, {'id': 398, 'name': 'W160T', 'ota': False, 'last': ''}, {'id': 399, 'name': 'WH700NB', 'ota': False, 'last': ''}, {'id': 400, 'name': 'W110T', 'ota': False, 'last': ''}, {'id': 401, 'name': 'X3 Lite', 'ota': False, 'last': ''}, {'id': 402, 'name': 'W210BT', 'ota': False, 'last': ''}, {'id': 403, 'name': 'W820NB Plus', 'ota': False, 'last': ''}, {'id': 404, 'name': 'WH950NB', 'ota': True, 'last': ''}, {'id': 405, 'name': 'WH500', 'ota': False, 'last': ''}, {'id': 406, 'name': 'W800BT Plus', 'ota': False, 'last': ''}, {'id': 407, 'name': 'W800BT Plus', 'ota': False, 'last': ''}, {'id': 422, 'name': 'NeoDots', 'ota': True, 'last': ''}, {'id': 423, 'name': 'W800BT Pro', 'ota': False, 'last': ''}, {'id': 424, 'name': 'S880DB MKII', 'ota': False, 'last': ''}, {'id': 478, 'name': 'QR30', 'ota': True, 'last': '1.0.2'}, {'id': 482, 'name': 'LolliClip', 'ota': True, 'last': '1.0.4'}, {'id': 481, 'name': 'ES20', 'ota': True, 'last': '1.0.4'}, {'id': 480, 'name': 'ES60', 'ota': True, 'last': '1.0.2'}, {'id': 477, 'name': 'ES850NB', 'ota': False, 'last': ''}, {'id': 471, 'name': 'Atom Max', 'ota': False, 'last': ''}, {'id': 470, 'name': 'T10', 'ota': False, 'last': ''}, {'id': 469, 'name': 'R1', 'ota': False, 'last': ''}, {'id': 468, 'name': 'W60', 'ota': False, 'last': ''}, {'id': 496, 'name': 'X3 Pro', 'ota': False, 'last': ''}, {'id': 504, 'name': 'G2 S', 'ota': False, 'last': ''}, {'id': 503, 'name': 'W280NB Pro', 'ota': False, 'last': ''}, {'id': 495, 'name': 'K750W', 'ota': False, 'last': ''}, {'id': 494, 'name': 'T30', 'ota': False, 'last': ''}, {'id': 493, 'name': 'NeoBuds Planar', 'ota': True, 'last': '1.0.4'}, {'id': 492, 'name': 'W80', 'ota': True, 'last': ''}, {'id': 449, 'name': 'Comfo C', 'ota': False, 'last': ''}, {'id': 448, 'name': 'X1 Lite', 'ota': False, 'last': ''}, {'id': 450, 'name': 'W800BT SE', 'ota': False, 'last': ''}, {'id': 435, 'name': 'NeoBuds Plus', 'ota': True, 'last': ''}, {'id': 434, 'name': 'H9', 'ota': False, 'last': ''}, {'id': 433, 'name': 'WH700NB Pro', 'ota': False, 'last': ''}, {'id': 432, 'name': 'M60', 'ota': True, 'last': '2.5.1'}, {'id': 431, 'name': 'V80', 'ota': False, 'last': ''}, {'id': 430, 'name': 'MR3', 'ota': True, 'last': '1.0.8'}, {'id': 457, 'name': 'Comfo Flex', 'ota': False, 'last': ''}, {'id': 456, 'name': 'A6', 'ota': False, 'last': ''}, {'id': 451, 'name': 'W200T', 'ota': False, 'last': ''}, {'id': 562, 'name': 'EvoBuds', 'ota': True, 'last': '1.0.2'}, {'id': 561, 'name': 'EvoBuds Pro', 'ota': False, 'last': ''}, {'id': 10010, 'name': 'R990BT', 'ota': True, 'last': '1.0.6'}, {'id': 10009, 'name': 'G5 Max', 'ota': False, 'last': ''}, {'id': 10008, 'name': 'JoyBuds', 'ota': False, 'last': ''}, {'id': 10007, 'name': 'JoyBuds', 'ota': False, 'last': ''}, {'id': 10006, 'name': 'Comfo Bass', 'ota': False, 'last': ''}, {'id': 10005, 'name': 'S355DB', 'ota': True, 'last': '2.1.1'}, {'id': 10003, 'name': 'R2750DB MKⅡ', 'ota': True, 'last': '2.6.1'}, {'id': 10002, 'name': 'M90', 'ota': True, 'last': '2.5.1'}, {'id': 10001, 'name': 'R20BT', 'ota': True, 'last': '1.0.1'}, {'id': 590, 'name': 'P230 USB-C', 'ota': False, 'last': ''}, {'id': 521, 'name': 'MR5', 'ota': True, 'last': '1.0.4'}, {'id': 520, 'name': 'QS20', 'ota': True, 'last': '1.0.1'}, {'id': 519, 'name': 'Comfo Q', 'ota': False, 'last': ''}, {'id': 518, 'name': 'MP330', 'ota': True, 'last': '1.0.2'}, {'id': 507, 'name': 'X2 Plus', 'ota': False, 'last': ''}, {'id': 506, 'name': 'NeoBuds Pro 3', 'ota': True, 'last': ''}, {'id': 548, 'name': 'W820NB Plus', 'ota': False, 'last': ''}, {'id': 547, 'name': 'X5 Pro', 'ota': False, 'last': ''}, {'id': 546, 'name': 'QD25', 'ota': True, 'last': '1.0.1'}, {'id': 545, 'name': 'G1000 II', 'ota': False, 'last': ''}, {'id': 505, 'name': 'WH950NB', 'ota': False, 'last': ''}, {'id': 533, 'name': 'QR65', 'ota': False, 'last': ''}, {'id': 10019, 'name': 'WH880NB', 'ota': True, 'last': ''}, {'id': 10023, 'name': 'Comfo Bass Pro', 'ota': True, 'last': '1.0.2'}, {'id': 10022, 'name': 'Comfo Q2', 'ota': True, 'last': ''}, {'id': 10021, 'name': 'R990BT', 'ota': True, 'last': ''}, {'id': 10020, 'name': 'M60（V26）', 'ota': True, 'last': ''}, {'id': 10011, 'name': 'MR4.5', 'ota': True, 'last': ''}, {'id': 10018, 'name': 'WH950NB Pro', 'ota': True, 'last': ''}, {'id': 10017, 'name': 'X2 Pro', 'ota': False, 'last': ''}, {'id': 10016, 'name': 'MR5', 'ota': True, 'last': ''}, {'id': 10015, 'name': 'R2750DB MKⅡ', 'ota': True, 'last': ''}, {'id': 10014, 'name': 'MR4 MKII', 'ota': True, 'last': ''}, {'id': 10013, 'name': 'MR4.5', 'ota': True, 'last': ''}, {'id': 10012, 'name': 'MR4 MKII', 'ota': True, 'last': '1.0.2'}]                       # id / name / ota / last
UA = "okhttp/4.12.0"


def build_params(product_id, mac, current_version, appver, app, os_code, lang):
    p = {
        "product_id": str(product_id),
        "os": str(os_code),
        "mac": mac,
        "current_version": current_version,
        "app_version": appver,
        "app": str(app),
    }
    if lang:
        p["lang_code"] = lang
    p["timestamp"] = f"{int(time.time()):010d}"
    base = "".join(f"{k}={p[k]}" for k in sorted(p)) + SIGN_SECRET
    p["sign"] = hashlib.md5(base.encode("utf-8")).hexdigest().upper()
    return p, base


def http_json(url, timeout=30, retries=2):
    last = None
    for attempt in range(retries + 1):
        try:
            req = urllib.request.Request(url, headers={"User-Agent": UA, "Accept": "application/json"})
            with urllib.request.urlopen(req, timeout=timeout) as r:
                return json.loads(r.read().decode("utf-8"))
        except Exception as e:                 # noqa: BLE001 - сетевые ошибки разные
            last = e
            if attempt < retries:
                time.sleep(1 + attempt)
    raise last


def safe_name(s):
    s = re.sub(r"[^A-Za-z0-9._-]+", "_", str(s)).strip("_")
    return s or "firmware"


def query(product, args, version):
    params, sign_base = build_params(
        product["id"], args.mac, version, args.appver, args.app, args.os, args.lang
    )
    url = API_URL + "?" + urllib.parse.urlencode(params)
    j = http_json(url, timeout=args.timeout)
    # Сервер отдаёт 429 «请求过于频繁» при пакетных запросах — отступаем.
    for backoff in (3, 6, 12):
        if j.get("code") != 429:
            break
        time.sleep(backoff)
        params, sign_base = build_params(
            product["id"], args.mac, version, args.appver, args.app, args.os, args.lang
        )
        url = API_URL + "?" + urllib.parse.urlencode(params)
        j = http_json(url, timeout=args.timeout)
    data = j.get("data") or {}
    fw_url = data.get("FirmwareLinkUrl") or ""
    return {
        "product_id": product["id"],
        "model": product["name"],
        "requested_version": version,
        "code": j.get("code"),
        "message": j.get("message"),
        "firmware_version": data.get("FirmwareVersionNo") or "",
        "firmware_url": fw_url,
        "request_url": url,
        "sign_base": sign_base,
    }


def download_file(url, path, timeout=180):
    req = urllib.request.Request(url, headers={"User-Agent": UA})
    tmp = path.with_suffix(path.suffix + ".part")
    with urllib.request.urlopen(req, timeout=timeout) as r, tmp.open("wb") as f:
        while True:
            chunk = r.read(1 << 20)
            if not chunk:
                break
            f.write(chunk)
    tmp.replace(path)
    return path.stat().st_size


def process(product, args):
    rows = []
    for version in args.versions:
        try:
            info = query(product, args, version)
        except Exception as e:                 # noqa: BLE001
            rows.append({
                "model": product["name"], "product_id": product["id"],
                "requested_version": version, "error": str(e),
            })
            continue

        if args.delay:
            time.sleep(args.delay)
        if args.dry_run:
            info["action"] = "DRY-RUN"
            rows.append(info)
            continue

        fw_url = info["firmware_url"]
        if not fw_url:
            info["action"] = "NO-FILE"
            rows.append(info)
            continue

        ver = info["firmware_version"] or "unknown"
        digest = hashlib.sha1(fw_url.encode()).hexdigest()[:8]
        name = f"{safe_name(product['name'])}_{safe_name(ver)}_{digest}.bin"
        out = Path(args.out) / name
        if out.exists() and out.stat().st_size > 0:
            info.update(action="SKIP-EXISTS", file=str(out), size=out.stat().st_size)
        else:
            try:
                size = download_file(fw_url, out, timeout=args.timeout)
                sha = hashlib.sha256(out.read_bytes()).hexdigest()
                info.update(action="DOWNLOADED", file=str(out), size=size, sha256=sha)
            except Exception as e:             # noqa: BLE001
                info.update(action="DOWNLOAD-FAILED", error=str(e))
        meta = Path(args.out) / (out.stem + ".json")
        meta.write_text(json.dumps(info, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        rows.append(info)
    return rows


def select_products(args):
    if args.all:
        selected = list(PRODUCTS) if args.include_no_ota else [p for p in PRODUCTS if p["ota"]]
    elif args.id:
        ids = {int(x) for x in args.id}
        selected = [p for p in PRODUCTS if p["id"] in ids]
    elif args.model:
        selected = []
        for needle in args.model:
            hits = [p for p in PRODUCTS if needle.lower() in p["name"].lower()]
            if not hits:
                print(f"! модель не найдена: {needle}", file=sys.stderr)
            selected.extend(hits)
    else:
        args.parser.error("нужно указать --model, --id или --all")
    seen, out = set(), []
    for p in selected:
        key = (p["id"], p["name"])
        if key not in seen:
            seen.add(key)
            out.append(p)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.parser = ap
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--model", action="append", help="название или подстрока, можно повторить")
    g.add_argument("--id", nargs="+", help="id каталога, можно несколько")
    g.add_argument("--all", action="store_true", help="все модели с IsFirmwareUpdate")
    ap.add_argument("--include-no-ota", action="store_true", help="вместе с --all: все 103 модели")
    ap.add_argument("--versions", default="0.0.0", help="current_version через запятую")
    ap.add_argument("--mac", default="C8:24:78:12:34:56")
    ap.add_argument("--appver", default="1.0.32")
    ap.add_argument("--app", type=int, default=13)
    ap.add_argument("--os", type=int, default=1)
    ap.add_argument("--lang", default="")
    ap.add_argument("--out", default="./firmware")
    ap.add_argument("--timeout", type=int, default=60)
    ap.add_argument("--workers", type=int, default=1)
    ap.add_argument("--delay", type=float, default=1.0, help="пауза между запросами, сек")
    ap.add_argument("--dry-run", action="store_true", help="только показать, что нашлось")
    args = ap.parse_args()
    args.versions = [v.strip() for v in args.versions.split(",") if v.strip()]

    products = select_products(args)
    if not products:
        print("нет моделей для обработки", file=sys.stderr)
        return 1

    Path(args.out).mkdir(parents=True, exist_ok=True)
    print(f"Моделей: {len(products)}; версий на модель: {len(args.versions)}; выход: {args.out}")

    all_rows = []
    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as pool:
        futures = {pool.submit(process, p, args): p for p in products}
        for fut in as_completed(futures):
            p = futures[fut]
            try:
                rows = fut.result()
            except Exception as e:                # noqa: BLE001
                rows = [{"model": p["name"], "product_id": p["id"], "error": str(e)}]
            for r in rows:
                action = r.get("action", "?")
                line = f"[{action:16}] {p['name']:24} версия={r.get('requested_version',''):10} " \
                       f"сервер={r.get('firmware_version','-'):10} {r.get('firmware_url','')}"
                if r.get("error"):
                    line += "  ERR=" + r["error"][:120]
                print(line, flush=True)
            all_rows.extend(rows)

    manifest = Path(args.out) / "firmware_manifest.json"
    manifest.write_text(json.dumps(all_rows, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    csv_path = Path(args.out) / "firmware_manifest.csv"
    fields = ["model", "product_id", "requested_version", "code", "firmware_version",
              "firmware_url", "action", "file", "size", "sha256", "error"]
    with csv_path.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fields, extrasaction="ignore")
        w.writeheader()
        for r in all_rows:
            w.writerow(r)

    downloaded = sum(1 for r in all_rows if r.get("action") == "DOWNLOADED")
    skipped = sum(1 for r in all_rows if r.get("action") == "SKIP-EXISTS")
    nofile = sum(1 for r in all_rows if r.get("action") == "NO-FILE")
    print(f"\nИтого: скачано {downloaded}, уже было {skipped}, файла нет {nofile}, всего строк {len(all_rows)}")
    print(f"Манифест: {manifest}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
