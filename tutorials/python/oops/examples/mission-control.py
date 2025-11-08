#pylint: skip-file
import time
from rockets import Rocket
from sensors import Sensor, Altimeter, Accelerometer

class MissionControl:
    def __init__(self, rocket, sensors) -> None:
        self.rocket = rocket
        self.sensors = sensors

    def run_sim(self, dt=1, max_time = 20):
        t = 0
        while t < max_time and self.rocket.altitude >= 0:
            time.sleep(0.5)
            self.rocket.update(dt)
            readings = {sensor.name: sensor.readData(self.rocket) for sensor in self.sensors}
            print(f"t = {t:.2f}s\n\
                  alt: {self.rocket.altitude:.2f} m\n\
                  vel: {self.rocket.velocity:.2f} m/s\n\
                  fuel: {self.rocket.fuel:.2f} kg\n\
                  sensors: {readings}")
            t += dt

if __name__ == "__main__":
    starship = Rocket(mass=1000, fuel=500, max_thrust=20000, isp=300)
    sensor_lst = [Altimeter("Altimeter"), Accelerometer("Accelerometer")]
    command = MissionControl(rocket=starship, sensors=sensor_lst)
    command.run_sim()

