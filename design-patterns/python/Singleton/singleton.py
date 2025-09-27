class Singleton:
    _instance = None

    @staticmethod
    def getInstance():
        if Singleton._instance == None:
            Singleton()
        return Singleton._instance
    
    def __init__(self) -> None:
        if Singleton._instance is not None:
            raise Exception("Singleton Exists ---> call getInstance()")
        else:
            Singleton._instance = self
            print("Singleton Instance Created")

inst1 = Singleton()
print(inst1)
inst2 = Singleton.getInstance()
print(inst2)

### Output:
# Singleton Instance Created
# <__main__.Singleton object at 0x0000027742A37380>
# <__main__.Singleton object at 0x0000027742A37380>

