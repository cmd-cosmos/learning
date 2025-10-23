# hasing in dict keys
#pylint: skip-file

d = {"name" : "batman",
     "age"  : 22}

print(hash("batman")) # long hash computed
print(hash(22))       # int hash to same int
print(hash(34))       # int hash to same int 
print(hash(34.0))     # same hash as int
print(hash(3.14156))  # long hash computed
print(hash(-123))     # same hash as input

# Outputs:
# -6344129055824560244
# 22
# 34
# 34
# 326415136384290819
# -123