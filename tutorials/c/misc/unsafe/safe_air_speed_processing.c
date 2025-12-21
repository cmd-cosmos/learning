// MISRA-C style thinking

#include <stdio.h>
#include <stdint.h>

#define SAMPLES 8U
#define DEFAULT_AIRSPEED 250U

int main(void)
{
    uint16_t airSpeed[SAMPLES] = {0};
    uint32_t sum = 0U;
    uint8_t i = 0U;
    
    for (i = 0U; i < SAMPLES; i++)
    {
        airSpeed[i] = DEFAULT_AIRSPEED;
    }

    for (i = 0U; i < SAMPLES; i++)
    {
        sum += airSpeed[i];
    }

    if (SAMPLES == 0U) return 1;

    uint16_t avg = (uint16_t)(sum / SAMPLES);
    printf("avg average: %u knots\n", avg);

    return 0;
}
