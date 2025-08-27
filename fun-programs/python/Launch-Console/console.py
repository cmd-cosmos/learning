### Simulating a launch operations console, from pre launch launch control to post launch mission control.

from art import art
import time
import logging

vechicle_list: list = ["Starship", "Falcon 9", "Falcon Heavy"]
operator_auth_map: dict = {"Bruce"    : 1,
                           "Prem"     : 1,
                           "Alfred"   : 2,
                           "Joker"    : 3, 
                           "Jason"    : 4,
                           "Mike"     : 4,
                           "Harley"   : 5,
                           "Harvey"   : 5
}
authority_level: dict = {
    1 : "Root/LD/MD",
    2 : "Senior Controller",
    3 : "Junior Controller",
    4 : "Training",
    5 : "No Access"
}

print(art.space_x_logo)
print(art.operator_console_logo)
print()

print("Booting Up Controls")
time.sleep(3)
print("Commencing Auth Check Procedure...")
time.sleep(2)

def get_credentials(name):
    for key, val in operator_auth_map.items():
        if key.lower() == name.lower():
            user_level: str = authority_level[val]
            return user_level
        # elif name not in operator_auth_map:
    # print("Unauthorized Operator.")
    # print("No operator with alias: {}".format(name))


operator_name_input: str = input("Enter Operator Alias: ")
determined_level = get_credentials(operator_name_input) 
print("Control Authority Level: {}".format(determined_level))
# choice = int(input("Enter Vehicle: "))
