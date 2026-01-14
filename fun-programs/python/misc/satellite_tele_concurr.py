#pylint: skip-file

import asyncio
import math
import random
from datetime import datetime

class Satellite:
    def __init__(self, name, orb_rad, ang_speed) -> None:
        self.name = name
        self.orb_rad = orb_rad
        self.ang_speed = ang_speed
        self.angle = random.uniform(0, 2 * math.pi)

    async def orbit(self):
        while True:
            self.angle += self.ang_speed
            x = self.orb_rad * math.cos(self.angle)
            y = self.orb_rad * math.sin(self.angle)
            print(f"[{datetime.now().strftime('%H:%M:%S')}] {self.name} : ({x:.1f}, {y:.1f}) km")
            await asyncio.sleep(1)

async def main():
    satellites = [
        Satellite("Starlink-1", 600, 0.02),
        Satellite("Starlink-302", 700, 0.05),
        Satellite("Hubble", 20000, 0.009),
        Satellite("COSMO-SAT", 6500, 0.01)
    ]

    await asyncio.gather(*(sat.orbit() for sat in satellites))

asyncio.run(main())