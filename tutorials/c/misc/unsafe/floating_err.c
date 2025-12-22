// floating point precision based error

#include <stdio.h>

int main(void)
{
    double sched = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sched += 0.1;
    }
    if (sched == 1.0)
    {
        puts("Vals Match");
    }
    else
    {
        printf("Sched Val: %.10f\n", sched);
        printf("Sched Val: %.15f\n", sched);
        printf("Sched Val: %.20f\n", sched);
        printf("Sched Val: %.25f\n", sched);
    }

    return 0;
}