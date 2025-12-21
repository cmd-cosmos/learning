// altitude change calculation 
// signed vs unsigned bugs 
// goal: descend by a 100m from 1000m altitude to 900m altitude.
// issue: since we deal with unsigned int, the difference is treated as +ve climb instead of descend.

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t currAltitude   = 1000U;
    uint16_t targetAltitude = 900U;

    uint16_t delta = targetAltitude - currAltitude;
    printf("alt diff (raw): %u\n", delta); 

    if (delta > 100U)
    {
        printf("climb delta out of instrumentation limits.\n");
    }
    else if (delta < -100)
    {
        printf("descent delta out of instrumentation limits.\n");
    }
}

/*
unsafe output:
alt diff (raw): 65436
climb delta out of instrumentation limits.
*/
