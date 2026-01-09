#include <stdio.h>

#define EXIT_SUCCESS 0;

int main(void)
{
    int a = 5, b = 3, res = 0;

    asm ("addl %%ebx, %%eax;"
            : "=a" (res)
            : "a" (a), "b" (b));
    
    printf("asm out: %d + %d = %d\n", a, b, res);
    return EXIT_SUCCESS;
}