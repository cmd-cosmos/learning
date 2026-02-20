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
    queue_t* q = &scheduler->queue[job->priority];

    job->before = NULL;
    job->after = NULL;

    if (q->tail == NULL)
    {
        q->head = job;
        q->tail = job;
    }
    else
    {
        q->tail->after = job;
        job->before = q->tail;
        q->tail = job;
    }
}

job_t* scheduler_dequeue(scheduler_t* scheduler)
{
    for (int priority = CRITICAL; priority >= LOW; priority--)
    {
        queue_t* q = &scheduler->queue[priority];

        if (q->head != NULL)
        {
            job_t* job = q->head;
            q->head = job->after;

            if (q->head != NULL)
            {
                q->head->before = NULL;
            }
            else
            {
                q->tail = NULL;
            }
            job->after = NULL;
            job->before = NULL;

            return job;
        }
    }
    return NULL;
}

const char* priority_to_string(priority_t priority)
{
    switch (priority)
    {
    case LOW:
        return "LOW";
    case MEDIUM:
        return "MEDIUM";   
    case HIGH:
        return "HIGH";
    case CRITICAL:
        return "CRITICAL";  
    default:
        return "NULL";
    }
}

job_t* create_job(uint32_t id, priority_t priority)
{
    job_t* job = malloc(sizeof(job_t));
    if (!job)
        return NULL;
    job->id = id;
    job->priority = priority;
    job->before = NULL;
    job->after = NULL;

    return job;
}

int main(void)
{
    return 0;
}
