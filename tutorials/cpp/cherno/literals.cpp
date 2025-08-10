// series of chars between ""
// string literals are stored in read-only memory.
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>

int main()
{
    const char name[10] = "batman";
    std::cout << strlen(name) << '\n'; // strlen does not include 

    // standard way to declare a string literal if done through cahr pointer.
    const char* valid = "batman"; // using const ensures read-only access to the string literal.
    
    char* undefined = "joken\n";    // unreliable as now we can try to modify the val at an idx but it could cause undefined behavior which is resolved based on complier.

    // undefined[2] = 'l'; // warning: ISO C++ forbids converting a string constant to 'char*'
    std::cout << undefined; // still shows a warning as const not used but now at least prints the literal

    // different types of char pointers ---> store single chars in different sizes.
    const char* regular = u8"Batman";
    const wchar_t* wide_char = L"Batman";
    const char16_t* name2 = u"Batman";
    const char32_t* name3 = U"Batman";

    using namespace std::string_literals;
    std::string mix = "I am "s + "Batman\n"; // use the s operator beside the first string literal to append another string to it.
    std::cout << mix;

// the R operator is important for multiline strings
// essentially ignores the escape seq chars.
// r here stands for raw strings
// are used in python too to print multiline strings and ignore escape seq chars. 
    const char* sample = R"(
L1
L2
L3
these should print in different lines.
    )";
    std::cout << sample;

    return 0;
}
