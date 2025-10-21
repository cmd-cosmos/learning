# pylint: skip-file
# small string optimization
# store small string data into string object instead of the heap
# SSO is not guranteed all the time
# does not work with large strings

import sys
import ctypes

a = "batman"*5000
b = "batman"*5000

print(sys.getsizeof(a), "bytes for a,", sys.getsizeof(b), "bytes for b")
print(f"id of a : {id(a)}\nlen(a) = {len(a)}")
print(f"id of b : {id(b)}\nlen(b) = {len(b)}")
print("a is b ===> ",a is b) # since the string is too large interning is disabled

print()

c = "batman"*50
d = "batman"*50
print(sys.getsizeof(c), "bytes for c,", sys.getsizeof(d), "bytes for d")
print(f"id of c : {id(c)}\nlen(c) = {len(c)}")
print(f"id of d : {id(d)}\nlen(d) = {len(d)}")
print("c is d ===> ",c is d) # string interning works here


### short vs long string mem view
s_str = "hello"
l_str = "Hello this is a longer string"*1000

print()
# getsizeof returns byte val
print(f"short_str size: {sys.getsizeof(s_str)} bytes")
print(f"long_str size:  {sys.getsizeof(l_str)} bytes")


# raw mem view of strings 

test = "i am batman"
ptr = id(test)

# look at the first 32 bytes of data
buffer = (ctypes.c_char * 32).from_address(ptr)
# print the first 32 bytes of the mem dump 
print(bytes(buffer))

view = memoryview(test.encode())
print(view.tobytes())


