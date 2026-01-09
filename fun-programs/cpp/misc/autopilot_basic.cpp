#include <iostream>
#include <chrono>
#include <thread>

enum class FlightMode {
    IDLE,
    TAKEOFF,
    CRUISE,
    LAND
};

class Autopilot
{
    FlightMode mode{FlightMode::IDLE};
    std::chrono::steady_clock::time_point last {std::chrono::steady_clock::now()};
    public:
        void update(bool gearLocked) 
        {
            auto now = std::chrono::steady_clock::now();
            if (now - last < std::chrono::milliseconds(100)) return;
            last = now;

            if (mode == FlightMode::IDLE) {
                mode = FlightMode::TAKEOFF;
            }
            else if (mode == FlightMode::TAKEOFF && gearLocked) {
                mode = FlightMode::CRUISE;
            }
        }

        void log() const
        { 
            std::cout << "Mode: " << int(mode) << "\n";
        }
};

int main(void)
{
    Autopilot ap;
    for (int i = 0; i < 5; i++) {
        ap.update(true);
        ap.log();
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
    return EXIT_SUCCESS;
}