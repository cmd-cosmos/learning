#pylint: skip-file
#type: ignore

class A:
    x: list = []

class B(A):
    pass

a = A()
b = B()

a.x.append(1)

print(a.x, b.x)
print(a.x is b.x) # true

# x lives on the class object and not the instance
