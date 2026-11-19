#!/usr/bin/env python3
# Массовый скачиватель прошивок Edifier (только HTTP к облаку).
# Особенности: 429 приходит ВНУТРИ тела при HTTP 200 -> пауза и ретрай.
import hashlib, json, os, re, sys, time, urllib.request, urllib.parse, ssl

SIGN_KEY = "7rn$r44-jM"
CTX = ssl.create_default_context()

def sign_params(params):
    params = dict(params)
    params["timestamp"] = str(int(time.time()))
    s = "".join(f"{k}={params[k]}" for k in sorted(params)) + SIGN_KEY
    params["sign"] = hashlib.md5(s.encode()).hexdigest().upper()
    return params

def http_get(url, timeout=60):
    req = urllib.request.Request(url, headers={"User-Agent": "okhttp/4.9.3"})
    return urllib.request.urlopen(req, timeout=timeout, context=CTX).read()

def ota_query(host, pid):
    params = sign_params({"product_id": str(pid), "os": "1",
                          "mac": "C8:24:78:12:34:56",
                          "current_version": "0.0.0",
                          "app_version": "8.4.50", "app": "13"})
    url = host + "/home/api/v1/ota-upgrade?" + urllib.parse.urlencode(params)
    for attempt in range(10):
        try:
            body = json.loads(http_get(url))
        except urllib.error.HTTPError as e:
            print(f"  HTTP {e.code}, sleep 120", flush=True)
            time.sleep(120)
            continue
        except Exception as e:
            print(f"  net err: {str(e)[:70]}, sleep 30", flush=True)
            time.sleep(30)
            continue
        code = body.get("code")
        if code == 429:
            wait = 45
            print(f"  rate-limited, sleep {wait}s", flush=True)
            time.sleep(wait)
            continue
        return body
    return {"code": "gave_up"}

def sanitize(name):
    name = (name or "unnamed").strip()
    name = re.sub(r'[\\/:*?"<>|\r\n\t]+', "_", name)
    name = re.sub(r"\s+", " ", name)
    return name[:60] or "unnamed"

def download(url, dest):
    # не-ASCII (китайские имена файлов) -> percent-encoding
    url = urllib.parse.quote(url, safe="%/:=&?~#+!$,;'@()*[]|")
    urls = [url]
    if "edifier-provider-oss.edifier.com" in url:
        # фирменный домен из этой сети недоступен (SYN_SENT) -> алиясунг первым
        urls.insert(0, url.replace("edifier-provider-oss.edifier.com",
                                   "edifier-provider.oss-cn-shenzhen.aliyuncs.com"))
    for u in urls:
        for attempt in range(2):
            try:
                data = http_get(u, timeout=45)
                if len(data) > 1000:
                    with open(dest, "wb") as f:
                        f.write(data)
                    return True, len(data), u
                break
            except Exception as e:
                print(f"    dl retry {attempt}: {str(e)[:60]}", flush=True)
                time.sleep(5)
    return False, 0, None

def run(region, host, products_path, out_root):
    prods = json.load(open(products_path, encoding="utf-8"))
    print(f"=== {region}: {len(prods)} products, host={host} ===", flush=True)
    mpath = os.path.join(out_root, "_manifest.json")
    os.makedirs(out_root, exist_ok=True)
    manifest = []
    if os.path.exists(mpath):
        manifest = json.load(open(mpath, encoding="utf-8"))
    # ретраим только ошибки; ok/no_firmware/no_link не трогаем
    manifest = [m for m in manifest if m.get("status") != "error"]
    done = {m["product_id"] for m in manifest}
    for i, p in enumerate(prods, 1):
        pid = p.get("id")
        if pid in done:
            continue
        name = sanitize(p.get("ProductName"))
        model = sanitize(p.get("ProductModel"))
        folder = os.path.join(out_root, f"{pid}_{name}")
        print(f"[{i}/{len(prods)}] {pid} {name}", flush=True)
        resp = ota_query(host, pid)
        entry = {"product_id": pid, "name": name, "model": model,
                 "service_uuid": p.get("ProductServiceUuid"),
                 "last_fw": p.get("LastFirmwareVersion"), "status": None}
        code = resp.get("code")
        data = resp.get("data")
        if code == 200 and isinstance(data, dict) and data.get("FirmwareLinkUrl"):
            link = data["FirmwareLinkUrl"]
            ver = (data.get("FirmwareVersionNo") or "unknown").strip()
            os.makedirs(folder, exist_ok=True)
            dest = os.path.join(folder, f"firmware_{ver}.bin")
            if not os.path.exists(dest):
                ok, size, used = download(link, dest)
                if not ok:
                    entry.update(status="error", url=link, error="download_failed")
                    print("  DOWNLOAD FAILED", flush=True)
                    manifest.append(entry)
                    json.dump(manifest, open(mpath, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
                    continue
            else:
                size = os.path.getsize(dest); used = link
            entry.update(status="ok", version=ver, url=used, size=size, fw_id=data.get("id"))
            with open(os.path.join(folder, "ota_response.json"), "w", encoding="utf-8") as f:
                json.dump(data, f, ensure_ascii=False, indent=1)
            print(f"  OK {ver} {size}B", flush=True)
            time.sleep(1)
        elif code == 200 and isinstance(data, dict) and not data:
            entry.update(status="no_firmware")
            print("  без прошивки", flush=True)
            time.sleep(1)
        elif code == 400:
            entry.update(status="no_firmware", message=(resp.get("message") or "")[:80])
            print("  без прошивки (400)", flush=True)
            time.sleep(1)
        elif code == 200 and isinstance(data, list):
            entry.update(status="no_firmware", message="data=[]")
            print("  пусто (data=[])", flush=True)
            time.sleep(1)
        else:
            entry.update(status="error", response=json.dumps(resp, ensure_ascii=False)[:200])
            print(f"  ошибка code={code}", flush=True)
            time.sleep(30)
        manifest.append(entry)
        json.dump(manifest, open(mpath, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    ok = sum(1 for m in manifest if m.get("status") == "ok")
    print(f"=== {region} ГОТОВО: ok={ok}, записей={len(manifest)} ===", flush=True)

if __name__ == "__main__":
    which = sys.argv[1] if len(sys.argv) > 1 else "all"
    root = r"C:\dev\edifier_firmware_archive\firmwares"
    if which in ("all", "global"):
        run("GLOBAL", "https://foreign-app.edifier.com",
            os.path.join(root, "MR5_1.0.3_1c89dcaf", "source", "products_foreign-app.json"),
            os.path.join(root, "GLOBAL"))
    if which in ("all", "cn"):
        run("CN", "https://admin-app.edifier.com",
            os.path.join(root, "MR5BT_1.0.3_CN", "source", "products_cn.json"),
            os.path.join(root, "CN"))
    print("ALL DONE", flush=True)
