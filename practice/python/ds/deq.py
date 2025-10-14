from collections import deque


### stack behavior of the deque class
stack = deque()
stack.append(1)
stack.append(2)
stack.append(3)
stack.append(4)
print(*stack) # unpack the stack

# regular pop --> removes from the right
stack.pop() 
print(*stack)

# Output ---> LIFO followed here
# 1 2 3 4
# 1 2 3
print('-' * 50)
### queue behavior of the deque class
# Enqueuing operation
queue = deque()
queue.append(1)
queue.append(2)
queue.append(3)
queue.append(4)

print(*queue)
# Output --->  appending normally
# 1 2 3 4

# Dequeuing operation ---> FIFO
queue.popleft()
queue.popleft()

print(*queue)

print('-' * 50)

q2 = deque()
q2.append(12)
q2.append(108)
q2.append(42)
q2.append(78)
q2.append(64)
q2.append(1000)
print("intitialized queue: ", *q2)
print("length before emptying: ", q2.__len__())

while q2.__len__() !=0:
    print("popped          -->", q2.popleft())
    print("modified queue  -->", *q2)

print("length after emptying: ", q2.__len__())