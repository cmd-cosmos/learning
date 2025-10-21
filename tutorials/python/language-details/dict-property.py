# dictionary keys
# pylint: skip-file

d = {
    1   : "Batman",
    1.0 : "Alfred"
}

# 1 and 1.0 treated the same despite being different types as they equate to the same int value
print(f"d[1]   = {d[1]}")
print(f"d[1.0] = {d[1.0]}")

# Output:
# d[1]   = Alfred
# d[1.0] = Alfred


print(d)
# {1: 'Alfred'}

