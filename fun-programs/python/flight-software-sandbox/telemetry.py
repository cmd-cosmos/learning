#pylint: skip-file
#type:ignore

class Telemetry:
    def __init__(self) -> None:
        self.log = []
    
    def record(self, t, alt, vel):
        self.log.append((t, alt, vel))
    
    def dump(self):
        for t, alt, vel in self.log:
            print(f"T: {t:04.1f}s | alt: {alt:04.1f}m | vel: {vel:04.1f}m/s")

alt, vel, dt = 0.0, 0.0, 0.1
tele = Telemetry()

for t in range(50):
    vel += 5*dt
    alt += vel*dt
    tele.record(t*dt, alt, vel)

tele.dump()
