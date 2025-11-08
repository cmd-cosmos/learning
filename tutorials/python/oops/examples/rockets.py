#pylint: skip-file
import time

class Rocket:
    def __init__(self, mass, fuel, max_thrust) -> None:
        self.mass = mass  # kg
        self.fuel = fuel  # kg
        self.max_thrust = max_thrust # Newtons
        self.altitude = 0.0
        self.velocity = 0.0

    def __repr__(self) -> str:
        return "Rocket(mass: {} | fuel: {} | max_thrust: {})".format(self.mass,
                                                                     self.fuel,
                                                                     self.max_thrust)

    def countDown(self, period):
        for i in range(1, period, -1):
            print(i)
        self.__ignite()

    def __ignite(self):
        print("Ignition..")
        print("We have Liftoff...")
    
starship = Rocket(100, 100, 100)
print(starship)


