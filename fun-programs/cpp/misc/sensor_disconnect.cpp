#include <iostream>
#include <stdexcept>

class Sensor {
    private:
        bool connected = true;

    public:
        Sensor() {
            std::cout << "Initialized Sensor\n";
        }
        double read()
        {
            if (!connected) {
                throw std::runtime_error("SENSOR DISCONNECTED");
            }
            else {
                return 100.034;
            }
        }

        void disconnect() {
            std::cout << "Disconnecting Sensor\n";
            connected = false;
        }
};

int main(void)
{
    Sensor s;
    std::cout << "READING: " << s.read() << "\n";
    s.disconnect();
    
    try
    {
        std::cout << s.read() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << "SENSOR ERROR: " << e.what() << '\n';
    }
    

    return EXIT_SUCCESS;
}