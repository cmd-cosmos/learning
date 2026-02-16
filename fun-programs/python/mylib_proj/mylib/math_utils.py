# pylint: skip-file
# math utils module

def add(a ,b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        return ValueError("Divide by 0 error")
    return a / b
