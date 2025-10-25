# pylint: skip-file
# modeling state transitions

# NEW STATE -admitted--> READY STATE ----dispatch------->  RUNNING ---Exit--> TERMINATED STATE 
#                           ^                                |
#                           |--- BLOCKED STATE <-IO/ wait<--|

from typing import Optional

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
    






