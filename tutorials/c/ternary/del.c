#include <stdio.h>

int main()
{
    int n = 0;

    // old Unix way
    // print 1 file deleted if val files == 1 else pluralize
    printf("%d file%s deleted", n, n == 1 ? "" : "s");
    printf("\n");

    n = 1;
    printf("%d file%s deleted", n, n == 1 ? "" : "s");
    printf("\n");


    // newer way

    n = 100;
    printf(n == 1 ? "%d file deleted" : "%d files deleted", n);



    return 0;
}

