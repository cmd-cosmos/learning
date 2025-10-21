# pylint: skip-file
# small string optimization
# store small string data into string object instead of the heap
# SSO is not guranteed all the time
# does not work with large strings

import sys

a = "batman"*5000
b = "batman"*5000

print(f"id of a : {id(a)}\nlen(a) = {len(a)}")
print(f"id of b : {id(b)}\nlen(b) = {len(b)}")
print("a is b ===> ",a is b) # since the string is too large interning is disabled

print()

c = "batman"*50
d = "batman"*50

print(f"id of c : {id(c)}\nlen(c) = {len(c)}")
print(f"id of d : {id(d)}\nlen(d) = {len(d)}")
print("c is d ===> ",c is d)



