# dictionary keys
# pylint: skip-file

d = {
    1   : "Batman",
    1.0 : "Alfred"
}

# 1 and 1.0 treated the same despite being different types as they equate to the same int value
print(d)
print(f"d[1]   = {d[1]}")
print(f"d[1.0] = {d[1.0]}")
# Output:
# {1: 'Alfred'}
# d[1]   = Alfred
# d[1.0] = Alfred
print("-"*30)
# different float vals act as separate keys
d2 = {
    1 : "Batman",
    1.23 : "Alfred"
}
print(d2)
print(f"d2[1]   = {d2[1]}")
print(f"d2[1.23] = {d2[1.23]}")


