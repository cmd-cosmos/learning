#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char* base;
    size_t size, used;
} Arena;


int main(void)
{
    Arena a;
    a.size = 1024;
    a.used = 0;
    a.base = malloc(a.size);

    int* x = (int *)(a.base + a.used);
    a.used += sizeof(int);
    *x = 100;

    double* y  = (double *)(a.base + a.used);
    a.used += sizeof(double);
    *y = 3.1415;

    printf("%d, %.2f\n", *x, *y);
    free(a.base);

    return EXIT_SUCCESS;
}