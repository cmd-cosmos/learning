#pylint: skip-file
#type: ignore

import requests

base_url = r"https://www.weatherapi.com/docs/#"

response = requests.get(url=base_url)
print(response.status_code)

curr_weather = base_url + r"/current.json"
resp2 = requests.get(curr_weather)
print(resp2.status_code)
data = resp2.json
print(data)