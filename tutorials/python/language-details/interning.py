#pylint: skip-file

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