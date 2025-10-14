from collections import deque


# stack behavior of the deque class
queue = deque()
queue.append(1)
queue.append(2)
queue.append(3)
queue.append(4)
print(*queue) # unpack the queue

# regular pop --> removes from the right
queue.pop() 
print(*queue)

# Output ---> LIFO followed here
# 1 2 3 4
# 1 2 3


