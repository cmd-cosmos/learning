#pylint: skip-file
import time

class Rocket:
    def __init__(self, mass, fuel, max_thrust, isp) -> None:
        self.mass = mass  # kg
        self.fuel = fuel  # kg
        self.max_thrust = max_thrust # Newtons
        self.isp = isp
        self.altitude = 0.0
        self.velocity = 0.0

    @property
    def totMass(self):
        return self.mass + self.fuel

    def __repr__(self) -> str:
        return "Rocket(mass: {} kg | fuel: {} kg | max_thrust: {} N | isp: {} s)".format(self.mass,
                                                                     self.fuel,
                                                                     self.max_thrust,
                                                                     self.isp)

    def countDown(self, period):
        for i in range(period, 0, -1):
            print(i)
            time.sleep(0.75)
        self.__ignite()

    def __ignite(self):
        print("Ignition..")
        print("We have Liftoff...")

    def burn(self, thrust, dt):
        g = 9.81
        req_fuel = (thrust / (self.isp * g)) *dt
        if req_fuel > self.fuel:
            req_fuel = self.fuel
        self.fuel -= req_fuel
        return thrust if self.fuel > 0 else 0
    
    def update(self, dt):
        thrust = self.max_thrust
        calc_thrust = self.burn(thrust, dt)
        g = 9.81
        acc = calc_thrust / self.mass - g
        self.velocity += acc * dt
        self.altitude += self.velocity * dt
        if self.altitude < 0:
            self.altitude = 0
            self.velocity = 0

    
# starship = Rocket(1000, 700, 20000, 200)
# print(starship)

# starship.countDown(10)

