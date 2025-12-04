#pylint: skip-file
#type: ignore

# basic single isotope radioactive decay using the exponential law

import numpy as np
import matplotlib.pyplot as plt

initial_nuclei = 10000
half_life      = 30.0
dt             = 0.1
n              = initial_nuclei
history        = []

lamb1 = np.log(2) / half_life
steps = int(200 / dt)

for i in range(steps):
    decays = np.random.binomial(n, lamb1 * dt)
    n     -= decays
    history.append(n)

plt.plot(np.arange(steps)*dt, history)
plt.xlabel("Time (s)")
plt.ylabel("# Nuclei")
plt.show()

