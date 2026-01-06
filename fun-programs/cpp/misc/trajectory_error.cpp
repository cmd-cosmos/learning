#include <iostream>
#include <vector>
#include <stdexcept>

void followTrajectory(const std::vector<double>& trajectory)
{
    for (double x : trajectory)
    {
        if (x < 0)
        {
            throw std::invalid_argument("INVALID TRAJECTORY COORDINATE");
        }
        else
        {
            std::cout << "WAYPOINT: " << x << "\n";
        }
    }
}

int main(void)
{
    std::vector<double> trajectory = {1.0, 2.0, -1.5, 3.0};

    try
    {
        followTrajectory(trajectory);
    }
    catch(const std::exception& e)
    {
        std::cout << "\nTRAJECTORY ERROR: " << e.what() << '\n';
    }
    

    return EXIT_SUCCESS;
}