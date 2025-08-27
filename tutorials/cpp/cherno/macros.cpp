// macros: using preprocessor to replace text in code with something else
// go through the code and find and replace
// evaluated before everythinf during the preprocessing stage of the 4 stage compilation phase
// 4 step compilation process: 
// preprocessor ---> compiler ---> assembler ---> linker

#include <iostream>
#include <string>

#define OPEN_CURLY {
#define INTRODUCE std::cout << "I am Batman" << std::endl
#define WAIT do std::cout << "Press enter to exit" << std::endl; while(!std::cin.get());
#define LOG(x) std::cout << x << std::endl

int main()
OPEN_CURLY
    INTRODUCE; // inserts cout code here ---> ; written after macro name as ; not a part of the macro definition
    LOG("I am Vengeance");
    WAIT     // inserts cin code here ---> no ; req as ; included in the macro definition
    return 0;
}
