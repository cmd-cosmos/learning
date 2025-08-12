// mutable keyword ---> changable 
// 2 uses:
// used in tandom with const ---> used in class methods
// other context is its use with lambdas.

#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCounter = 0; // counts number of times getter method was called
public:
/*
a reason to mark some class methods as const is:
- if in the main scope an object is defined as a const it will not execute non const methods. 
*/

    const std::string& GetName() const
    {
        // since we want a constant method to update an attribute, the attribute must be marked with the mutable keyword.
        m_DebugCounter++;
        return m_Name;
    }

    void LogGetterCalls() const
    {
        std::cout << m_DebugCounter << '\n';
    }
};

int main()
{
    const Entity e;
    e.GetName();
    e.GetName();
    e.GetName();
    e.LogGetterCalls();

    // using const with lambda functions
    // lambdas are throw away functions assigned to variables
    
    int x = 10;
    //capture method for argument being passed in the [] --> use &/=
    // pass by reference for labdas works fine without the mutable kw ---> so if & used in the [] to capture the argument then mutable can be ignored
    // but if we want to pass by values ---> we need to create a new var and assign val of parameter to that var. 
    // use mutable when = passed to the []
    // essentailly the parameter is not updated but a copy of the parameter is inside the function which could be a purpose too.
    // pass by reference would modify the parameter varaible itself whereas pass by value will create a copy of the parameter in the function scope and modify it without touching the input parameter.

    std::cout << "x outside lambda before lambda exec: "  << x << '\n';

    auto f = [=]() mutable 
    {
        x++; // x becomes 11 within the scope and the x outside the scope is not affected.
        std::cout << "lambda called" << '\n';
        std::cout << "x inside lambda: "  << x << '\n';
        std::cout << "lambda done" << '\n';
    };

    f();
    // x is stil 10
    std::cout << "x outside lambda after lambda exec: "  << x << '\n';

    return 0;
}
