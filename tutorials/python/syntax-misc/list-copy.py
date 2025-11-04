#pylint: skip-file

l1 = [1,2,3]
print("l1: ", id(l1))

#shallow copies --> same id

l2 = l1
print("l2: ", id(l2))

# deep copies ---> different obj ids
l3 = l1.copy()
print("l3: ", id(l3))

