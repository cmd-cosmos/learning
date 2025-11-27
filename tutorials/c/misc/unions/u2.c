// shared memspace in unions

#include <stdio.h>
#include <string.h>

typedef union uni1{
    int id;
    float val;
    char arr[12];
} union_t;

int main()
{
    union_t union1 = {.val = 4.56f};
    
    printf("unions size: %d\n", sizeof(union_t));
    printf("%f\n", union1.val);

    // shows the float version of the string
    strcpy(union1.arr, "Batman");
    printf("%f", union1.val);

    return 0;
}