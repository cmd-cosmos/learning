# purpose:
# git status
# git add
# git commit
# all in 1

# type: ignore
# pylint ignores ---> ignore globals whitespace in multiline function calls
# pylint: disable=global-statement
# pylint: disable=C0303

import time
import os
import sys
import subprocess

# init global vars to none
STATUS = None
CHANGES_FLAG = None

if len(sys.argv) > 1:
    target_path = sys.argv[1]
    print(f"target set: {target_path}")
    os.chdir(target_path)
else:
    print("no target dir passed, using program home dir...\n")

print("-"*30, "Auto Git", "-"*30, '\n')

CHANGES_FLAG = False

def validate_and_status_check():
    '''
    validation sequence to ensure git repo exists before checking for repo status.
    '''
    check = os.system("git rev-parse --git-dir")
    print("git repo check returned: ",check)

    if check == 0:
        print(".git directory confirmed, proceeding with auto commit sequence.\n")
        print("-"*70)
    else:
        print("not a git directory")
        print("-"*70)

    time.sleep(2)
    global STATUS #ignore : warning
    STATUS = os.system("git status")
    print("-"*70)
    print("\nstatus check return val: ", STATUS)

    change_check = subprocess.run(["git", "status", "--porcelain"],
                                  capture_output=True, text=True, check=False)
    
    print("Changed files: \n", change_check.stdout)

    if bool(change_check.stdout.strip()) is True:
        time.sleep(1)
        print("changes found.")
        print("proceeding with the auto track sequence.\n")
        global CHANGES_FLAG
        CHANGES_FLAG = not CHANGES_FLAG
    else:
        time.sleep(1)
        print("no changes found.\nexiting sequence...")
        time.sleep(1)
        sys.exit()

validate_and_status_check()
print("-"*70)
print(f"validation and status bit: {CHANGES_FLAG}") 
print("-"*70)

MODE = 1 # 0 = debug mode, 1 = run mode
if MODE and CHANGES_FLAG:
    PROCEED = False

    def check_remote_and_push():
        '''
        check if remote exists and push if remote found
        '''

        print("\nchecking if remote exists for the current git repo.")
        time.sleep(1)
        remote_check = os.system("git remote -v")
        print("remote check: ", remote_check)
        if remote_check == 0:
            print("remote found...")
            print("pushing to remote...\n")
            time.sleep(1)
            os.system("git push")
            time.sleep(1)
            print("-"*70)
            print("\ngetting branch status...")
            time.sleep(1)
            os.system("git status")
            time.sleep(1)
            print("-"*70)

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
            sys.exit()

    def commit():
        '''
        proceed with git commit sequence after git add returns and user passes custom message 
        otherwise goes with the default version
        '''
        os.system("git add --all")
        inp_flag = input("add custom message for the commit[y/n]: ").lower().strip()

        if inp_flag == 'y':
            msg_string = input("enter custom message: ").strip()
        else:
            msg_string = "auto commit --> default message"

        print()
        os.system(f'git commit -m "{msg_string}"')
        print("-"*70)
        push_conf = input("ready to push changes[y/n]: ").lower().strip()
        if push_conf == "y":
            check_remote_and_push()
        else:
            print("\nexiting without pushing.")
            time.sleep(1)
            sys.exit()

    if STATUS == 0:
        print("status check successful --> proceeding with git add --all")
        print(f"cwd: {os.getcwd()}")
        print("\nconfirm add permission to stage all modified files in the cwd.")
        inp = input("confirm git add --all [y/n]: ")
        if inp == 'y':
            PROCEED = True
            print("\nproceeding to auto commit sequence...")
            commit()
        else:
            PROCEED = False
            print("exiting seq.")
            sys.exit()
    else:
        print("failure --> exiting")
        sys.exit()
