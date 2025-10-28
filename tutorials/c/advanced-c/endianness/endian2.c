// runtime detection of endianness
/*
int x = 1 ---> 1 = 0000 0000 0000 0000 0000 0000 0000 0001 binary in mem
                   00 00 00 01 in hex
                   arrangement of theses bytes in mem is dependent on endianness 
given ==> memory ==> low -> high addresses
little endian will store the LSB in the lower addr.

mem layout: low addr ---------> higher addr
little -      [LSB]               [MSB]
big    -      [MSB]               [LSB]
hex ==> 0x00000001
little endian --> 01 00 00 00 
big endian    --> 00 00 00 01
*/ 

#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    unsigned int x = 1;  // 0x00000001
    char* c = (char*)&x; // inspect the first byte

    for (int i = 0; i < sizeof(x); i++)
    {
        printf("Byte %d: 0x%02x\n", i, c[i]);
    }

    if (*c)
    {
        printf("little endian\n");
    }
    else{
        printf("big endian\n");
    }

    unsigned int y = 0x12345678;
    
    // 0x78 ---> 7*16^1 + 8*16^0 = 7*16 + 8 = 120 in decimal
    if (*(char*)&y == 0x78 && *(char*)&y == 120)         
    {
        printf("\nlittle endian\n");
        printf("val at first byte: %02x", *(char*)&y);
    }
    else
    {
        printf("\nbig endian\n");
    }

    return 0;
}

/*

output:

Byte 0: 0x01 <---- LSB stored in byte 0
Byte 1: 0x00
Byte 2: 0x00
Byte 3: 0x00
little endian

*/

