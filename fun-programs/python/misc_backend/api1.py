#pylint: skip-file
#type: ignore

from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

class User(BaseModel):
    id : int
    name : str

@app.get("/")
def root():
    return {
        "message" : "backend active"
    }

@app.post("/users")
def add_users(user : User):
    pass