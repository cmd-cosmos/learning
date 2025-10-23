# Understanding minute details pertaining to datatypes
# pylint: skip-file

def demarcate():
    print("-"*50)
    

# ints are unbounded - arbitrary precision
a: int = 9999999999999999999 # no overflow 
print(a+1)
demarcate()
# usually small integers are cached ---> (typical range in C python: -5 to 256)
a = 123
b = 123
print(a is b)
c = 2000
d = 2000
print(c is d)

# small int caching not visible --> maybe due to single pylong object being created by the compiler ---> so both c and d point to that.
def foo(): return 10000
def bar(): return 10000
print(foo() == bar())
print(foo() is bar())

demarcate()

# bool is an instance of int
var = bool() # instantiate a bool object
print(isinstance(var, int))
print(isinstance(False, int))
print(isinstance(True, int))
demarcate()

# floats ---> implemented as C doubles
print(0.1 + 0.2 == 0.3) # floating point imprecision
demarcate()

# string literals --> concatenated at compile time
# methods like replace() or upper() returns new string objects and never modify in place
s = "I"" am"" Batman"
print(s)