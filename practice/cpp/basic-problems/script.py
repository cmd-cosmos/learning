# pylint: skip-file
# type-ignore

import os
import shutil

cwd = os.getcwd()
target = "bin"
os.makedirs(target, exist_ok=True)

cpp_lst = []

for item in os.listdir(cwd):
    print(item)
    if item.endswith(".exe"):
        cpp_lst.append(item)
        shutil.move(item, os.path.join(target, item))

print("Moved: ", cpp_lst)
