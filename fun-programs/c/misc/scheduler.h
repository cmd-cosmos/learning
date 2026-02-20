#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "joblib.h"

typedef struct
{
    job_t* head;
    job_t* tail;
} queue_t;

typedef struct
{
    // 4 queues for 4 diff priorities
    queue_t queue[4];
} scheduler_t;

void scheduler_init(scheduler_t* scheduler);
void scheduler_enqueue(scheduler_t* scheduler, job_t* job);
job_t* scheduler_dequeue(scheduler_t* scheduler);

#endif  