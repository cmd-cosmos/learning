# calcualte area of a cicrle 

import os

os.system("cls")
os.system("echo running area calculation program")

validFlag = False

while not validFlag:
    try:
        radius: int  = int(input("Radius: "))
        if not radius or radius < 0:
            raise ValueError("Invlalid Input")
        validFlag = True
    except ValueError:
            os.system("cls")
            os.system("echo rerunning due to: invalid input")
    except KeyboardInterrupt:
         os.system("cls")
         print("keyboard interrup ---> exiting")
         exit()

pi: float    = 3.14
area: float  = pi*(radius**2)  
print("Area of the corresponding circle: {:.2f}".format(area))


