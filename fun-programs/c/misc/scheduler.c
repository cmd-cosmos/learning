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
    scheduler_t scheduler;
    scheduler_init(&scheduler);

    job_t* job1 = create_job(1, MEDIUM);
    job_t* job2 = create_job(2, LOW);
    job_t* job3 = create_job(3, CRITICAL);
    job_t* job4 = create_job(4, HIGH);
    job_t* job5 = create_job(5, CRITICAL);
    job_t* job6 = create_job(6, LOW);
    job_t* job7 = create_job(7, HIGH);
    job_t* job8 = create_job(8, MEDIUM);

    scheduler_enqueue(&scheduler, job1);
    scheduler_enqueue(&scheduler, job2);
    scheduler_enqueue(&scheduler, job3);
    scheduler_enqueue(&scheduler, job4);
    scheduler_enqueue(&scheduler, job5);
    scheduler_enqueue(&scheduler, job6);
    scheduler_enqueue(&scheduler, job7);
    scheduler_enqueue(&scheduler, job8);

    puts("DISPATCH ORDER: \n");

    job_t* job;
    while((job = scheduler_dequeue(&scheduler)) != NULL)
    {
        printf("RUNNING JOB ID: %2u | PRIORITY: %10s\n", job->id, priority_to_string(job->priority));
        free(job);
    }

    return 0;
}
