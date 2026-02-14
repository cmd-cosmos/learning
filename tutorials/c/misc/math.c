#include <stdio.h>
#include "math_utils.h"

int main()
{
    printf("sum: %d\n", add(2,3));
    printf("global val: %d\n", global_val);

    global_val += 5000;
    
    printf("modified global val: %d\n", global_val);
    
    int global_val = 6000;
    printf("modified global val: %d\n", global_val);

    return 0;
}