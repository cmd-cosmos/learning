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
                std::cout << "Motor RPM: " << rpm << " RPM\n";
            }
        }

        void stop() {
            rpm_ = 0;
            state_ = State::STOPPED;
            std::cout << "Motor Stopped\n";
        }

        double getRPM() const {
            return rpm_;
        }

        State getState() const {
            return state_;
        }

        std::string getStateString() const {
            switch (state_)
            {
            case State::STOPPED: return "STOPPED";
            case State::RUNNING: return "RUNNING";            
            case State::FAULT:   return "FAULT";            
            default:             return "UNKNOWN";
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
        std::cout << "Motor State: " << m.getStateString() << '\n';
    }
    catch(const MotorException& e)
    {
        std::cerr << "MOTOR ERROR: " << e.what() << '\n';
    }
    
    std::cout << "\nSetting motor speed to 5000 RPM\n";

    try
    {
        m.setRPM(5000);
    }
    catch(const MotorException& e)
    {
        std::cerr << "\nMOTOR ERROR: " << e.what();
        std::cerr << "POST FAULT STATE: " << m.getStateString() << '\n';
    }
    

    return EXIT_SUCCESS;
}