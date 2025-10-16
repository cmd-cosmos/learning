# purpose:
# git status
# git add
# git commit
# all in 1

import time
import os

print("-"*10, "Auto Git", "-"*10, '\n')

check = os.system("git rev-parse --git-dir")
print("git repo check: ",check)

if check == 0:
    print(".git directory confirmed, proceeding with auto commit sequence.")
else:
    print("not a git directory")

time.sleep(2)

status = os.system("git status")
print("\n\nstatus check: ", status)

proceed = False

def commit():
    os.system("git add --all")
    os.system("git commit -m \"auto commit default message\"")

if status == 0:
    print("status check successful --> proceeding with git add --all")
    print(f"cwd: {os.getcwd()}")
    print("confirm add permission to stage all modified files in the cwd.")
    inp = input("confirm git add --all [y/n]: ")
    if (inp == 'y'):
        proceed = True
        print("proceeding to auto commit sequence.")
        commit()
    else:
        proceed = False
        print("exiting seq.")
        exit()
else:
    print("failure --> exiting")
    exit()
