### Valid Anagram ---> check if 2 strings are anagrams
# anagrams ---> same characters with same frequencies
# eg) danger ---> garden is an anagram

from collections import Counter

str1 = str(input("Enter str 1: ")).lower()
str2 = str(input("Enter str 2: ")).lower()

def check_anagram(str1, str2) -> bool:
    if len(str1) == len(str2) != 0:
        flag = True if Counter(str1) == Counter(str2) else False
    else:
        flag = False
    return flag

result = check_anagram(str1=str1, str2=str2)
print(result)

'''
manual frequency counter like a hash table
'''

print("-"*20 + "Maunual Solution" + "-"*20)

f1 = {}
f2 = {}

if len(str1) != len(str2):
    print(False)
else:
    for character in str1:
        if character in f1:
            f1[character] += 1
        else:
            f1[character] = 1
    
    for character in str2:
        if character in f2:
            f2[character] += 1
        else:
            f2[character] = 1
    
    for key in f1:
        if key not in f2 or f1[key] != f2[key]:
            flag = False
        else:
            flag = True
    
    if flag == True:
        print("Anagram")
    else:
        print(print("Not Anagram"))
    


