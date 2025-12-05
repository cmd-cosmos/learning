#pylint: skip-file
#type: ignore

# 2 body gravitational system 

G  = 6.6743e-11 # m^3 kg^-1 s^-2
dt = 1

x1, y1, m1, vx1, vy1 = -1e7, 0, 1e5, 0, 100
x2, y2, m2, vx2, vy2 =  1e7, 0, 1e5, 0, -100

for _ in range(1000):
    dx = x2 - x1
    dy = y2 - y1
    r2 = dx*dx + dy*dy
    r  = r2**0.5
    F  = (G * m1 * m2) / r2

    ax1 = (F * dx) / (r * m1)
    ay1 = (F * dy) / (r * m1)

    ax2 = (-F * dx) / (r * m2)
    ay2 = (-F * dy) / (r * m2)

    vx1 += ax1 * dt
    vy1 += ay1 * dt

    vx2 += ax2 * dt
    vy2 += ay2 * dt

    x1 += vx1 * dt
    y1 += vy1 * dt

    x2 += vx2 * dt
    y2 += vy2 * dt

    print(f"x1 = {x1:.2f} | y1 ={y1:10.2f} | x2 = {x2:.2f} | y2 = {y2:.2f}")
