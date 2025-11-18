// swapping 2 nums

#include <iostream>

int main()
{
    int a = 1, b = 99, temp;

    std::cout << "Before: (a = " << a << ", b = " << b << ")\n";

    temp = a;
    a = b;
    b = temp;

    std::cout << "After: (a = " << a << ", b = " << b << ")\n";

    return 0;
}