#pylint: skip-file
#type: ignore

from flask import Flask

app = Flask(__name__)

@app.route("/intro")
def foo():
    return "I am Batman"

if __name__ == "__main__":
    app.run()

