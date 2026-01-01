#include <windows.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t* mem = (uint8_t *)VirtualAlloc(
        NULL,
        64,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READWRITE
    );

    if (!mem) {
        return 1;
    }

    for (int i = 0; i < 64; i++)
    {
        *(mem + i) = (uint8_t)(i ^ 0xAA);
    }

    // freeing allocated memory
    VirtualFree(mem, 0, MEM_RELEASE);

    return 0;
}
