#pylint: skip-file

l1 = [1,2,3]
print("l1: ", id(l1))

#shallow copies --> same id, same list, same element

l2 = l1
print("l2: ", id(l2))

# not a deep copy
# shallow copy ---> new list, shared elements
l3 = l1.copy()
print("l3: ", id(l3))

l3.append(6)
print(l1) # [1, 2, 3]
print(l3) # [1, 2, 3, 6]

l4 = [[1,2,3], [1,2,3,4,5]]
l5 = l4.copy()
print(l4)
print(l5)

l5[0].append(2000)
print(l4)
print(l5)

# output --> the shallow nature of .copy is now visible --> both lists are affected when i modify at an index of the list that copied from the initial list.
# [[1, 2, 3], [1, 2, 3, 4, 5]]
# [[1, 2, 3], [1, 2, 3, 4, 5]]
# [[1, 2, 3, 2000], [1, 2, 3, 4, 5]]
# [[1, 2, 3, 2000], [1, 2, 3, 4, 5]]

