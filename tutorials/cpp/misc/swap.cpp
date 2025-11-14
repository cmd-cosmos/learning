// swapping string

#include <iostream>

void swapString(std::string& x, std::string& y);

int main()
{
    std::string str  = "Batman";
    std::string str2 = "Joker";

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    swapString(str, str2);

    std::cout << str  << std::endl;
    std::cout << str2 << std::endl;

}

void swapString(std::string& x, std::string& y)
{
    std::cout << "\nSwapping Strings\n";
    std::string temp = x;
    x = y;
    y = temp;
    std::cout << '\n';
}
