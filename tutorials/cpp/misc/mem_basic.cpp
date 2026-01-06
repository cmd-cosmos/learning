// basic manual mem alloc

#include <iostream>

int main(void)
{
    int* ptr = new int;
    
    *ptr  = 100;

    std::cout << *ptr; 

    delete ptr;

    return EXIT_SUCCESS;
}