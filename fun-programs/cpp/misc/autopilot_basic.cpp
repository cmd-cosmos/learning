#include <iostream>
#include <chrono>
#include <functional>

enum class FlightMode {
    IDLE,
    TAKEOFF,
    CRUISE,
    LAND
};

class Autopilot
{
    FlightMode mode{FlightMode::IDLE};
    std::chrono::steady_clock::time_point last;
    public:
        Autopilot() : last(std::chrono::steady_clock::now()) {}
        
        void update(std::function<bool()> gearLocked) 
        {
            auto now = std::chrono::steady_clock::now();
            if (now - last < std::chrono::milliseconds(100)) return;
            last = now;

            switch (mode)
            {
            case FlightMode::IDLE: 
                mode = FlightMode::TAKEOFF; 
                break;
            case FlightMode::TAKEOFF:
                if (gearLocked()) {
                    mode = FlightMode::CRUISE;
                }
                break;
            case FlightMode::CRUISE:
                if (!gearLocked()) {
                    mode = FlightMode::LAND;
                }
                break;
            default:
                break;
            }
        }

        void log() const
        { 
            std::cout << "Mode: " << int(mode) << "\n";
        }
};

int main(void)
{


    return EXIT_SUCCESS;
}