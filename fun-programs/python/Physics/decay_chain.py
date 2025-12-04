#pylint: skip-file
#type: ignore

import numpy as np
import matplotlib.pyplot as plt

# half life of 2 istopes 
i1 = 20
i2 = 40

lam1 = np.log(2) / i1
lam2 = np.log(2) / i2

dt    = 0.1
steps = 500

# initial amount of matter
A,B,C = 1000, 0, 0

A_hist, B_hist, C_hist = [],[],[]

for _ in range(steps):
    dA = np.random.binomial(A, lam1*dt)
    dB = np.random.binomial(B, lam2*dt)
    
    A -= dA
    B += dA - dB
    C += dB

    A_hist.append(A)
    B_hist.append(B)
    C_hist.append(C)

plt.plot(A_hist, label="A")
plt.plot(B_hist, label="B")
plt.plot(C_hist, label="C")
plt.legend()
plt.show()
