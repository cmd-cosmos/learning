/*
static vars:
static duration of variables ---> lifetime = enitre execution timeline
scope and duration are 2 separate terms ---> scope could be limited but memory retained till end of execution
*/

#include <stdio.h>
#include <stdlib.h>

void Counter();

int main()
{
    // since count var in the local scope of the counter function is marked static, it retains value after the stack id popped when the function returns after the 1st call
    Counter(); // 1
    Counter(); // 2
    Counter(); // 3
    Counter(); // 4
    // final val of count will be 4
    return 0;
}

void Counter()
{
    static int count;
    count++;
    printf("Count = %d\n", count);
}