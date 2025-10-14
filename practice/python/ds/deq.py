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

### queue behavior of the deque class


