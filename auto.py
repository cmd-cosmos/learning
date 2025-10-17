# purpose:
# git status
# git add
# git commit
# all in 1

import time
import os
import sys
import subprocess

if len(sys.argv) > 1:
    target_path = sys.argv[1]
    print(f"target set: {target_path}")
    os.chdir(target_path)
else:
    print("no target dir passed, using program home dir...\n")

print("-"*30, "Auto Git", "-"*30, '\n')

changes_flag = False

def validate_and_status_check():
    check = os.system("git rev-parse --git-dir")
    print("git repo check returned: ",check)

    if check == 0:
        print(".git directory confirmed, proceeding with auto commit sequence.\n")
        print("-"*70)
    else:
        print("not a git directory")
        print("-"*70)

    time.sleep(2)
    global status
    status = os.system("git status")
    print("-"*70)
    print("\nstatus check return val: ", status)

    change_check = subprocess.run(["git", "status", "--porcelain"], capture_output=True, text=True)
    print("Changed files: \n", change_check.stdout)

    if bool(change_check.stdout.strip()) == True:
        time.sleep(1)
        print("changes found.")
        print("proceeding with the auto track sequence.\n")
        global changes_flag
        changes_flag = not changes_flag
    else:
        time.sleep(1)
        print("no changes found.\nexiting sequence...")
        time.sleep(1)
        exit()

validate_and_status_check()
print("-"*70)
print(f"validation and status bit: {changes_flag}") 
print("-"*70)

mode = 1 # 0 = debug mode, 1 = run mode
if mode and changes_flag:
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
