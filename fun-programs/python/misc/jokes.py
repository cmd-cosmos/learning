#pylint: skip-file
#type: ignore

import requests

url = "https://icanhazdadjoke.com"

headers = {
    "Accept" : "text/plain",
    }

run = True

while run:
    user_inp = input("[DAD] Would you like to hear a Joke (y/n):\n[YOU]: ").strip().lower()

    if user_inp == "y":
        run = True
        response = requests.get(url=url, headers=headers)
        if response.status_code == 200:
            data = response.text
            print(f"\n[DAD]: {data}\n")
        else:
            print("No Response.")
    else:
        print("\nYour Loss...")
        run = False
