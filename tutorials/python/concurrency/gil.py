#pylint: skip-file

# GIL -> a global mutex that ensures only a single thread execs py bytecode at a time

import threading

def cpu_heavy_load():
    x = 0
    for i in range(100_000_000):
        x += i
    print(x, '\n')
    return x


for _ in range(5):
    # start 5 threads to execute the cpu heavy computation
    thread = threading.Thread(target=cpu_heavy_load)
    thread.start()
    print(thread.name, thread.ident)

# GIL ensures 5 different threads but each executes the function serially, the computation is serial and not parallel.
# the threads are all loaded in the dispatch queue and the scheduler switches between threads 