#pylint: skip-file
#type-ignore

import sys
import struct

def to_big_endian(x):
    return struct.pack('>I', x)

def to_little_endian(x):
    return struct.pack('=I', x)

print(sys.byteorder)
print(to_big_endian(1))
print(to_little_endian(1)) # 0000 0000 0000 0000 0000 0000 0000 0001
