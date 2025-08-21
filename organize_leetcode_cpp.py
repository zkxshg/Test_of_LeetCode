# organize_leetcode_cpp.py
import argparse, glob, os, re, shutil, hashlib

def bucket_from_id(x: int) -> str:
    lo = (x // 1000) * 1000
    hi = lo + 1000
    return f"{lo}-{hi}"

def extract_id_from_filename(name: str):
    m = re.match(r"^(\d+)_", name)
    return int(m.group(1)) if m else None

def extract_id_from_file(path: str):
    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as f:
            head = f.read(4096)
        m = re.search(r"^\s*//\s*(\d+)\.", head, flags=re.M)
        return int(m.group(1)) if m else None
    except Exception:
        return None

def file_sha(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()

def main(apply: bool):
    root = os.getcwd()
    # 只处理根目录下的 .cpp（不进入子文件夹）
    files = [f for f in glob.glob("*.cpp") if os.path.isfile(f)]
    if not files:
        print("No root-level .cpp files found.")
        return

    moves = []
    for f in sorted(files):
        fid = extract_id_from_filename(f) or extract_id_from_file(f)
        if fid is None:
            print(f"[SKIP] 无法解析题号: {f}")
            continue
        dest_dir = bucket_from_id(fid)
        os.makedirs(dest_dir, exist_ok=True)
        dest = os.path.join(dest_dir, f)

        if os.path.exists(dest):
            # 重复文件处理：内容相同则删除源，不同则改名避免覆盖
            if file_sha(f) == file_sha(dest):
                moves.append(("delete", f, dest))
            else:
                base, ext = os.path.splitext(f)
                alt = os.path.join(dest_dir, base + "_dup" + ext)
                i = 1
                while os.path.exists(alt):
                    alt = os.path.join(dest_dir, f"{base}_dup{i}{ext}")
                    i += 1
                moves.append(("move", f, alt))
        else:
            moves.append(("move", f, dest))

    if not moves:
        print("Nothing to do.")
        return

    print("Plan:")
    for kind, src, dst in moves:
        if kind == "move":
            print(f"  MOVE   {src}  →  {dst}")
        else:
            print(f"  DELETE {src}  (duplicate of {dst})")

    if not apply:
        print("\nDry-run only. Use:  python organize_leetcode_cpp.py --apply")
        return

    for kind, src, dst in moves:
        if kind == "move":
            shutil.move(src, dst)
        else:
            os.remove(src)

    print("\nDone. Now you can:")
    print("  git add -A && git commit -m \"chore: organize cpp files into buckets\" && git push")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--apply", action="store_true", help="actually move files")
    main(parser.parse_args().apply)
