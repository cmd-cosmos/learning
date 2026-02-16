# pylint: skip-file
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

if __name__ == "__main__":
    batman = Batman()
    joker = Joker()

    batman.say()
    joker.say()

    print("\n\nrunning concurrent func\n\n")

    batman.start()
    joker.start()

    # batman.join()
    # joker.join()