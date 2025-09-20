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
        print("-"*50)
        print("Choose Test Article/Procedure: ")
        print("-"*50)
        print("1. Ship ")
        print("2. Booster ")
        print("3. Integrated System - Starship")
        print("4. Dry Run")
        print("-"*50)
        
        try:
            targetVehicle = int(input("Enter Selection: "))
            if targetVehicle == 1:
                print("Proceeding with Ship Prop Load Procedures...")
                print("-"*50)
                valid=True
            elif targetVehicle == 2:
                print("Proceeding with Booster Prop Load Procedures...")
                print("-"*50)
                valid=True
            elif targetVehicle == 3:
                print("Proceeding with Starship SuperHeavy System Load Procedures...")
                print("-"*50)
                valid=True
            elif targetVehicle == 4:
                print("Dry Run - Test Procedure 1.2.31")
                print("-"*50)
                valid=True
            else:
                print("Invalid Input")
                print("-"*50)
        except ValueError:
            print("Invalid Input")
            print("-" * 50)

    return vehicleMap[targetVehicle]
    
# CONTROL LOOP

if __name__ == "__main__":
    targetVehicle = getTargetVehicle()



