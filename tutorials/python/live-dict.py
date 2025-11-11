#pylint: skip-file
#type-ignore

# LEGB - scope resolution

def foo():
    x = 10
    y = 1
    print(locals())
    locals()['y'] = 1000 # trying to modify val assigned to y
    print(locals()['y']) # y is still 1 as locals is a snapshot of curr locals
    print(y)
    exec("y = 200")
    print(y)
    

foo()

print()
for k,v in locals().copy().items():
    print(f"{k} : {v}")

print()
for k,v in globals().copy().items():
    print(f"{k} : {v}")

print()
print(locals() == globals())

z = 100
y = 1000
print()
print(locals() == globals())


# inside a function, locals() returns a snapshot of the function’s local variables
# modifying this dict does not change the actual variables in the function.
# at the module (global) level, locals() and globals() point to the same live dict
# modifying locals() here changes real global variables.
# iterating over locals() at global scope can cause runtime error
# because loop variables are added to the namespace while iterating
# soln: iterate over locals().copy()
# vars inside a function are stored in a fast internal array (not a dict)
# locals() constructs a dict copy from this array for access.
# using exec() or eval() inside a func can sync locals() dict with actual local vars
# allows dynamic code to modify the real locals.
# after a function exits, its local variables disappear
# globals() / module-level locals() remain unaffected.
# locals() == globals() is true at the module level
# they reference the same live dictionary
