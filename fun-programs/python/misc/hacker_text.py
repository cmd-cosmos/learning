#pylint: skip-file
#type: ignore

import random
import time
import string

chars = string.ascii_letters + string.digits + "@$#%"
line_count = 0
while line_count < 100:
    line = "".join(random.choice(chars) for _ in range(80))
    print(line)
    line_count += 1
    time.sleep(0.05)
