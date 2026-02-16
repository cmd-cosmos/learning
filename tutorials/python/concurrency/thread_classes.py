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

# inheritence based worker class
class Worker(Thread):
    def __init__(self, name, delay):
        super().__init__()
        self.name = name
        self.delay = delay
    
    def run(self):
        print(f"{self.name} starting")
        time.sleep(self.delay)
        print(f"{self.name} finished")

class WorkerComposition:
    def __init__(self, name, delay) -> None:
        self.name = name
        self.delay = delay
        self.thread = Thread(target=self.run)
    
    def run(self):
        print(f"{self.name} starting")
        time.sleep(self.delay)
        print(f"{self.name} finished")
    
    def start(self):
        self.thread.start()

    def join(self):
        self.thread.join()

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

    print("\nDone\n\n")

    tc1 = WorkerComposition("composition-thread-1", 5)
    tc2 = WorkerComposition("composition-thread-2", 2)
    tc3 = WorkerComposition("composition-thread-3", 3)

    tc1.start()
    tc2.start()
    tc3.start()
    
    tc1.join()
    tc2.join()
    tc3.join()