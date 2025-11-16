#pylint: skip-file
#type-ignore

# refcount is 1 higher than actual 
# sys.getrefcount() adds a temp ref when passing the obj to the method
# cycles do not use ref counts

import sys

x = []
print(sys.getrefcount(x)) # 2

def foo(x):
    print("func scope: ",sys.getrefcount(x))
foo(x) # 3
print(sys.getrefcount(x)) # 2

y = x
z = [x, y]
print(sys.getrefcount(x)) # 5
