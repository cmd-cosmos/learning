#pylint: skip-file
#type: ignore

from flask import Flask, jsonify

app = Flask(__name__)

@app.route("/user/<name>")
def user(name):
    return f"Hello {name}"

@app.route("/age/<int:age>")
def age(age):
    return f"Age: {age}"

@app.route("/api/user/<username>", methods=["GET"])
def get_user(username):
    return jsonify({
        "user" : username,
        "role" : "student"
    })

if __name__ == "__main__":
    app.run(port=8080)