#pylint: skip-file
#type: ignore

import requests

url = "https://icanhazdadjoke.com"

headers = {
    "Accept" : "text/plain",
    }

response = requests.get(url=url, headers=headers)

if response.status_code == 200:
    print("Received Response.\n")
    print("Joke:")
    data = response.text
else:
    print("No Response.")


print(data)
