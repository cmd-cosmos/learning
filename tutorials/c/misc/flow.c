// using the goto statement for flow control

#include <stdio.h>

int main()
{
    int inp, i;
    i = 0;

    printf("Enter len of series: ");
    scanf("%d", &inp);

    if(inp < 1)
    {
        printf("ERROR: Invalid Input\n");
        return 1;
    }
    printf("Series: ");

LOOP:
    if (i != inp)
    {
        printf("%d -> ", i++);
        goto LOOP;
    }
    printf("%d", inp);

    return 0;
}

