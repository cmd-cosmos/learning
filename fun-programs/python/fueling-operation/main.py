#pylint: skip-file
### BASED ROUGHLY ON THE STARSHIP ---> PRE SHIP STATIC FIRE TESTING FUELING PROCEDURE 
### simulating fueling procedure of a rocket
### fuel LOX and Methane simultaneously
### pressurize the tank farm
### chilling the plumbing to cryogenic temperatures
### start by pressurizing the tanks 
### proceed to prop load
### stop prop load at set level
### perform final tank pressurization to flight pressure


import time
import threading
import random
import sys

# CONSTANTS ---> FLOW RATES, VOLUME, TIME, PRESSURES, TEMPERATURES
FUEL_FLOW_RATE              =    2.5
PRESSURIZATION_SIM_TIME     =    5
CHILL_SIM_TIME              =    3
FINAL_PRESS_TIME            =    4

TARGET_LOX = 100.00
TARGET_CH4 = 100.00

LOG_INTERVAL = 1 #seconds

state = {
    "lox"   : 0.0,
    "ch4"   : 0.0,
    "PHASE" : "INIT",
    "DONE"  : False,
    "ABORT" : False,
    "LOCK"  : threading.Lock(),
}

# daemon logger thread
def logProcedure(state):
    while not state["DONE"]:
        with state["LOCK"]:
            lox = state["lox"]
            ch4 = state["ch4"]
            phase = state["PHASE"]
            abort = state["ABORT"]

        sys.stdout.write("\r")
        sys.stdout.flush()
        if abort:
            print("\n[ABORT] Sequence Aborter - Commencing Safing Procedures")

        if phase == "PRESSURIZING":
            print(f"[INFO] pressurizing tank farm")
        elif phase == "CHILL":
            print(f"[INFO] chilling plumbing")
        elif phase == "LOAD":
            print(f"[INFO] LOX : {lox:6.2f}% | CH4 : {ch4:6.2f}%")
        elif phase == "LAUNCH_PRESS":
            print(f"[INFO] final tank pressurization seq.")
        else:
            sys.stdout.write("[INIT] Stand By")
        
        time.sleep(LOG_INTERVAL)

    print("[ALERT] Prop Load Complete => GO for static fire.")


# HELPER FUNCTIONS

def pressurize():
    with state["LOCK"]:
        state["PHASE"] = "PRESSURIZING"
    time.sleep(PRESSURIZATION_SIM_TIME)

def chillLines():
    with state["LOCK"]:
        state["PHASE"] = "CHILL"
    time.sleep(CHILL_SIM_TIME)

def loadProp():
    with state["LOCK"]:
        state["PHASE"] = "LOAD"
    while True:
        with state["LOCK"]:
            if state["lox"] >= TARGET_LOX and state["ch4"] >= TARGET_CH4:
                break

            state["lox"] = min(TARGET_LOX, state["lox"] + FUEL_FLOW_RATE + random.uniform(-0.5,0.5))
            state["ch4"] = min(TARGET_CH4, state["ch4"] + FUEL_FLOW_RATE + random.uniform(-0.5, 0.5))
        time.sleep(1)

def finalPressurize():
    with state["LOCK"]:
        state["PHASE"] = "LAUNCH_PRESS"
    time.sleep(FINAL_PRESS_TIME)

def getTargetVehicle():
    '''Function to get test article ---> for now only supports ship subroutine'''

    vehicleMap = {
        1 : "Ship",
        2 : "Booster",
        3 : "Integrated System",
        4 : "Dry Run",
    }

    while(True):
        print("-"*50)
        print("Choose Test Article/Procedure: ")
        print("-"*50)
        print("1. Ship ")
        print("2. Booster ")
        print("3. Integrated System - Starship")
        print("4. Dry Run")
        print("-"*50)
        
        try:
            selection = int(input("Enter Selection: "))
            if selection in vehicleMap:
                print(f"\n[CONFIG] Selected: {vehicleMap[selection]}")
                return vehicleMap[selection]
        except ValueError:
            pass
        print("[WARN] Invalid Selection - Retry")

# control loop

def main():
    targetVehicle = getTargetVehicle()

    logger = threading.Thread(target=logProcedure, args=(state,), daemon=True)
    logger.start()

    try:
        pressurize()
        chillLines()
        loadProp()
        finalPressurize()
    except KeyboardInterrupt:
        with state["LOCK"]:
            state["ABORT"] = True
            state["DONE"] = True
        return
    with state["LOCK"]:
        state["DONE"] = True
    
    logger.join()
    
# entry point
if __name__ == "__main__":
    main()



