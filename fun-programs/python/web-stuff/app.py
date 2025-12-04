#pylint: skip-file
#type: ignore

from flask import jsonify, Flask, request

app = Flask(__name__)

@app.route("/")
def home():
    return jsonify({
        "message" : "API Running"
    })

@app.route("/add", methods=["GET"])
def add():
    try:
        a = float(request.args.get("a", 0))
        b = float(request.args.get("b", 0))
        return jsonify({
            "result" : a + b
        })
    except Exception as e:
        return jsonify({
            "error" : str(e)
        }), 400
    
if __name__ == "__main__":
    app.run(debug=True, use_reloader=False)
