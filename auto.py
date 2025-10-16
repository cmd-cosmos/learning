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

def check_remote_and_push():
    print("checking if remote exists for the current git repo.")
    time.sleep(1)
    remote_check = os.system("git remote -v")
    print("remote check: ", remote_check)
    if remote_check == 0:
        print("remote found...")
        print("pushing to remote...\n")
        time.sleep(1)
        os.system("git push")
        time.sleep(1)
        print("\ngetting branch status...")
        time.sleep(1)
        os.system("git status")
        time.sleep(1)
        clean_flag = input("would you like to clear screen[y/n]: ").lower().strip()
        if clean_flag == 'y':
            print("clearing screen...")
            time.sleep(1)
            os.system("cls")
        else:
            print("\nsequence complete...")
    else:
        print("no remote found...")
        print("exiting sequence without pushing to remote....")
        time.sleep(1)
        exit()

def commit():
    os.system("git add --all")
    inp_flag = input("add custom message for the commit[y/n]: ").lower().strip()

    if inp_flag == 'y':
        msg_string = input("enter custom message: ").strip()
    else:
        msg_string = "auto commit --> default message"
    
    os.system(f'git commit -m "{msg_string}"')
    push_conf = input("ready to push changes[y/n]: ").lower().strip()
    if push_conf == "y":
        check_remote_and_push()
    else:
        print("\nexiting without pushing.")
        time.sleep(1)
        exit()

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
