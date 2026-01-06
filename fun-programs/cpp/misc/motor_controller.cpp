#include <iostream>

struct Motor
{
    Motor() {
        std::cout << "Motor ON\n";
    }
    ~Motor() {
        std::cout << "Motor OFF\n";
    }

    void setRPM(int rpm) {
        std::cout << "RPM: " << rpm << "\n";
    }
};


int main(void)
{
    {
        Motor m;
        m.setRPM(6000);
    }
    // auto shutdown at end of scope
    return EXIT_SUCCESS;
}