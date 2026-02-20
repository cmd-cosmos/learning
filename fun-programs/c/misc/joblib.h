#ifndef JOBLIB_H
#define JOBLIB_H
#include <stdint.h>

typedef enum {
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL
}priority_t;

typedef struct job job_t;

struct job{
    uint32_t id;
    priority_t priority;
    job_t* before;
    job_t* after;
};

#endif