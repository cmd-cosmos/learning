# pylint: skip-file

import time
import threading
import random

LOG_FILE = "satellite-telemetry.txt"

def telemetry_log_daemon(sat_id):
    with open(LOG_FILE, 'a') as f:
        while True:
            pos = (random.uniform(-1000, 1000),
                   random.uniform(-1000, 1000),
                   random.uniform(-1000, 1000))
            vel = random.uniform(0, 10)
            timestamp = time.ctime()

            telemetry = (
                f"{timestamp} | Satellite ID: {sat_id} |"
                f"POS: {pos}  | VEL: {vel:.2f} km/s    |\n"
            )

            f.write(telemetry)
            f.flush()

            print(f"LOGGED: {telemetry}")
            time.sleep(1)

def main():
    for id in range(1,4):
        t = threading.Thread(target=telemetry_log_daemon, args=(id,), daemon=True)
        t.start()

    print("logging telemetry data --> press ctrl + c to stop.")

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nkilling main thread --> daemon disposed")

if __name__ == "__main__":
    main()