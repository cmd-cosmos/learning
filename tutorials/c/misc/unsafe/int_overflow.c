#include <stdlib.h>
#include <stdio.h>

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

int main()
{
    unsafe_alloc(0xFFFFFFFFFFF);

    return 0;
}