#include <stdio.h>
#include <math.h>
#include <fenv.h>

#pragma STDC FENV_ACCESS ON

int main()
{
    double x = 0.1;
    double y = 0.2;

    printf("0.1 + 0.2 = %.20f\n", x+y);

    if (isnan(NAN))
    {
        printf("NaN detected\n");
    }

    fesetround(FE_DOWNWARD);
    printf("rounded down: %.2f\n", 3.14159);

    return 0;
}
