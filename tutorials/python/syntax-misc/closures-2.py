#pylint: skip-file

# each call to the make multiplier function return a new inner function which remembers its own factor
# allows function factories and stateful decorators

def log(msg):
    print(f"LOG: {msg}")

def make_multiplier(factor):
    log("Entered outer func.")
    
    def multiply(x):
        log("Entered inner func.")
        print(x * factor)
        log("Exiting inner func.")
    
    log("Exiting outer func.")
    return multiply


double = make_multiplier(2)
triple = make_multiplier(3)

double(7)
triple(7)

