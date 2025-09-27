# Vendor friendly implementation to allow for only constructor based obj creation

from typing_extensions import Self


class Singleton:
    _instance = None

    def __new__(cls) -> Self:
        if (cls._instance is None):
            cls._instance = super(Singleton, cls).__new__(cls)
        return cls._instance
    
inst1 = Singleton()
print(inst1)
inst2 = Singleton()
print(inst2)

### Output
# <__main__.Singleton object at 0x000001BB5EAD74D0>
# <__main__.Singleton object at 0x000001BB5EAD74D0>
