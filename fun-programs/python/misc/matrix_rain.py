#pylint: skip-file

import random
import time
import string
from colorama import Fore, Style, init
import os

init()

chars = [string.ascii_letters, string.digits,  "$", "#", "@", "%"]
print(chars)

rows = 25
cols = 80
while(True):
    os.system("cls")
    for i in range(rows):
        for j in range(cols):
            print(random.randint(5, 20)*" " + chars[0][random.randint(1, len(chars[0]) - 1)] + random.randint(10, 20)*" " + chars[1][random.randint(1, len(chars[1]) - 1)] + random.randint(10, 20)*" " + random.choice(chars[2:]))
        time.sleep(2.5)

