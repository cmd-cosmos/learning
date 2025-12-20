#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void unsafe_alloc(size_t count)
{
    int* arr = malloc(count * sizeof(int)); // chances to overflow
    if (!arr)
    {
        printf("Overflow --> Not Allocated\n");
        return;
    }
    arr[count-1] = 100;
    free(arr);
}

void safe_alloc(size_t count)
{
    if (count > SIZE_MAX / sizeof(int))
    {
        printf("Validation failed in comparision to SIZE_MAX.\n");
        return;
    }
    printf("Validation Successful => Allocating Memory\n");
        
    int* arr = malloc(count * sizeof(int)); // chances to overflow
    if (!arr)
    {
        printf("Overflow --> Not Allocated\n");
        return;
    }
    arr[count-1] = 100;
    free(arr);
}


int main()
{
    // unsafe_alloc(0xFFFFFFFFFFF);
    safe_alloc(0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFF);
    safe_alloc(0xFFFFFFFFFFFFF);
    return 0;
}