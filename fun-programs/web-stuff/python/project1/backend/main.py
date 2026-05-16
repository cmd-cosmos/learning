# pylint: skip-file
# type: ignore

from fastapi import FastAPI
from fastapi.responses import HTMLResponse
from pydantic import BaseModel

app = FastAPI()

# simulating a database
users = []

class Form(BaseModel):
    id : int
    name : str

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
            <p>This is a home page/landing page</p>
        </body>
    </html>
"""

@app.post("/form")
async def submit_form(formData : Form):
    uid = formData.id
    uname = formData.name
    users.append({
        "id" : uid,
        "name" : uname
    })
    return {
        "msg" : "user registered",
        "user id" : uid,
        "user name" : uname,
    }

@app.get("/users/{uid}")
def get_users(uid):
    uid = int(uid)
    return {
        "msg" : f"retrieving user with id {uid}",
        "user id" : users[uid]["id"], 
        "user name" : users[uid]["name"], 
    }