#pylint: skip-file

def odd_check(num):
    return num & 1 == 1

print(odd_check(65))
print(odd_check(117))
print(odd_check(10))

# odd case
# num = 65
#   0100 0001 <--- 65
# & 0000 0001 <--- 1
#  -----------
#   0000 0001 <---- 1 ==> assert(1==1) ==> True --> odd
# 
# num = 117
#   0111 0101 <--- 117
# & 0000 0001 <--- 1
#  -----------
#   0000 0001 <--- 1 ==> assert(1==1) ==> True ==> odd
#          