#pylint: skip-file

# using the @ to decorate --> pie syntax

def multi_intro_decorator(func):
    def func_wrapper(*args, **kwargs):
        print(*args)
        for i in range(*args):
            func(*args, **kwargs)
    return func_wrapper

@multi_intro_decorator
def intro(n):
    print("I am Batman")

intro(5)
