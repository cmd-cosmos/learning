#type:ignore
#pylint: skip-file

class CommandRejected(Exception):
    pass

class VehicleState:
    def __init__(self, altitude, stability_flag, fuel_mass) -> None:
        self.altitude       = altitude       # meters
        self.stability_flag = stability_flag # bool
        self.fuel_mass      = fuel_mass      # kg
    
class Command:
    def __init__(self, name) -> None:
        self.name = name

def validate_command(cmd, vehicle_state):
    if cmd.name == "DEPLOY_PAYLOAD":
        if vehicle_state.altitude <  160_000:
            raise CommandRejected("Low Altitude for Payload Deployment.")
        if not vehicle_state.stability_flag:
            raise CommandRejected("Vehicle unstable.")
    
    if cmd.name == "ENGINE_RELIGHT":
        if vehicle_state.fuel_mass < 5000:
            raise CommandRejected("Insufficient fuel.")
        
if __name__ == "__main__":
    state = VehicleState(120_000, True, 6000)
    cmd   = Command("DEPLOY_PAYLOAD")

    try:
        validate_command(cmd=cmd, vehicle_state=state)
        print("Command Validated.")
    except CommandRejected as e:
        print(f"Rejected: {e}") 

