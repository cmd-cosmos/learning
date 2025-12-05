#pylint: skip-file
#type: ignore

import numpy as np
import matplotlib.pyplot as plt

g: float     = 9.81

v0: float    = float(input("Enter Initial Velocity(m/s): "))
angle: float = float(input("Enter Angle(degrees): "))

radians: float     = np.radians(angle)
flight_time: float = (2 * v0 * np.sin(radians)) / g
t_pts: np.ndarray  = np.linspace(0, flight_time, num=1000)

# eqns of motion
x = v0 * np.cos(radians) * t_pts
y = v0 * np.sin(radians) * t_pts - 0.5 * g * t_pts**2

y = np.maximum(y, 0)
#plots
plt.plot(x, y)
plt.xlabel("Distance(m)")
plt.ylabel("Height(m)")
plt.grid(True)
plt.show()
