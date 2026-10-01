// imagine a rockets 8 bit status register -> where each bit is a separate T/F flag. packing flags like this saves bandwidth in a real aerospace application and simulates how real hardware registers work

#include <stdio.h>
#include <stdint.h>

/*
1U => unsigned int with a val of 1 => 4 bytes on most x86-64, ARM systems
1U in binary: 0000 0000 | 0000 0000 | 0000 0000 | 0000 0001
*/

/*
patterns:
=> set:     x |= MASK
=> clear:   x &= ~MASK
=> toggle:  x ^= MASK
=> test:    x  & MASK
*/

// each flag is a bit, built using a left shift
#define FLAG_ARMED          (1U << 0) // 0000 0001
#define FLAG_IGNITION       (1U << 1) // 0000 0010
#define FLAG_LIFTOFF        (1U << 2) // 0000 0100
#define FLAG_STAGE_SEP      (1U << 3) // 0000 1000
#define FLAG_LAND_BURN      (1U << 4) // 0001 0000
#define FLAG_FAULT          (1U << 7) // 1000 0000

// shifting by x bits  -> x 0s after the '1' bit

static void print_bits(uint8_t v) {
    for (int i = 7; i >= 0; i--) {
        putchar((v >> i) & 1U ? '1' : '0');
    }
}

int main(void) {
    uint8_t status = 0; // clear flags

    status |= FLAG_ARMED; // set bit 
    status |= FLAG_IGNITION;
    printf("after arm and ignite: "); print_bits(status); putchar('\n');

    if (status & FLAG_IGNITION) {
        printf("ignition flag set\n");
    }

    status &= ~FLAG_ARMED; // clear a bit -> not oper
    printf("after disarm: "); print_bits(status); putchar('\n');

    status ^= FLAG_FAULT; // toggle new bit
    printf("after fault toggle: "); print_bits(status); putchar('\n');

    return 0;
}