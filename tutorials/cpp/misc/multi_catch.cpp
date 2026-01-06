#include <iostream>
#include <stdexcept>

void foo(int x)
{
    if (x == 0) 
    {
        throw std::runtime_error("ZERO ERROR");
    }
    if (x < 0)
    {
        throw std::logic_error("NEGATIVE ERROR");
    }
}

int main(void)
{
    try
    {
        foo(0);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "RUNTIME: " << e.what() << '\n';
    }
    try
    {
        foo(-100);
    }
    catch(const std::logic_error& e)
    {
        std::cerr << "LOGIC: " << e.what() << '\n';
    }
    

    return EXIT_SUCCESS;
}