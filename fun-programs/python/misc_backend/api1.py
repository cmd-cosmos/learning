#pylint: skip-file
#type: ignore

from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

@app.get("/")
def root():
    return {
        "message" : "backend active"
    }

@app.post("/users")
def add_users():
    pass