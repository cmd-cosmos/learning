#include <stdio.h>

char bss_buffer[8];
char data_buffer[8] = "ABC";

int main(void)
{
    printf("bss: %p\n", (void*)bss_buffer);
    printf("data: %p\n", (void*)data_buffer);
    return 0;
}

// data placed before bss by the linker
// relative addresses when compared show byte difference
