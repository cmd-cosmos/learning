// dynamic memory allocation

#include <iostream>

int main()
{
    int* ptr = new int; // allocate mem on heap for single integer

    *ptr = 10;

    std::cout << "val: " << *ptr << std::endl;

    delete ptr; // free mem to avoid mem leaks

    return 0;
}
