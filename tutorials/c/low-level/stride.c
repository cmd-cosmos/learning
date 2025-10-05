// array stride benchmarking to see cache locality in cases of smaller arrays vs cache misses in larger arrays

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// store approximately 64 million ints
// array will utilize approx 268 MB
// to test the cache line use stride to jump over arrays
// large stride would avoid resuse of cache lines ---> perf. hit

#define ARRAY_SIZE (64*1024*1024) 
#define MAX_STRIDE 1024   

int main()
{
    int *array = malloc(sizeof(int) * ARRAY_SIZE);
    if (!array)
    {
        perror("malloc failed");
        return 1;
    }

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {

    }
    

    return 0;
}