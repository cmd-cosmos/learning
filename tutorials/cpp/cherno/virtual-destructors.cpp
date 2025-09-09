// virtual destructors
// important when polymorphism required
// ensures no memory leak if polymorphic behavior used
// mark virtual explicitly to ensure derived destructor called

#include <iostream>
#include <string>

class Base
{
    public:
        Base()
        {
            std::cout << "Base Contructor\n";
        }
        ~Base()
        {
            std::cout << "Base Destructor\n";
        }
};

class Derived : public Base
{
    public:
        Derived()
        {
            std::cout << "Derived Contructor\n";
        }
        ~Derived()
        {
            std::cout << "Derived Destructor\n";
        }
};

int main()
{
    Base* base = new Base();
    delete base;
    std::cout << "-------------------\n"; 
    Derived* derived = new Derived();
    delete derived;
    /*
    Output:
        Base Contructor
        Base Destructor
        -------------------
        Base Contructor
        Derived Contructor
        Derived Destructor
        Base Destructor
    */

    return 0;
}