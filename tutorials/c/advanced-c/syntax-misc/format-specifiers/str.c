#include <stdio.h>

/*
%s --> requires a char* as input, otherwise leads to mem. corruption
   --> compiler does not perform this check after the first format specifier and thus manual enforcement and vigilance required
*/

int main() {
    
    char* str = "schedule";
    printf("%s\n", str);        // prints ---> schedule
    printf("%c\n", *str);       // prints ---> s
    
    char** ptr = &str;
    printf("%p\n", ptr);        // prints ---> address of the str ptr
    printf("%s\n", *(ptr));     // prints ---> schedule
    printf("%c\n", **ptr);      // prints ---> s

    return 0;
}