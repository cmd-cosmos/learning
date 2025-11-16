#pylint: skip-file
#type: ignore

import sys

class A:
    __slots__ = ("x", "y")

class B:
    pass

a = A()
a.x = 10
a.y = 20

print(a.__slots__) # avoids attribure dict alloc
print(sys.getsizeof(a))           # 48 bytes
print(sys.getsizeof(a.__slots__)) # 56 bytes

b = B()
b.x = 200
b.y = 300

print(b.__dict__) # attribute dict
print(sys.getsizeof(b))          # 48 bytes
print(sys.getsizeof(b.__dict__)) # 296 bytes
