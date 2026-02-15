#include <stdio.h>
#include <stdint.h>

typedef struct Packet {
    uint8_t type : 3;   // use 3 bits out of a byte
    uint8_t flag : 1;   // use 1 bit
    uint8_t length : 4; // use 4 bits
} packet_t;

int main(void)
{
    packet_t p = { 3, 0, 8 };
    packet_t p2 = { 1, 1, 15 };
    printf("Packet | type = %2d | flag = %2d | length = %2d\n", p.type, p.flag, p.length);
    printf("Packet | type = %2d | flag = %2d | length = %2d\n", p2.type, p2.flag, p2.length);

    return 0;
}