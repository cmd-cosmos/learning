#include <stdio.h>

void bufferOverflow()
{
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i <= 5; i++) // accessing 5th index when arr ends at idx 4
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

int main()
{
    bufferOverflow();
    return 0;
}