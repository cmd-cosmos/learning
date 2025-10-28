# pylint: skip-file
# decorators with arguments

def repeat(times):
    def decorator(func):
        def wrapper(*args, **kwargs):
            for _ in range(times):
                func(*args, **kwargs)
        return wrapper
    return decorator
    
@repeat(5)
def greet():
    print("I am Batman")

greet()

# outer function --> receives args for the decorator
# middle function --> receives func being decorated
# inner function --> receives func being decorated

