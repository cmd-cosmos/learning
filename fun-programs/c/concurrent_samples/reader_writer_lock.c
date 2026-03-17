#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void* reader(void* arg)
{
    pthread_rwlock_rdlock(&rwlock);
    printf("Reader %ld is reading the shared resource\n", (long)arg);
    sleep(1);
    printf("Reader %ld finished reading the shared resource\n", (long)arg);
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

void* writer(void* arg)
{
    pthread_rwlock_wrlock(&rwlock);
    printf("Writer %ld is writing to the shared resource\n", (long)arg);
    sleep(2);
    printf("Writer %ld finished writing to the shared resource\n", (long)arg);
    return NULL;
}

int main(void)
{
    return 0;
}
