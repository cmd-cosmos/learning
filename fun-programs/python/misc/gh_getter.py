#pylint:skip-file
#type: ignore

import requests

def fetch_repos(username):
    url = f"https://api.github.com/users/{username}/repos"
    response = requests.get(url, timeout=5)
    response.raise_for_status()
    return response.json()

def main():
    username = "cmd-cosmos"
    repos = fetch_repos(username=username)
    for repo in repos:
        print(f"Repo Name: {repo["name"]}")

if __name__ == "__main__":
    main()