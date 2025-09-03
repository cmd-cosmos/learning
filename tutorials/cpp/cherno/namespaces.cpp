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

// nesting namespaces
namespace multi{
    namespace functions{
        void printf()
        {
            std::cout << "===========================================" << std::endl;
            std::cout << "multi namespace exec. started" << std::endl;
            falcon::launch();
            starship::launch();
            using namespace batman; // nesting custom namespace in a custom nested namespace
            cout(); // cout from the batman namespace
            std::cout << "multi namespace exec. complete" << std::endl;
            std::cout << "===========================================" << std::endl;
        }        
    }
}

int main()
{
    // using namespace falcon;
    // using namespace starship;
    // using namespace batman;

    // 2 functions with the same name ---> but different functionalities
    // namespaces defines the functionality of the member associated with the namespace.
    //2 symbols with the same name are not parsed by the linker thus resulting in a linking error

    falcon::launch();
    starship::launch();
    // launch(); // leads to error -->more than one instance of overloaded function "launch" matches the argument list:C/C++(308)

    batman::cout(); // since I have not used std namesapce I can overload the name and also call the cout function in the batman namespace without using the scope resolution operator

    {
        // if we use namespace standards then we do not need to use the :: to resolve the scope but conflicts will happen as both falcon and starship both have the same function name/signature.
    using namespace falcon;
    // using namespace starship;
    using namespace batman;

    // should work for falcon as falcon was the default namespace used here
    launch(); // issue is multiple overloads if both namespaces used

    cout(); // from the batman scope as namespace explicitly used in the scope 
    }
    
    {
        using namespace starship;
        launch(); // now launch function defaults to starship scope.
    }

    {
        // separate scope to test the nested namespace
        multi::functions::printf();

    }
    // prefer to use namespace in small scopes insead of main scope or larger scopes.
    // never use complete namespace in header files
    return 0;
}
