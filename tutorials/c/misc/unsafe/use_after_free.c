// using vars after freeing mem.

#include <stdio.h>
#include <stdlib.h>

void safeUse()
{
    printf("executing safe routine:\n");
    int *p = malloc(sizeof(int));
    if (!p) return;

    *p = 1000;
    printf("%d\n", *p);

    free(p);
    p = NULL; // poisoning the malloc ptr
    printf("exiting safe routine\n");

}

void unsafe()
{
    printf("executing unsafe routine:\n");
    int *p = malloc(sizeof(int));
    *p = 1000;

    free(p);
    printf("%d\n", *p); // use after 
    // memory leak: -2038919296
    printf("exiting unsafe routine\n");
}

int main()
{
    safeUse();
    printf('\n');
    unsafe();

    return 0;    
}

