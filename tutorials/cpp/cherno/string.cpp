#include <iostream>
#include <string>

// chars ---> 1 byte in cpp but different encodings permit for differnet sizes like UTF16 = 2 byte char size

void badString(std::string string) // this will create a copy instead of affecting the actual string ---> no mods can be performed on the srgument string when this method of pass by value used.
// read only function
{
    std::cout << string << '\n';
}

void goodFunction(const std::string& string_ref) // pass by reference method to pass the pointer to the original string.
// avoids expensive operation of string copy.
// provides write access to the original string.
{
    // since we use const we will not mutate the string but we could now since we have the reference to the string.
}

int main()
{
    // C style string definition
    const char* str = "batman";
    std::cout << str << '\n';

    // using library
    std::string str2 = "I am Batman";

    char* sample = "joker";
    char alias[6] = {'J','o','k','e','r',0};
    // null termination character and stack guards to ensure boundary definition.

    char* test = "Hello";
    std::cout << *test << '\n'; // prints the first letter of the word

    for (int i = 0; i < 6; i++)
    {
        std::cout << *(test+i) << '\n'; // using pointer deref to print a string till the null escape seq.
    }

    std::string name = "batman";
    std::cout << name.size() << '\n';
    std::string line = " is my name. \n";
    name += line;                           // appending strings
    std::cout << name;

    bool contains = name.find("z") != std::string::npos; // npos is to ensure boundary integrity maintained when find function iterates over the string.
    std::cout << contains; // 0 ---> not in the string

    return 0;
}
