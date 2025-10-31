# pylint: skip-file

# using xor property to swap vals of 2 vars without using a temp var
# a XOR b XOR b = a

def swap_vals(a, b):
    # new b = a ^ b ^ b <--- original a
    a = a ^ b
    b = a ^ b
    a = a ^ b # a = a ^ b ^ (a ^ b ^ b)
    return a,b

a, b = 1, 99
print(a,b)
print(swap_vals(a,b))

c, d = 12, 54
print(c, d)
print(swap_vals(c, d))


# XOR operation
# a = 1, b = 99
# a = a ^ b 
# 0000 0001 <- a = 1
# 0110 0011 <- b = 99
# ---------
# 0110 0010 <- 98 <---- a = 98

# b = a ^ b
# a = 98, b = 99
# 0110 0010 <- 98
# 0110 0011 <- 99
# ---------
# 0000 0001 <--- b = 1 ### b has got the val of a after the operation (a ^ b) ^ b

# a = a ^  b
# a = 98, b = 1 ****
# 0110 0010 <- a = 98
# 0000 0001 <- b = 1
# ---------
# 0110 0011 <---- a = 99 ### a is now updated to have the original val of b
