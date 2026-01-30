#pylint: skip-file
#type: ignore

from flask import Flask

app = Flask(__name__)

@app.route("/user/<name>")
def user(name):
    return f"Hello {name}"

@app.route("/age/<int:age>")
def age(age):
    return f"Age: {age}"

if __name__ == "__main__":
    app.run(port=8080)