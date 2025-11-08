#pylint: skip-file

def uppercase(func):
    def wrapper(*args, **kwargs):
        print("Entering uppercase decor...")
        temp = func(*args, **kwargs)
        res = temp.upper()
        return res
    return wrapper

def splitter_decor(func):
    def wrapper(*args, **kwargs):
        print("Entering splitter wrapper...")
        temp = func(*args, **kwargs)
        res = temp.split(',')
        return res
    return wrapper

# this order will give an error as uppercase decor will wrap the splitter decor so we will first get a list which it will try to capitalize.
# @uppercase
# @splitter_decor

@splitter_decor     # split the capitalized string
@uppercase          # capitalize first
def greet(name):
    return f"Hello, {name}"

inp = input("Enter Name: ")
print(greet(inp))

