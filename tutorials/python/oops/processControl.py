# pylint: skip-file
# modeling state transitions

# NEW STATE -admitted--> READY STATE ----dispatch------->  RUNNING ---Exit--> TERMINATED STATE 
#                           ^                                |
#                           |--- BLOCKED STATE <-IO/ wait<--|

from typing import Optional
import time

class PCB:
    state_map = {
            1 : "NEW",
            2 : "READY",
            3 : "RUNNING",
            4 : "BLOCKED",
            5 : "TERMINATED",
        }
        
    def __init__(self, pid) -> None:
        self.pid = pid
        self.state = 1

    def setState(self, newState: int):
        if newState in self.state_map:
            print(f"PID: {self.pid} | TRANSITION: {self.state_map[self.state]} --> {self.state_map[newState]}")
            self.state =newState
        else:
            print(f"PID: {self.pid} | Invalid Transition Request")

class Process:
    pidCounter = 0

    def __init__(self) -> None:
        self.pcb : PCB

    def createProcess(self):
        Process.pidCounter += 1
        self.pcb = PCB(Process.pidCounter)
        print(f"Process: {self.pcb.pid} | Created State: {PCB.state_map[self.pcb.state]}")
        self.admit()

    def admit(self):
        self.pcb.setState(2)

    def dispatch(self):
        self.pcb.setState(3) if self.pcb.state == 2 else print("Cannot dispatch process until ")

    def ioWait(self, flag):
        # flag == 1 indicates ioWait enabled
        if self.pcb.state == 3 and flag == 1:
            self.pcb.setState(4)
            time.sleep(2)
            self.admit()
            flag = 0
            if flag == 0:
                print("IO wait ---> READY")

        elif flag == 0 and self.pcb.state == 3:
            # Exit without io wait
            print(f"LOG_PID: {self.pidCounter} | IO WAIT NOT REQUIRED")
            self.pcb.setState(5)
        else:
            print("Not Blockable at the monment")

    
        
    
p1 = Process()

p1.createProcess()
p1.dispatch()
p1.ioWait(0)





