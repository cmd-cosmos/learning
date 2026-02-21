#include <stdio.h>
#include <stdlib.h>

void ptr_arithmetic()
{
    int arr[5] = {1,2,3,4,5};

    printf("base addr arr = %p\n", (void*)arr);
    printf("addr &addr[0] = %p\n", (void*)&arr[0]);
    printf("using &arr    = %p\n", (void*)&arr);
}

int main(void)
{
    ptr_arithmetic();
    return EXIT_SUCCESS;
}