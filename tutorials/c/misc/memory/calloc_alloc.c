#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *array = calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }

    free(array);
    return EXIT_SUCCESS;
}