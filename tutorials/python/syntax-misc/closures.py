# pylint: skip-file

# closures --> nested func remembers vars from enclosing scope after outer method had been killed


def outer(msg):
    print("LOG: Entered outer function scope")
    def inner():
        print("LOG: Entered inner function")
        print(msg)
        print("LOG: Exiting inner function")
    print("LOG: Exiting outer function scope --> returning inner function")
    return inner

def regular(msg):
    print(msg)

speak = outer("I am Batman")
speak()
outer("Hello") # will not give any output as the return val is not being stored

regular("Hello") # this prints hello as hello is in the lexical scope of the regular func

    


