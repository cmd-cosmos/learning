// virtual destructors
// important when polymorphism required
// ensures no memory leak if polymorphic behavior used
// mark virtual explicitly to ensure derived destructor called
// rule: any class that will be extended, as in will have a sub class, mark its destructor as virtual.

#include <iostream>
#include <string>

class Base
{
    public:
        Base()
        {
            std::cout << "Base Contructor\n";
        }
        virtual ~Base() // mark the base destructor as virtual so cpp knows to search for any connections down in the heirarchy of inheritance
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
    std::cout << "-------------------\n"; 
    Base* polymorphic = new Derived(); // poiymorphic object pointed by a base pointer but init to as a derived object
    delete polymorphic;
    /*
    Change in output:

        Base Contructor
        Base Destructor
        -------------------
        Base Contructor
        Derived Contructor
        Derived Destructor
        Base Destructor
        -------------------
        Base Contructor
        Derived Contructor       < --------- Derived destructor was never called 
        Base Destructor          thus a mem leak
    */

    // after adding the virtual kw to the destructor of the base class
    /*
    change in output:

        Base Contructor
        Base Destructor
        -------------------
        Base Contructor
        Derived Contructor
        Derived Destructor
        Base Destructor
        -------------------
        Base Contructor
        Derived Contructor
        Derived Destructor
        Base Destructor
    */

    return 0;
}