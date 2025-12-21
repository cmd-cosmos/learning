// ring buffer data logger working on the power of 2 optimization to implement bound safe logic

#include <stdio.h>
#include <stdint.h>

// buffer size must be a power of 2
#define BUF_SIZE 8

int main()
{
    int16_t buffer[BUF_SIZE] = {0};
    uint8_t writeIndex = 0;

    for (int16_t i = 100; i < 116; i++)
    {
        buffer[writeIndex] = i;
        // wrap and overwrite data after passing the 7th index as the buffer can only hold 8 vals at a time
        writeIndex = (writeIndex + 1) & (BUF_SIZE - 1);
    }

    printf("ring buffer vals:\n");
    for (uint8_t i = 0; i < BUF_SIZE; i++)
    {
        printf("[%u] = %d\n", i, buffer[i]);
    }

    return 0;
}
