# type: ignore
# pylint: skip-file

from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return "HOME PAGE"

@app.route("/about")
def about():
    return "About Page"

@app.route("/contact")
def contact():
    return "Contact Page"

if __name__ == "__main__":
    app.run(host="127.0.0.1", port=8080)
