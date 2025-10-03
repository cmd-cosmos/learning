# read a specific line from a file

fileName  = input("File Name: ")
lineNumber = input("Line Number: ")
lineNumber = int(lineNumber)

file = open(fileName, "r")
lines = file.readlines()
file.close()

print(lines)
# lines list:
# ['1. I am Vengeance\n',
#  '2. I am the Night\n',
#  '3. I am Batman\n',
#  '4. Well I am not']

targetLine = lines[lineNumber - 1]

print(targetLine)
