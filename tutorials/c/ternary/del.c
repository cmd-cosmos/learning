#include <stdio.h>

int main()
{
    int n = 0;

    // print 1 file deleted if val files == 1 else pluralize
    printf("%d file%s deleted", n, n == 1 ? "" : "s");
    printf("\n");

    n = 1;
    printf("%d file%s deleted", n, n == 1 ? "" : "s");


    return 0;
}

