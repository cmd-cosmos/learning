#include <iostream>
#include <stdexcept>

class MotorException : public std::runtime_error {
    public:
        explicit MotorException(const std::string& msg) : std::runtime_error(msg) {}
};

class Motor {
    public:
        void setRPM(double rpm) {
            if (rpm > 3500) {
                throw std::runtime_error("MOTOR OVERSPEEDING\n");
            }
            else {
                std::cout << "Motor RPM: " << rpm << " RPM";
            }
        }
};

int main(void)
{
    Motor m;
    try
    {
        m.setRPM(1000);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "MOTOR ERROR: " << e.what() << '\n';
    }
    
    std::cout << "\nSetting motor speed to 5000 RPM\n";

    try
    {
        m.setRPM(5000);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "MOTOR ERROR: " << e.what() << '\n';
    }
    

    return EXIT_SUCCESS;
}