#include <stdio.h>

int main(void)
{
    int watchdog = 3;

    for (int i = 0; i < 5; i++)
    {
        if (watchdog == 0)
        {
            puts("SYSTEM RESET");
            break;
        }
        printf("TICK: %d\n", i);
        watchdog--;
    }
    return 0;
}