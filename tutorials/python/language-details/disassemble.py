#pylint: skip-file
#type: ignore

import dis

def f(a,b):
    return a + b

dis.dis(f)

def foo(x):
    y = x**2
    return f(y, 100)

dis.dis(foo)

