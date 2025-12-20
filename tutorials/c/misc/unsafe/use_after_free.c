// using vars after freeing mem.

#include <stdio.h>
#include <stdlib.h>

void safeUse()
{
    int *p = malloc(sizeof(int));
    if (!p) return;

    *p = 1000;
    printf("%d\n", *p);

    free(p);
    p = NULL; // poisoning the malloc ptr

}

void unsafe()
{
    int *p = malloc(sizeof(int));
    *p = 1000;

    free(p);
    printf("%d\n", *p); // use after 
    // memory leak: -2038919296
}

int main()
{
    safeUse();
    unsafe();

    return 0;    
}

