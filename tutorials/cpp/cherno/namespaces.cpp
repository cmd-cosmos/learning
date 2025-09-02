#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace starship
{
    void launch()
    {
        std::cout << "Launching starship" << std::endl;
    }
}

namespace falcon
{
    void launch()
    {
        std::cout << "Launching falcon" << std::endl;
    }
}

namespace batman
{
    // same function name as provided by the standard library
    void cout()
    {
        std::cout << "I am Batman" << std::endl;
    }
}

int main()
{
    using namespace falcon;
    using namespace starship;
    using namespace batman;

    // 2 functions with the same name ---> but different functionalities
    // namespaces defines the functionality of the member associated with the namespace.

    falcon::launch();
    starship::launch();
    // launch(); // leads to error -->more than one instance of overloaded function "launch" matches the argument list:C/C++(308)

    cout(); // since I have not used std namesapce I can overload the name and also call the cout function in the batman namespace without using the scope resolution operator

    return 0;
}
