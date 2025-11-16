#pylint: skip-file
#type: ignore

import sys

x: int = 21
y: str = "batman"
z: float = 0.001
l: bool = True
m: list = []
n: tuple = ()
o: set = set()
p: dict = {}

lt = [x,y,z,l,m,n,o,p]

for item in lt:
    print(f"{type(item)} => {sys.getsizeof(item)} bytes")

