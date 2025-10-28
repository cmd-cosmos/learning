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
        
        double totElapsed = 0.0;
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
        totElapsed += timing;
        double accesses = (double)ARRAY_SIZE / stride;
        double averageTime =  totElapsed / 100;
        double time_per_access = (averageTime / accesses) * 1e9; // ns per access
        printf("Stride %.4d --> Time: %.5f seconds ---> avg time: %.5fs ---> accesses: %.8d ----> time per access: %.5f ns\n", stride, timing, averageTime, (int)accesses, time_per_access);
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

after some micro optimization to show val access times:
- effect of cache locality visible

Stride 0001 --> Time: 0.26774 seconds ---> avg time: 0.00268s ---> time per access: 0.03990 ns
Stride 0002 --> Time: 0.17949 seconds ---> avg time: 0.00179s ---> time per access: 0.05349 ns
Stride 0004 --> Time: 0.09758 seconds ---> avg time: 0.00098s ---> time per access: 0.05816 ns
Stride 0008 --> Time: 0.05813 seconds ---> avg time: 0.00058s ---> time per access: 0.06930 ns
Stride 0016 --> Time: 0.06071 seconds ---> avg time: 0.00061s ---> time per access: 0.14473 ns
Stride 0032 --> Time: 0.04484 seconds ---> avg time: 0.00045s ---> time per access: 0.21383 ns
Stride 0064 --> Time: 0.02423 seconds ---> avg time: 0.00024s ---> time per access: 0.23110 ns
Stride 0128 --> Time: 0.01401 seconds ---> avg time: 0.00014s ---> time per access: 0.26716 ns
Stride 0256 --> Time: 0.00695 seconds ---> avg time: 0.00007s ---> time per access: 0.26527 ns
Stride 0512 --> Time: 0.00507 seconds ---> avg time: 0.00005s ---> time per access: 0.38692 ns
Stride 1024 --> Time: 0.00485 seconds ---> avg time: 0.00005s ---> time per access: 0.74005 ns

Stride 0001 --> Time: 0.27086 seconds ---> avg time: 0.00271s ---> accesses: 67108864 ----> time per access: 0.04036 ns
Stride 0002 --> Time: 0.14472 seconds ---> avg time: 0.00145s ---> accesses: 33554432 ----> time per access: 0.04313 ns
Stride 0004 --> Time: 0.08689 seconds ---> avg time: 0.00087s ---> accesses: 16777216 ----> time per access: 0.05179 ns
Stride 0008 --> Time: 0.05419 seconds ---> avg time: 0.00054s ---> accesses: 08388608 ----> time per access: 0.06461 ns
Stride 0016 --> Time: 0.04544 seconds ---> avg time: 0.00045s ---> accesses: 04194304 ----> time per access: 0.10835 ns
Stride 0032 --> Time: 0.04112 seconds ---> avg time: 0.00041s ---> accesses: 02097152 ----> time per access: 0.19605 ns
Stride 0064 --> Time: 0.02370 seconds ---> avg time: 0.00024s ---> accesses: 01048576 ----> time per access: 0.22598 ns
Stride 0128 --> Time: 0.01348 seconds ---> avg time: 0.00013s ---> accesses: 00524288 ----> time per access: 0.25703 ns
Stride 0256 --> Time: 0.00792 seconds ---> avg time: 0.00008s ---> accesses: 00262144 ----> time per access: 0.30220 ns
Stride 0512 --> Time: 0.00472 seconds ---> avg time: 0.00005s ---> accesses: 00131072 ----> time per access: 0.35981 ns
Stride 1024 --> Time: 0.00451 seconds ---> avg time: 0.00005s ---> accesses: 00065536 ----> time per access: 0.68855 ns
*/