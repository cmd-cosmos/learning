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


    if (*c)
    {
        printf("little endian\n");
    }
    else{
        printf("big endian\n");
    }

    return 0;
}

