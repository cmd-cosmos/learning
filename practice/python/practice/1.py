# read a specific line from a file

import os

try:
    fileName  = input("File Name: ")
    if not fileName or fileName not in os.curdir:
        raise ValueError("Invalid Input")
except:
    print("using default input file ---> 1-f.txt\n")
    fileName = "1-f.txt"   

try:
    lineNumber = int(input("Line Number: "))
    if not lineNumber:
        raise ValueError("Invalid Input")
except:
    print("using default line ---> fetching line 1\n")
    lineNumber = 1

file = open(fileName, "r")
lines = file.readlines()
file.close()

print("lines found in file: \n", lines, '\n')
# lines list:
# ['1. I am Vengeance\n',
#  '2. I am the Night\n',
#  '3. I am Batman\n',
#  '4. Well I am not']

totalLines = len(lines)
if (lineNumber > totalLines):
    print(f"Exceeded total file lines: read {totalLines} lines, requested for line {lineNumber}")
else:
    print("Found in file: ")
    targetLine = lines[lineNumber - 1].rstrip('\n')
    print(targetLine)
