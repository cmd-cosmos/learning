#pylint: skip-file

# check if num is power of 2
# use property --> a power of 2 has only 1 bit set as binary reps are power of 2

def power_of_2(num):
    return num > 0 and (num & (num - 1)) == 0

print(power_of_2(2))
print(power_of_2(128))
print(power_of_2(64))
print(power_of_2(20))
print(power_of_2(12))

# workings 
# num = 128
# 128 & (128 - 1) ?== 0
# 128 & 127 ?== 0
# 1000 0000 <--- 128
# 0111 1111 <--- 127
# ---------
# 0000 0000 <--- 0
# 0 == 0 <------ TRUE, so 128 is a power of 2
