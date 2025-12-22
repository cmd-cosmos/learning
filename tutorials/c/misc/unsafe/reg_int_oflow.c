// classic aerospace bug caused by unusual sensor spikes and unconditioned summing

#include <stdio.h>
#include <stdio.h>


int main()
{
    int alt = 10000;
    int spikedSensorValue = 1000000000; // climb
    alt += spikedSensorValue; // overflow

    printf("Altitude Reading: %d\n", alt);

    return 0;
}

