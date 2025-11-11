# pylint: skip-file
# type-ignore

# locals --> is live and reflects current state of local namespace
# var names are refs or bindinfs to objs stored on memory
# var names are keys to object pointers in the namespace dict --> x maps to a ref ptr to int obj in case of x = 10

x = 10
y = 100
z = 10
for key, vals in locals().copy().items():
    print(key, ' : ', vals)

check = locals()['x']
print(check) # prints 10 

