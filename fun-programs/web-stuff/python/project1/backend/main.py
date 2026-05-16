# pylint: skip-file
# type: ignore

from fastapi import FastAPI
from fastapi.responses import HTMLResponse

app = FastAPI()

@app.get("/")
def root():
    return {
        "status" : "backend active - root page"
    }

@app.get("/home", response_class=HTMLResponse)
def homepage():
    return """
    <html>
        <head>
            <title>Home Page</title>
        </head>
        <body>
            <h>Home Page</h>
        </body>
    </html>
"""