// accessing a single bit from memory
// reference: https://www.youtube.com/watch?v=ciio80nkjB8&list=TLPQMTYwOTIwMjVGlaw20gWpFg&index=2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <windows.h>

#define BITVAL(X, N) ((X) >> (N) & 0x1)

int main()
{
    uint32_t x = 42; // 0010 1010
    printf("x =  %d\n", x);

    printf("bit 0 of x = %d\n", BITVAL(x, 0));
    printf("bit 1 of x = %d\n", BITVAL(x, 1));
    printf("bit 2 of x = %d\n", BITVAL(x, 2));
    printf("bit 3 of x = %d\n", BITVAL(x, 3));

}

