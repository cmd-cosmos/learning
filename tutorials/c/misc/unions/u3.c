// ipv4 sample union

#include <stdio.h>
#include <string.h>

typedef union uni1{
    unsigned int addr;
    unsigned char bytes[4];
} ipv4;

int main()
{
    ipv4 address = {0};
    printf("union size: %d\n", sizeof(ipv4));

    // on little endian systems
    address.bytes[0] = 127; // LSB
    address.bytes[1] = 0;
    address.bytes[2] = 0;
    address.bytes[3] = 1;   // MSB

    printf("hex: 0x%x\n",address.addr); // gives hex version of the loopback address
    // 0x0100007f --> 01 MSB = 1, 7f LSB = 127
    
    for (int i = 0; i <=3; i++)
    {
        printf("%u", address.bytes[i]);
        if (i < 3) printf(".");
    }

    return 0;
}