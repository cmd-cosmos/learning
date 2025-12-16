#pylint: skip-file
#type: ignore

import random

LIMITS = {
    "battery_temp" : (-20, 70),
    "bus_voltage"  : (25.0, 40.0),
    "sensor_bias"  : (-0.05, 0.05)
}

def check_limit_violations(telemetry):
    violations = []

    for param, (low, high) in LIMITS.items():
        val = telemetry.get(param)
        if val is None:
            continue
        if not low <= val <= high:
            violations.append((param, val))
    
    return violations

if __name__ == "__main__":
    telemetry = {
        "battery_temp" : random.randint(-30, 100),
        "bus_voltage"  : random.randint(0, 60),
        "sensor_bias"  : random.randint(-5,5) * (random.random() /100)
    }

    print("VIOLATIONS: ", check_limit_violations(telemetry=telemetry))
    