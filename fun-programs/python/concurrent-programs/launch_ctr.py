#pylint: skip-file
#type: ignore

import threading
import time
import random

abort = False
lock = threading.Lock()

def engine_monitor():
    global abort
    while True:
        time.sleep(0.5)
        temp = random.uniform(200, 1200)
        print(f"[ENGINE] Temp = {temp:.1f} K")

        if temp > 1000:
            with lock:
                abort = True
            print("### ENGINE OVERHEAT ==> ABORT")

            return

