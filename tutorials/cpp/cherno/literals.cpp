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

    const char* valid = "batman"; // using const ensures read-only access to the string literal.
    
    char* undefined = "joker";    // unreliable as now we can try to modify the val at an idx but it could cause undefined behavior which is resolved based on complier.

    // undefined[2] = 'l'; // warning: ISO C++ forbids converting a string constant to 'char*'
    std::cout << undefined; // still shows a warning as const not used but now at least prints the literal

    return 0;
}
