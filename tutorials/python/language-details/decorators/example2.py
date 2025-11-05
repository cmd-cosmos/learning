#pylint: skip-file

import functools

def log_calls(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Calling: {func.__name__} --> args = {args}, kwargs = {kwargs}")
        res = func(*args, **kwargs)
        print(f"{func.__name__} returned --> {res}")
        return res
    return wrapper

@log_calls
def add(a,b):
    return a + b

print('sum = ',add(1,b=2))
print(add.__name__) # without the functools wrap decorator -> the wrapped function is replaced by the wrapper function in the log calls decorator
