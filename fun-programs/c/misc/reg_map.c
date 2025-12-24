#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint8_t ready : 1;
    uint8_t error : 1;
    uint8_t mode  : 2;
    uint8_t       : 1;
} Status;

int main(void)
{
    Status s = {1, 0, 1};
    printf("ready = %d mode = %d error = %d \n", s.ready, s.mode, s.error);

    return 0;
}