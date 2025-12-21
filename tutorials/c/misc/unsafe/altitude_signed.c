// altitude change calculation 
// signed vs unsigned bugs 
// goal: descend by a 100m from 1000m altitude to 900m altitude.
// issue: since we deal with unsigned int, the difference is treated as +ve climb instead of descend.

#include <stdio.h>
#include <string.h>
#include <stdint.h>

void safeAltDiff()
{
    uint16_t currAltitude   = 1000U;
    uint16_t targetAltitude = 900U;

    uint16_t delta = targetAltitude - currAltitude;
    
    int32_t safeDiff = (int32_t)targetAltitude - (int32_t)currAltitude;
    printf("safe alt diff = %ld\n", (long)safeDiff);

    if (safeDiff >= -100 && safeDiff <= 0)
    {
        printf("descent rate within safe range.\n");
        printf("proceeding with auto descent procedure.\n");
    }
}

void unsafeAltDiff()
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

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "--safe") == 0)
    {
        safeAltDiff();
    }
    else if (strcmp(argv[1], "--unsafe") == 0)
    {
        unsafeAltDiff();
    }

    return 0;
}

/*
unsafe output:
alt diff (raw): 65436
climb delta out of instrumentation limits.
*/
