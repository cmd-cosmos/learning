#pylint: skip-file
import sys

# string interning --> also called string pooling
#                  --> resuse identical immutable strings in mem to optimize mem alloc

a = "Batman"
b = "Batman"

# both a and b have the same val
# internally interned --> both a and b point to the same mem address


print(f"id of a = {id(a)}")
print(f"id of b = {id(b)}")

print("a is b ===> ",a is b) # compares object id
print("a == b ==> ",a == b) # compares object vals 


c = "".join(["Bat", "man"])
print(a is c) # false ---> join operation happens at runtime so objs mapped separately
print(a == c) # true ---> val of both objects is the same
print("-"*10)
d = "Bat" + "man"
# string literal concat happens at compile time so objects can be interned
print(a is d) # true
print(a == d) # true 

# string variable concat happens at runtime so interning not performed
print("-"*10)
e = "Bat"
f = e + "man"
print(a is f)
print(a == f)

# manual string interning
print("-"*10)

x = "".join(["Bat", "man"])
y = "".join(["Bat", "man"]) 

print(x is y) # false as string joined at runtime

x = sys.intern(x)
y = sys.intern(y)

print(x is y) # forcing interning
