# pylint: skip-file
import time
from threading import Thread

class Batman(Thread):
    def say(self):
        print("sequential func")
        for i in range(5):
            print(i, " I am Batman")

    def run(self) -> None:
        for i in range(5):
            print(i, " I am Batman")
    
class Joker(Thread):
    def say(self):
        print("sequential func")
        for i in range(5):
            print(i, " I am Joker")

    def run(self):
        for i in range(5):
            print(i, " I am Joker")

class Worker(Thread):
    def __init__(self, name, delay):
        super().__init__()
        self.name = name
        self.delay = delay
    
    def run(self):
        print(f"{self.name} starting")
        time.sleep(self.delay)
        print(f"{self.name} finished")

if __name__ == "__main__":
    batman = Batman()
    joker = Joker()

    batman.say()
    joker.say()

    print("\n\nrunning concurrent func\n\n")

    batman.start()
    joker.start()

    batman.join()
    joker.join()

    print("\n\n")

    t1 = Worker("Thread-1", 3)
    t2 = Worker("Thread-2", 2)

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print("\nDone")