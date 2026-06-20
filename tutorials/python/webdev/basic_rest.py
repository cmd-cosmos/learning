#pylint: skip-file
#type: ignore

from typing import List
from fastapi import FastAPI, HTTPException, status
from pydantic import BaseModel, Field

app = FastAPI(
    title="Basic REST",
    version= "1.0.0",
    docs_url="/docs",
    redoc_url="/redoc"
)

class UserCreate(BaseModel):
    id : int = Field(..., gt=0)
    name : str = Field(..., min_length=1, max_length=100)

class UserResponse(BaseModel):
    id: int
    name: str

class APIResponse(BaseModel):
    success: bool
    message: str
    
users: dict[int, UserResponse] = {}

@app.get("/", response_model=APIResponse)
async def health_check() -> APIResponse:
    return APIResponse(
        success = True,
        message = "backend is active"
    )
    
@app.post("/users",
          response_model=APIResponse,
          status_code=status.HTTP_201_CREATED)
async def add_user(user: UserCreate) -> APIResponse:
    if user.id in users:
       raise HTTPException(
           status_code=status.HTTP_409_CONFLICT,
           detail=f"user with id [{user.id}] alredy exists"
       )
    users[user.id] = UserResponse(id=user.id,name=user.name)
    return APIResponse(
        success=True,
        message="created user: %s" %user
    )

@app.get("/users",
         response_model=List[UserResponse],
         status_code=status.HTTP_200_OK
         )
async def get_users() -> List[UserResponse]:
    return list(users.values())

