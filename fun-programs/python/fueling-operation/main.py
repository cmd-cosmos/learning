### BASED ROUGHLY ON THE STARSHIP ---> PRE SHIP STATIC FIRE TESTING FUELING PROCEDURE 
### simulating fueling procedure of a rocket
### fuel LOX and Methane simultaneously
### pressurize the tank farm
### chilling the plumbing to cryogenic temperatures
### start by pressurizing the tanks 
### proceed to prop load
### stop prop load at set level
### perform final tank pressurization to flight pressure


# CONSTANTS ---> FLOW RATES, VOLUME, TIME, PRESSURES, TEMPERATURES


# ASYNC FUNCTIONS

# HELPER FUNCTIONS

def getTargetVehicle():
    '''Function to get test article ---> for now only supports ship subroutine'''

    vehicleMap = {
        1 : "Ship",
        2 : "Booster",
        3 : "Integrated System",
        4 : "Dry Run",
    }

    validInputs = [1,2,3,4]
    valid = False

    while(valid==False):
        print("Choose Test Article/Procedure: ")
        print("1. Ship ")
        print("2. Booster ")
        print("3. Integrated System - Starship")
        print("4. Dry Run")
        targetVehicle = int(input("Enter Selection: "))
        if targetVehicle == "":
            print("Invalid Input")
        elif targetVehicle == 1:
            print("Proceeding with Ship Prop Load Procedures...")
            valid=True
        elif targetVehicle == 2:
            print("Proceeding with Booster Prop Load Procedures...")
            valid=True
        elif targetVehicle == 3:
            print("Proceeding with Starship SuperHeavy System Load Procedures...")
            valid=True
        elif targetVehicle == 4:
            print("Dry Run - Test Procedure 1.2.31")
            valid=True
        else:
            print("Invalid Input")

    return vehicleMap[targetVehicle]


    
    
# CONTROL LOOP

if __name__ == "__main__":
    targetVehicle = getTargetVehicle()
    print(targetVehicle)



