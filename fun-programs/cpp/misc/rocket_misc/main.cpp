#include <iostream>
#include "Rocket.h"

int main()
{
    Rocket rocket(1000, 500, 20000);

    for (int i = 0; i < 100; i++)
    {
        rocket.update(0.1);
        std::cout << "Altitude: " << rocket.getAltitude() << "| Velocity: " << rocket.getVelocity() << std::endl;
    }
    return 0;
}