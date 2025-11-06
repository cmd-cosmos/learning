#pylint: disable=C0114
#pylint: disable=C0116
#pylint: disable=C0121
#pylint: disable=C0301
#pylint: disable=C0305

# 1. apply a 10% tax and round the res
salaries = [45000, 52000, 61000, 73000]
taxed_salaries = list(map(lambda x: round(x - x*0.1), salaries))
print(f"taxed salaries: {taxed_salaries}")

# 2. filter active users
users = [
    {"name" : "batman", "active" : True},
    {"name" : "alfred", "active" : True},
    {"name" : "joker", "active" : False},
    {"name" : "riddler", "active" : False},
    {"name" : "scarecrow", "active" : True},
]
active_users = list(filter(lambda x: x["active"] == True, users))
print(active_users)

# 3. sort by custom condition -> sort by descending power
characters = [
    {"name" : "batman", "power" : 100},
    {"name" : "alfred", "power" : 95},
    {"name" : "riddler", "power" : 85},
    {"name" : "scarecrow", "power" : 90},
    {"name" : "joker", "power" : 97},
]
sorted_characters = sorted(characters, key=lambda x: x["power"])
print(f"characters by power: {sorted_characters}")

# 4. combine lambdas and higher order functions -> add 5% tax and filter below 100 after tax and round results
prices = [50, 80, 120, 200]
calcs = list(filter(lambda x: x < 100,(map(lambda x: round(x + 0.05*x), prices))))
print(calcs)

# 5. using lambdas in real functions
def make_power(n):
    return lambda x: x**n
square = make_power(2)
cube = make_power(3)

print(square(4))
print(cube(2))

