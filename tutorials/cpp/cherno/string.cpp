#include <iostream>
#include <string>

// chars ---> 1 byte in cpp but different encodings permit for differnet sizes like UTF16 = 2 byte char size

int main()
{
    // C style string definition
    const char* str = "batman";
    std::cout << str << '\n';

    // using library
    std::string str2 = "I am Batman";

    return 0;
}
