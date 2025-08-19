// object lifetime - objects on the stack
// lifetime for stack based varaibles

#include <iostream>
#include <string>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Constructior" << '\n';
        }
        ~Entity()
        {
            std::cout << "Destructor" << '\n';
        }
};

int main()
{
    {
                    // object in an empty scope but yet scope bound
        Entity e;   // constructor called
    }               // destructor called here
    // stack entity obj destroyed
    
    return 0;
}

