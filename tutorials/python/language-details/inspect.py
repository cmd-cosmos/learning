### seeing Cpython slot assignment done during compilation

#pylint: disable=C0114
#pylint: disable=C0116
#pylint: disable=C0303
#pylint: disable=C0413
#pylint: disable=C0304
#pylint: disable=W0105

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
 10           RESUME                   0

 11           LOAD_CONST               1 (10)
              STORE_FAST               0 (x)

 12           LOAD_FAST                0 (x)
              RETURN_VALUE

'''