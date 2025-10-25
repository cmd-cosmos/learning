# pylint: skip-file
# modeling state transitions

# NEW STATE -admitted--> READY STATE ----dispatch------->  RUNNING ---Exit--> TERMINATED STATE 
#                           ^                                |
#                           |--- BLOCKED STATE <-IO/ wait<--|


class PCB:
    def __init__(self) -> None:
        state_map = {
            1 : "NEW",
            2 : "READY",
            3 : "RUNNING",
            4 : "BLOCKED",
            5 : "TERMINATED",
        }
        

class Process:
    def __init__(self) -> None:
        pass

    def createProcess(self):
        pass





