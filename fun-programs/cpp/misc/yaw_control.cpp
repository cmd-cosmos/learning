#include <iostream>
#include <cmath>

double wrapAngle(double angle)
{
    while (angle > 180)
    {
        angle -= 360;
    }
    while (angle < -180)
    {
        angle += 360;
    }
    return angle;
}

int main(void)
{
    double yaw   = 0;   // curr yaw
    double setPt = 90;  // target yaw
    double kp    = 1.5; // proportional gain

    for (int i = 0; i < 50; ++i){
        double error   = wrapAngle(setPt - yaw);
        double control = kp * error;
        
        yaw += control * 0.1;
        std::cout << "time: " << i*0.1 << " s | yaw: " << yaw << " deg\n";             
    }

    return EXIT_SUCCESS;
}
