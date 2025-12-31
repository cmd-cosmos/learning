// RAII --> resource acquisition is initialization
// binding lifecycle of a resource to the lifetime of an object

#include <iostream>

struct Tracker {
    std::string name;

    Tracker(std::string n) : name(std::move(n))
    {
        std::cout << "construct: " << name << "\n";
    }

    ~Tracker()
    {
        std::cout << "destruct: " << name << "\n";
    }
};

int main(void)
{


    return EXIT_SUCCESS;
}

