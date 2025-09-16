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
    Number num;
    num.value = 5;
    strcpy(num.value_string, "Five");

    printf("%d\n", num.value);
    printf("%s\n", num.value_string); // this was written to last thus this is the output

    return 0;
}

