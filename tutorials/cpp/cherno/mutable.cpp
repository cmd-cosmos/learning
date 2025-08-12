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
        std::cout << m_DebugCounter;
    }
};

int main()
{
    const Entity e;
    e.GetName();
    e.GetName();
    e.GetName();
    e.LogGetterCalls();
    return 0;
}
