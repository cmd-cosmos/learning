#include <stdio.h>

int main(void)
{
    int x = 100;
    int y = 200;

    printf("address of x: 0x%o\n", &x);
    printf("address of y: 0x%o\n", &y);

    // printing addr of the var - alternate
    // when printing addresses using the %p specifier --> it is recommended to cast to (void*) as the %p specifier expects a void ptr
    printf("addr of y: 0x%p\n", &y);
    printf("addr of y: 0x%p\n", (void*)&y);

    int num = 7;
    int* ptr = &num;
    int** ptr_ptr = &ptr;

    printf("ptr address: %p\n", (void*)&ptr);
    printf("ptr_ptr address: %p\n", (void*)&ptr_ptr);
    printf("ptr_ptr points to: %p\n", (void*)ptr_ptr);


    return 0;
}