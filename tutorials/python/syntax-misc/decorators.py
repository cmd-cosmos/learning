#pylint: skip-file

import time

def timer_decor(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        res = func(*args, **kwargs)
        end = time.time()
        print(f"func: {__name__} - time elapsed: {(end-start):.4f}s")
        return res
    return wrapper

@timer_decor
def sleeper_func():
    time.sleep(2)
    print("I am slow.")

sleeper_func()

