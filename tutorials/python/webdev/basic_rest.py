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

    
@app.post("/form")
def form_val(user: User):
    users.append(user)
    return {
        "status" : 0,
        "user" : user
    }
