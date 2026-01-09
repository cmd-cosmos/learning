#pylint: skip-file
#type: ignore

import random
import time
import string

chars = string.ascii_letters + string.digits + "@$#%"

while True:
    line = "".join(random.choice(chars) for _ in range(80))
    print(line)
    time.sleep(0.05)
