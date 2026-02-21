#include <stdio.h>
#include <stdlib.h>

void ptr_arithmetic()
{
    int arr[5] = {1,2,3,4,5};

    printf("base addr arr = %p\n", (void*)arr);
    printf("addr &addr[0] = %p\n", (void*)&arr[0]);
    printf("using &arr    = %p\n", (void*)&arr);

    // arr expands to &addr[0]
    int* ptr = arr;

    for (int i = 0; i < 5; i++) {
        printf("*(p + %d) = %d | address = %p\n", i, *(ptr+i), (void*)(ptr+i));
    }
}

int main(void)
{
    ptr_arithmetic();
    return EXIT_SUCCESS;
}