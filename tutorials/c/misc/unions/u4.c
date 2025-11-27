// hardware specific sample union

#include <stdio.h>
#include <string.h>

typedef union{
    struct
    {   
        unsigned char control_bit;
        unsigned char direction_bit;
        unsigned char parity_bit;
        unsigned char stop_bit;
    };
    unsigned int reg;
} HWRegister;

int main()
{
    HWRegister gpio;
    gpio.reg = 0x01010101;

    printf("%x\n", gpio.stop_bit);

    return 0;
}