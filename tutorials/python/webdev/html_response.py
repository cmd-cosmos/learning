#type: ignore
#pylint: skip-file

from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return """
    <h1>I am Batman</h1><br><hr>
    <p>Welcome to Gotham</p><hr>

"""

if __name__ == "__main__":
    app.run(port=8080)