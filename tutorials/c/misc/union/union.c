// using unions for effective memory management in case of single var assingment out of a var pool

#include <stdio.h>
#include <string.h>

union Number
{
    int value;
    char value_string[100];
};

typedef union Number Number;

int main(int argc, char* argv[])
{
    #if 0
    Number num;
    num.value = 5;
    strcpy(num.value_string, "Five");

    printf("%d\n", num.value);
    printf("%s\n", num.value_string); // this was written to last thus this is the output
    #endif

    Number num2;
    num2.value = 2;
    strcpy(num2.value_string, "Two");

    for (int i = 0; i < strlen(num2.value_string); i++)
    {
        // loops through unions shared memory space and since the string was the most recent write, it can be read individually
        printf("%c\n", num2.value_string[i]);
    }
    printf("%s\n", num2.value_string);
    /*
    Output:
    T
    w
    o
    Two
    */

    return 0;
}

