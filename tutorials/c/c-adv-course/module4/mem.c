#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int arr[] = {4,2,9,1};

    qsort(arr, 4, sizeof(int), compare);

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    } printf("\n");

    return 0;
}