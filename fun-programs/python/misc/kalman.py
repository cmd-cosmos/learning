#pylint: skip-file
#type:ignore

import numpy as np

altitude      = 0.0
uncertainty   = 100.0
measure_noise = 2.0
process_noise = 1.1

measurements = [10,11,12,13,11,13,12]

for j in measurements:
    uncertainty += process_noise

    K = uncertainty / (uncertainty + measure_noise)
    
    altitude = altitude + K*(j - altitude)

    uncertainty = (1 - K)*uncertainty

print(f"Estimate: {altitude}\nUncertainty: {uncertainty}")

