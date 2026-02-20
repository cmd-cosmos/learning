#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

void scheduler_init(scheduler_t* scheduler)
{
    for (int i = 0; i < 4; i++)
    {
        scheduler->queue[i].head = NULL;
        scheduler->queue[i].tail = NULL;
    }
}

void scheduler_enqueue(scheduler_t* scheduler, job_t* job)
{
    
}

job_t* scheduler_dequeue(scheduler_t* scheduler)
{
    
}

int main(void)
{
    return 0;
}
