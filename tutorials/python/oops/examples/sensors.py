#pylint: skip-file

import random

class Sensor:
    def __init__(self, name) -> None:
        self.name = name

    def readData(self, rocket):
        return None

class Altimeter(Sensor):
    def readData(self, rocket):
        noise = random.uniform(-2, 2)
        return rocket.altitude + noise
    
class Accelerometer(Sensor): # assume accl integrated to retreive velocity
    def readData(self, rocket):
        noise = random.uniform(-1, 1)
        return rocket.velocity + noise
