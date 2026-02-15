#include <stdio.h>
#include <stdint.h>

int main()
{
    int x = 0x12345678;
    uint8_t* byte_ptr = (uint8_t*)&x;

    for (size_t i = 0; i < sizeof(int); i++)
    {
        printf("byte %zu: 0x%02X\n", i, byte_ptr[i]);
    }
}