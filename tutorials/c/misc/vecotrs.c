#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t x;
    uint32_t y;
} vector_t;

int main(void)
{
    vector_t vec = { 1,10 };
    printf("%d\n",vec.x);
    printf("%d\n",vec.y);
    printf("sizeof struct vector = %zu bytes\n", sizeof(vector_t));
    printf("sizeof vec = %zu bytes\n", sizeof(vec));

    return 0;
}