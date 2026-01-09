#include <iostream>
#include <stdexcept>

class MotorException : public std::runtime_error {
    public:
        explicit MotorException(const std::string& msg) : std::runtime_error(msg) {}
};

class Motor {
    public:
        enum class State {
            STOPPED,
            RUNNING,
            FAULT
        };

        Motor() : rpm_(0.0), state_(State::STOPPED) {}
        
        void setRPM(double rpm) {
            if (rpm > MAX_RPM) {
                triggerFault("MOTOR OVERSPEEDING\n");
            }
            if (rpm < 0) {
                triggerFault("NEGATIVE RPM ERROR");
            }
            else {
                rpm_ = rpm;
                state_ = (rpm_ > 0) ? State::RUNNING : State::STOPPED;
                std::cout << "Motor RPM: " << rpm << " RPM";
            }
        }


    private:
        double rpm_;
        State state_;

        void triggerFault(const std::string& reason) {
            rpm_ = 0;
            state_ = State::FAULT;
            throw MotorException(reason);
        }

        static constexpr double MAX_RPM = 3500.0;
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