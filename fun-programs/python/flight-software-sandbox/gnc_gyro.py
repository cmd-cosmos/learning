#pylint: skip-file
#type: ignore

import numpy as np

def skew(w):
    '''
    skewing a matrix.
    
    :param w: input matrix
    '''
    return np.array([
        [0, -w[2], w[1]],
        [w[2], 0, -w[0]],
        [-w[1], w[0], 0]
    ])

def propogate_dcm(C_bn, gyro_rad_s, dt):
    omega = skew(gyro_rad_s)
    return C_bn @ (np.eye(3) + omega*dt)

if __name__ == "__main__":
    C_bn = np.eye(3)
    gyro = np.array([0.01, -0.02, 0.005]) # rad per second
    dt = 0.1

    C_next = propogate_dcm(C_bn=C_bn, gyro_rad_s=gyro, dt=dt)
    print(C_next)
