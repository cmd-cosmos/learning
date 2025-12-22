// ariane 5 bug

#include <stdio.h>
#include <stdint.h>

int main()
{
    double vel = 6500000.0; // too large to fit in a 16 bit location
    int16_t horizontal = (int16_t)vel; // overflow
    printf("Horizontal Velocity: %d\n", horizontal);

    return 0;
}
