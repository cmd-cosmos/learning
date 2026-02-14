#include <stdio.h>
#include "counter.h"

void increment()
{
    static int count = 0;
    count++;
    printf("count: %d\n", count);
}