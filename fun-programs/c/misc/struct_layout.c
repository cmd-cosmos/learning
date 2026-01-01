#include <stdio.h>
#include <stdint.h>

struct Unpacked {
    uint8_t  a; // 1
    uint32_t b; // 4
    uint16_t c; // 2
};

#pragma pack(push, 1)
struct Optimized {
    uint8_t  a; // 1
    uint32_t b; // 4
    uint16_t c; // 2
};
#pragma pack(pop)

int main(void)
{
    printf("size of unpacked struct : %zu\n", sizeof(struct Unpacked));
    printf("size of packed struct   : %zu\n", sizeof(struct Optimized));

    return 0;
}