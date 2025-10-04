#include <stdio.h>

void oldPluralizer(int n)
{
    printf("%d file%s deleted", n, n == 1 ? "" : "s");
    printf("\n");
}

void newPluralizer(int n)
{
    printf(n == 1 ? "%d file deleted" : "%d files deleted", n);
    printf("\n");
}

int main()
{
    oldPluralizer(100);
    oldPluralizer(1);
    oldPluralizer(0);
    printf("\n");
    newPluralizer(0);
    newPluralizer(23);
    newPluralizer(1);


    // old Unix way
    // print 1 file deleted if val files == 1 else pluralize
    // printf("%d file%s deleted", n, n == 1 ? "" : "s");
    // printf("\n");



    // n = 1;
    // printf("%d file%s deleted", n, n == 1 ? "" : "s");
    // printf("\n");

    // // newer way

    // n = 100;
    // printf(n == 1 ? "%d file deleted" : "%d files deleted", n);



    return 0;
}

