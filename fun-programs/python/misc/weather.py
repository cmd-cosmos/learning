#pylint: skip-file
#type: ignore

import requests
import sys


def get_coordinates(city):
    url = "https://geocoding-api.open-meteo.com/v1/search"
    params = {
        "name": city,
        "count": 1,
        "language": "en",
        "format": "json",
    }

    response = requests.get(url, params=params)
    data = response.json()

    if "results" not in data:
        print("City not found.")
        sys.exit(1)

    result = data["results"][0]
    return result["latitude"], result["longitude"], result["name"], result["country"]


def get_weather(lat, lon):
    url = "https://api.open-meteo.com/v1/forecast"
    params = {
        "latitude": lat,
        "longitude": lon,
        "current_weather": True,
    }

    response = requests.get(url, params=params)
    return response.json()["current_weather"]


def main():
    if len(sys.argv) < 2:
        print("Usage: python weather.py <city>")
        sys.exit(1)

    city = " ".join(sys.argv[1:])

    lat, lon, name, country = get_coordinates(city)
    weather = get_weather(lat, lon)
    # print(weather)

    print(f"\nWeather for {name}, {country}")
    print("-" * 30)
    print(f"Time : {weather['time']}")
    print(f"Temperature : {weather['temperature']}°C")
    print(f"Wind Speed  : {weather['windspeed']} km/h")
    print(f"Wind Dir   : {weather['winddirection']}°")
    print(f"Condition  : Weather code {weather['weathercode']}\n")


if __name__ == "__main__":
    main()
