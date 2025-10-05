// optimizing division in some conditions at a low level
// division is complicated in terms of involvement of decisions
// however division by a power of 2 is just a bit shift

#include <stdio.h>

int main()
{
    int a,b;
    double res, res_opt;

    a = 8;
    res = a / 2;
    printf("%f\n", res);

    b = 8;
    res_opt = b >> 1; // bitwise shift for division by 2
    printf("%f\n", res_opt);

    return 0;
}
