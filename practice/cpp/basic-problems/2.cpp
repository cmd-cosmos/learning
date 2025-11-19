// checking isalpha, isnum or special character.

#include <iostream>

int main()
{
    char ch;
    std::cout << "Enter a Character: ";
    std::cin >> ch;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        std::cout << "It is a character.\n";
    } 
    else if ((ch >= '0' && ch <= '9'))
    {
        std::cout << "It is a digit.\n";
    }
    else{
        std::cout << "It is a special character.\n";
    }
    return 0;
}
