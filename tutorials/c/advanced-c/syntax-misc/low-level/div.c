// optimizing division in some conditions at a low level
// division is complicated in terms of involvement of decisions
// however division by a power of 2 is just a bit shift

#include <stdio.h>

int main()
{
    int a,b;
    double res, res_opt;

    a = 8;
    res = a / 2.0;
    printf("%f\n", res);

    // this bitwise operation only behaves predictably for positive ints
    b = 8;
    res_opt = b >> 1; // bitwise shift for division by 2
    printf("%f\n", res_opt);

    // 8 ----> 0000 1000 ---> div by 2 get 4 ----> 1 right shift for the bits will lead to the result
    // 4 ----> 0000 0100 <---- 1 bitwise shift to the right

    return 0;
}
