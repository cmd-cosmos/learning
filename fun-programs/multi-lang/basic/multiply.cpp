#include <iostream>

int main()
{
    std::cerr << "\n------- Entered C++ Routine -------\n";
    int a, b;
    std::cin >> a >> b;
    std::cerr << "Multiplying: " << a << " and " << b << '\n';
    std::cout << a * b;
    std::cerr << "------- Exiting C++ Routine -------\n";

    return 0;
}
