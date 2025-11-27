// union vs struct

#include <stdio.h>

// total size = 20 bytes
typedef struct str1{
    int id;
    float val;
    char arr[12];
} struct_t;

// total size = 12 bytes
typedef union uni1{
    int id;
    float val;
    char arr[12];
} union_t;

int main()
{
    struct_t structure1;
    union_t union1;

    printf("unions size: %d\n", sizeof(union_t));
    printf("struct size: %d\n", sizeof(struct_t));

    return 0;
}