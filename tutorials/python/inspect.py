### seeing Cpython slot assignment done during "compilation"

def f():
    x = 10
    return x

print(f.__code__.co_varnames)   
print(f.__code__.co_consts)    

import dis
dis.dis(f)

'''
Output:

('x',)
(None, 10)
  3           RESUME                   0

  4           LOAD_CONST               1 (10)
              STORE_FAST               0 (x)

  5           LOAD_FAST                0 (x)

'''