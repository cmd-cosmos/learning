#pylint: skip-file
#type: ignore

class A:
    x = "A.x from parent class A"

class B(A):
    '''Empty class inherits from A'''
    pass

b = B()
print(b.x) # prints from class A
# Due to attribute lookup process ---> look in B.__dict__ first and then in A.__dict__ if not found


