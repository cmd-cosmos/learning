#pylint: skip-file

def uppercase(func):
    def wrapper(*args, **kwargs):
        print("Entering decorator funciton...")
        temp = func(*args, **kwargs)
        res = temp.upper()
        return res
    return wrapper


@uppercase
def greet(name):
    return f"Hello, {name}"

inp = input("Enter Name: ")
print(greet(inp))

