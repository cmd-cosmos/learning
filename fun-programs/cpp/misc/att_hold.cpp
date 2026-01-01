#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(std::time(0));
    double altitude = 0;
    double setpoint = 50;
    double kp = 0.8;
    double dt = 0.1;

    for (int i = 0; i < 50; ++i)
    {
        double disturbance = (std::rand() % 21 - 10) * 0.1;
        double error       = setpoint - altitude;
        double control     = kp * error;

        altitude += (control + disturbance) * dt;
        std::cout << "time: " << i*dt << " s | altitude: " << altitude << " m | disturbance: " << disturbance << std::endl;
    }

    return EXIT_SUCCESS;
}
