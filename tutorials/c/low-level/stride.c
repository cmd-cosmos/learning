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
        array[i] =  (i*5);
    }

    // using different strides to test perf. differneces
    for (int stride = 1; stride <= MAX_STRIDE; stride *= 2)
    {
        // start with a stride of 1, calc sum over the whole array using that stride and measure the time delta
        clock_t start = clock();
        volatile int sum = 0;
        for (size_t i = 0; i < ARRAY_SIZE; i += stride)
        {
            sum += array[i];
        }
        clock_t end = clock();

        double timing = (double)(end - start) / 1000;
        printf("Stride %d --> Time: %.6f seconds\n", stride, timing);
    }

    
    free(array);
    return 0;
}