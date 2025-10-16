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

# if (status == 0):
#     print("success")

