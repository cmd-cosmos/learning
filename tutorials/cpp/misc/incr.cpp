#include <iostream>

int main()
{
    // postfix increment
    int i = 100;

    std::cout << i << '\n';   // 100
    std::cout << i++ << '\n'; // still 100
    std::cout << i << '\n';   // updated to 101
    std::cout << i++ << '\n'; // still 101
    std::cout << i << '\n';   // updated to 102


    // prefix increment
    int j = 10;

    std::cout << j << '\n';   // 10
    std::cout << ++j << '\n'; // 11
    std::cout << j << '\n';   // 11
    std::cout << ++j << '\n'; // 12
    std::cout << j << '\n';   // 12

    return 0;
}
