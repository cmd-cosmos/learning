#include <stdio.h>
#include <pthread.h>

void* worker(void* arg)
{
    printf("Worker Thread\n");
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, worker, NULL);
    pthread_join(thread, NULL);
    
    return 0;
}