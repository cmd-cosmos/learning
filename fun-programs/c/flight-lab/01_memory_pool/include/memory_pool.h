// header guards to ensure single inclusion of the header file 
// only include the memory pool h file in the src code if it is not already included
#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stddef.h> // includes size_t which is unsigned integer type specially for size representations
#include <stdint.h> // provides fixed width integer types

// compile time constants
#define MEMORY_POOL_BLOCK_SIZE 64 // every allocation gives the user 65 bytes
#define MEMORY_POOL_BLOCK_COUNT 128 // total blocks in the pool

// total memory allocated = 128 blocks of 64 bytes each
// total memory allocated = 128 x 64 = 8192 bytes = roughly 8 kBytes

typedef struct
{
    uint8_t memory[MEMORY_POOL_BLOCK_SIZE * MEMORY_POOL_BLOCK_COUNT];
    uint8_t used[MEMORY_POOL_BLOCK_COUNT]; // 
    size_t used_blocks;

} MemoryPool;


#endif