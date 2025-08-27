// macros: using preprocessor to replace text in code with something else
// macros are most helpful for debugging
// go through the code and find and replace
// evaluated before everything during the preprocessing stage of the 4 stage compilation phase
// 4 step compilation process: 
// preprocessor ---> compiler ---> assembler ---> linker
#include <iostream>
#include <string>

#define OPEN_CURLY {
#define INTRODUCE std::cout << "I am Batman" << std::endl
#define WAIT do std::cout << "Press enter to exit" << std::endl; while(!std::cin.get());
#define LOG(x) std::cout << x << std::endl

// we do not always want macros to run ---> some macros could be only for debugging and are not required in release builds.
// like loggers
// how can we enable and disable macros as needed.

#define HEALTH_LOGGER_FLAG 0 // when this flag set to 1 ---> it will allow the program to use the cout definition
// if this was 0 then it will not print anything to console
#if HEALTH_LOGGER_FLAG == 1
#define HEALTH_LOGGER(x) std::cout << x << std::endl
#else
#define HEALTH_LOGGER(x)
#endif

// inactive preprocessor block
#if 0
// a whole block of preprocessor statements and macros
#define SOMETHING
#define SOMETHING
#define SOMETHING
#define SOMETHING
#define SOMETHING
#endif

int main()
OPEN_CURLY
    INTRODUCE; // inserts cout code here ---> ; written after macro name as ; not a part of the macro definition
    LOG("I am Vengeance");
    HEALTH_LOGGER("Vehicle chamber pressures nominal."); // only when the flag for this macro is set to 1 will this be printed else this will not be included in the build.
    
    WAIT     // inserts cin code here ---> no ; req as ; included in the macro definition
    return 0;
}
