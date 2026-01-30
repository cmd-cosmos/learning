#pylint: skip-file
#type: ignore


from flask import Flask, jsonify

app = Flask(__name__)

@app.route("/api/help", methods=["GET"])
def hello():
    return jsonify({
        "message" : "REST API",
        "status" : "success"
    })

if __name__ == "__main__":
    app.run(port=8080)