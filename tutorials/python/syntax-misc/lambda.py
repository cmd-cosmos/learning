#pylint: skip-file

# lambdas --> small, nameless and anonymous function
# lambda args: expression
# shortcut for writing small functions inline 

# import functools

# basic use of lambdas
add = lambda x, y: x + y
print(f"{add.__name__} : {add(1,2)}")

# using lambdas as args to map(), filter() or sorted()
nums = [1,2,3,4,5]
squares = list(map(lambda x: x**2, nums))
print(f"squares: {squares}")

# filter based on conditions
lst = [1,2,3,4,5,6,7,8,9,10]
evens = list(filter(lambda x: (x % 2 == 0), lst))
print(f"evens : {evens}")

