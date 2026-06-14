#pylint: skip-file
#type: ignore
import sqlite3
import requests
import time
import random
import os
import sys

def create_database(db_name: str) -> sqlite3.Cursor:
    conn = sqlite3.connect(db_name)
    cur = sqlite3.Cursor(conn)
    return cur
    
def delete_database(db_name: str):
    pass