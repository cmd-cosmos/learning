#pylint: skip-file
#type: ignore

from flask import Flask, request, render_template

app = Flask(__name__)

@app.route("/intro")
def foo():
    return "I am Batman"

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get('username')
        password = request.form.get('password')

        return f"Username: {username} | Password: {password}"
    else:
        return render_template('login.html')
    
@app.route("/get")
def serve():
    return {
        1 : "Batman",
        2 : "Superman"
    }

if __name__ == "__main__":
    app.run()

