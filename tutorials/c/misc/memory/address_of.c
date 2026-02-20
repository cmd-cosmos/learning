#include <stdio.h>

int main(void)
{
    int x = 100;
    int y = 200;

    printf("address of x: 0x%o\n", &x);
    printf("address of y: 0x%o\n", &y);

    return 0;
}