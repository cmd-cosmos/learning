#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 0; i < 16; i += 4) {
        printf("RELOOPING: i = %4d | SUM: %4d\n", i, sum);
        sum += i;
        printf("sum: %4d\n", sum);
        sum += i + 1;
        printf("sum: %4d\n", sum);
        sum += i + 2;
        printf("sum: %4d\n", sum);
        sum += i + 3;
        printf("sum: %4d\n", sum);
    }

    printf("\n\nsum: %d\n", sum);
}