// accessing a single bit from memory
// reference: https://www.youtube.com/watch?v=ciio80nkjB8&list=TLPQMTYwOTIwMjVGlaw20gWpFg&index=2
// access single bits within a bitfield or a bitvector

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <windows.h>

#define BITVAL(X, N) ((X) >> (N) & 0x1)

// defining certain test bits ---> hex to binary!!!
#define SYSTEM 0x0  // 0000 0000
#define LAUNCH 0x1  // 0000 0001
#define FAULT  0x2  // 0000 0010
#define GSE    0x4  // 0000 0100
#define STAGE1 0x8  // 0000 1000
#define STAGE2 0x10 // 0001 0000

int main()
{
    uint32_t x = 42; // 0010 1010
    printf("x =  %d\n", x);

    printf("bit 0 of x = %d\n", BITVAL(x, 0));
    printf("bit 1 of x = %d\n", BITVAL(x, 1));
    printf("bit 2 of x = %d\n", BITVAL(x, 2));
    printf("bit 3 of x = %d\n", BITVAL(x, 3));

    // extracting bits from the bit stream ---> 4 bytes ---> 32 bits
    int numbits = sizeof(x) * 8;
    for (int i = 0; i < numbits; i++)
    {
        printf("bit %d of x = %d\n", i, BITVAL(x, i));
    }
    printf("bitstream: ");
    for (int i = 0; i < numbits; i++)
    {
        printf("%d", BITVAL(x,numbits - i - 1));
    }printf("\n");

    // if logical not (not x and LAUNCH)
    // !x ==> 0 ===> because !42 = 0
    //   0000 0000
    // & 0000 0001
    // ------------
    //   0000 0000
    // !0 = 1 ---> if (1) ---> true

    // NOTE
    // ! ---> logical not
    // ~ ---> bitwise not

    if (!(!x & LAUNCH))
    {
        printf("GO FOR LAUNCH\n");
    }
    
}

