#include <stdio.h>

int main(void)
{
    double s1 = 101.2;
    double s2 = 100.4;
    double sBroken = 500.2;

    double avg = (s1 + s2 + sBroken) / 3.0;

    if (sBroken > 200.0)
    {
        avg = (s1 + s2) / 2.0;
    }

    printf("fused vals: %.2f\n", avg);
    return 0;
}
