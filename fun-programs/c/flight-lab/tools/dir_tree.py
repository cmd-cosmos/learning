#pylint: skip-file

import os
from pathlib import Path

IGNORE = {
    ".git",
    "__pycache__",
    ".vscode",
    ".idea",
    "build",
    "bin",
    "obj"
}

def print_tree(dir, prefix=""):
    path = Path(dir)
    entries = sorted(
    [
        item for item in path.iterdir()
        if item.name not in IGNORE
    ],
    key=lambda x: (
        0 if x.name == "Makefile" else 1 if x.is_dir() else 2,
        x.name.lower()
        )
    )
    for index, entry in enumerate(entries):
        is_last = index == len(entries) - 1
        connector = "└── " if is_last else "├── "
        print(prefix + connector + entry.name)
        if entry.is_dir():
            extension = "    " if is_last else "│   "
            print_tree(
                entry,
                prefix + extension
            )

def main():
    curr_dir = Path.cwd()
    print(f"{curr_dir.name}/")
    print_tree(curr_dir)
    
if __name__ == "__main__":
    main()
