// const keyword is a promise made to not mutate something.
// since it is a promise it can be broken.
#include <iostream>
#include <string>

class Entity
// mark methods as const if they are not supposed to modify the class.
// if we want a variable to be modified in a const method ---> mark as mutable ---> use mutable keyword.
{
private:
    int m_X, m_Y;
    int* ptr;
    mutable int mut_A;
public:
    // const should be used with getters but not with setters.
    int GetX() const // after method name ---> works only in classes ---> prevents write on any class attribute passed to the method.
    {
        // m_X = 100; // does not allow this write as the method is bound to be const.
        
        mut_A += 1000; // since mut_A has the mutable keyword associated ---> it allows for mutation even within the const method.

        return m_X;
    }
    // not a const method.
    int SetX()
    {
        m_X += 1000;
    }
    const int* const GetPtr() const
    {
        return ptr;
    }
};

void PrintEntity(const Entity& e) // passing a constant reference
{
    //modify ptr behavior but cannot modify class behavior as pointer contents are set to read only.
    
    // e = Entity(); // error as e is read only due to it being passed as a const ref
}

int main()
{
    Entity e;

    int x = 5;
    const int MAX_THRUST = 100;

    x = 10;
    // MAX_THRUST = 200; // will give an error as y is const

    int* a = new int; // new integer on the heap
    *a = 2;           // deref allowed as it points to a regular int
    std::cout << *a <<'\n';

    a = (int*)&MAX_THRUST; // if cast as an int pointer, the const promise can be bypassed.
    std::cout << *a <<'\n';

    *a += 10000;
    std::cout << *a <<'\n';
    std::cout << MAX_THRUST << '\n';

    const int* ptr = new int; // same as int const* ptr = new int;
    // *ptr = 1000; // this will error out as now we cannot deref to assign, we can only deref to read and print to console.
    std::cout << *ptr; // prints a garbage value from the heap

    int* const ptr2 = new int; // this is a constant pointer, the values can change but the pointer cannot be reassigned to point to other locations.
    *ptr2 = 44440;
    // ptr2 = &a; // when we try to reassign to other locations ---> error: const ptr.
    
    //crux: 
    //const before the pointer astricks ensures that the value pointed to by the pointer is immutable. ---> const int* a or int const* ---> 
    // const after the astericks ensures that the pointer itself cannot be reassigned to a different mem location. ---> int* const a ---> read as: the integer pointer must point to a constant mem location
    
    return 0;
}