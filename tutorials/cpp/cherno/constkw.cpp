// const keyword is a promise made to not mutate something.
// since it is a promise it can be broken.
#include <iostream>
#include <string>

int main()
{
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
    // const after the astericks ensures that the pointer itself cannot be reassigned to a different mem location. ---> int* const a ---> the integer pointer must point to a constant mem location
    

    return 0;
}