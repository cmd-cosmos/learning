# pylint: skip-file

from mylib import math_utils, string_utils

result  = math_utils.add(12, 34)
result2 = math_utils.subtract(12, 34)
result3 = math_utils.multiply(12, 34)
result4 = math_utils.divide(12, 34)
result5 = math_utils.divide(12, 0)

print(result, '\n', result2, '\n', result3, '\n', result4, '\n', result5)

string  = string_utils.to_lowercase("BATMAN")
string2 = string_utils.to_uppercase("BATMAN")
string3 = string_utils.count_vowels("BATMAN")

print(string, string2, string3)