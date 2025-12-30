#pylint: skip-file

from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return "I am Vengeance"

@app.route("/about")
def about():
    return "this is the about page"

@app.route("/user/<name>")
def user(name):
    return f"I am {name}"

if __name__ == "__main__":
    app.run(debug=True, use_reloader=False)