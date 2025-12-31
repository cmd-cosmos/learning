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

void test()
{
    Tracker a("A");
    {
        Tracker b("B");
    }
    std::cout << "exiting scope\n";
}

int main(void)
{
    test();

    return EXIT_SUCCESS;
}

