#pylint: skip-file

def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mult(a, b):
    return a * b

def divide(a,b):
    if b == 0:
        raise ZeroDivisionError("Cannot divide by 0")
    return a / b
