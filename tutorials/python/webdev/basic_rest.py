#pylint: skip-file
#type: ignore

from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI(
    title="Basic REST",
    version= "0.1.0"
)

class User(BaseModel):
    id : int
    name : str
    

users = []

@app.get("/")
def root():
    return {
        "status" : 0,
        "message" : "backend active"
    }

@app.post("/user")
def add_user(user: User):
    users.append(user)
    return {
        "status" : 0,
        "message" : "added user: %s" %user
    }

@app.get("/user")
def get_all_users():
    return {
        "status" : 0,
        "result" : users 
    }