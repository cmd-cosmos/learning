#pylint: skip-file
#type-ignore

import ctypes

class Point(ctypes.Structure):
    _fields_ = [
        ("x", ctypes.c_int32),
        ("y", ctypes.c_int32)
    ]

def raw_mem(obj):
    addr = ctypes.addressof(obj)
    size = ctypes.sizeof(obj)
    buf  = (ctypes.c_ubyte * size).from_address(addr)
    return [f"{b:02x}" for b in buf] 

p = Point(10, 20)

print(raw_mem(p))
