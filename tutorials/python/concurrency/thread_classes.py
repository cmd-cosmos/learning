# pylint: skip-file

class Batman:
    def say(self):
        print("sequential func")
        for i in range(5):
            print(i, " I am Batman")

class Joker:
    def say(self):
        print("sequential func")
        for i in range(5):
            print(i, " I am Joker")

if __name__ == "__main__":
    batman = Batman()
    joker = Joker()

    batman.say()
    joker.say()



