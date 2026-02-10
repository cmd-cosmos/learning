# pylint: skip-file
import matplotlib.pyplot as plt
import time

speed = [i for i in range(0, 100, 10)]
time_steps = list(range(len(speed)))

fig, ax = plt.subplots()
ax.set_xlim(0, 10)
ax.set_ylim(0, 100)
ax.set_xlabel("Time")
ax.set_ylabel("Speed")

line, = ax.plot([], [], marker='o', linestyle='-')
x_data, y_data = [], []

plt.ion()  
plt.show()

for t, s in zip(time_steps, speed):
    x_data.append(t)
    y_data.append(s)
    
    line.set_data(x_data, y_data)
    fig.canvas.draw()    
    fig.canvas.flush_events()  
    time.sleep(1)            
