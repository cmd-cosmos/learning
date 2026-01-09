#pylint: skip-file
#type: ignore

import random
import time
import string
from colorama import Fore, Style, init

init()

chars = string.ascii_letters + string.digits + "@$#%"
line_count = 0
while line_count < 100:
    line = "".join(random.choice(chars) for _ in range(80))
    print(Fore.GREEN + line + Style.RESET_ALL)
    line_count += 1
    time.sleep(0.05)
