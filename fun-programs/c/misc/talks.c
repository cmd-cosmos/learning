// mem mapped register

#include <stdio.h>
#include <stdint.h>

#define REGISTER_STATUS (*(volatile uint32_t*)0x40000000)

int main(void)
{
    uint32_t fake_reg = 0x1;
    volatile uint32_t* reg = &fake_reg;

    if (*reg &0x1)
    {
        puts("SYSTEM READY");
    }
    return 0;
}