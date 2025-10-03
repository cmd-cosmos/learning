# calcualte area of a cicrle 

import os

os.system("cls")

radius: int  = int(input("Radius: "))
pi: float    = 3.14

area: float  = pi*(radius**2)  
print("Area of the corresponding circle: {:.2f}".format(area))


