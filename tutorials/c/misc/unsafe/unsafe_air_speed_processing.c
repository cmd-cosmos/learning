#include <stdio.h>
#include <stdint.h>

#define SAMPLES 8

int main()
{
    uint16_t airSpeed[SAMPLES];
    uint32_t sum = 0;

    for (uint8_t i = 0; i <= SAMPLES; i++)
    {
        airSpeed[i] = 250; // writing out of bounds at index 8
    }

    for (uint8_t i = 0; i < SAMPLES; i++)
    {
        sum += airSpeed[i]; // in bounds array access
    }

    uint16_t avg = sum / SAMPLES;
    printf("avg. arispeed = %u knots\n", avg);

    return 0;
}