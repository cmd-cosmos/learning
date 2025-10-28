// endianness --> describes the order in which bytes of a multibyte data type are stored
// little endian machine --> least sign. bit stored first(lowest addr)
// big endian machine --> most sign. bit stored first(lowest addr)

#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    uint32_t num = 0x12345678;
    unsigned char* p = (unsigned char*)&num;

    printf("Mem Repr:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("Byte %d: 0x%02x\n", i, p[i]);
        // 02x <-- format specifier for hex with a min field width of 2
    }

    return 0;
}

/*
little endian machine determined:

Mem Repr:
Byte 0: 0x78
Byte 1: 0x56
Byte 2: 0x34
Byte 3: 0x12

*/
