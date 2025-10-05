// array stride benchmarking to see cache locality in cases of smaller arrays vs cache misses in larger arrays
// ref: https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-large_integer-r1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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

    // using win api to get query performance metrics
    LARGE_INTEGER frequency;
    QueryPerformanceCounter(&frequency);

    // using different strides to test perf. differneces
    for (int stride = 1; stride <= MAX_STRIDE; stride *= 2)
    {
        // start with a stride of 1, calc sum over the whole array using that stride and measure the time delta
        // clock_t start = clock();

        LARGE_INTEGER start, end;
        QueryPerformanceCounter(&start);

        volatile int sum = 0;
        for (size_t i = 0; i < ARRAY_SIZE; i += stride)
        {
            sum += array[i];
        }
        QueryPerformanceCounter(&end);

        // timing in nanoseconds as queryperfcounter is very high resolution
        double timing = ((double)(end.QuadPart - start.QuadPart) / frequency.QuadPart)*1e6;
        printf("Stride %d --> Time: %.10f seconds\n", stride, timing);
    }

    
    free(array);
    return 0;
}

/*
results: mainly due to size of array, shows cache locality but skipping nums is faster so affects performance due to that 
Stride 1 --> Time: 0.2772540210 seconds
Stride 2 --> Time: 0.1515511932 seconds
Stride 4 --> Time: 0.0907983705 seconds
Stride 8 --> Time: 0.0596475816 seconds
Stride 16 --> Time: 0.0454376637 seconds
Stride 32 --> Time: 0.0439628274 seconds
Stride 64 --> Time: 0.0247876782 seconds
Stride 128 --> Time: 0.0159141056 seconds
Stride 256 --> Time: 0.0072471012 seconds
Stride 512 --> Time: 0.0049229557 seconds
Stride 1024 --> Time: 0.0038197397 seconds <----- worst cache locality but fast computation as skipping nearly 1000 vals per computation
*/