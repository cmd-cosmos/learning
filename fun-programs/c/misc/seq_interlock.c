// command sequence interlock 

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void)
{
    int armedCMD = 0;
    int fireCMD = 1;

    if (!armedCMD && fireCMD)
    {
        puts("SYS UNARMED - REJECT FIRE");
    }

    armedCMD = 1;
    if (armedCMD && fireCMD)
    {
        puts("SYS ARMED - FIRE CMD SENT");
    }
    return EXIT_SUCCESS;
}