#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* worker(void* arg)
// function to be ran by each thread
{
    // arg --> takes in a void ptr to the id and cast to int ptr for deref purpose.
    int id = *(int *)arg;
    printf("Response from Thread -> %d\n", id);
    return NULL;
}

int main()
{
    pthread_t t1, t2; // these are handles/identifiers for the threads we create
    int id1 = 1, id2 = 2; // pass ids as integers to worker func

    // the create method takes in a ptr to a pthread type var to store the thread id and uses default settings for thread attr. and the worker function is the target for both threads and a single argument passed to the function which are the ids.
    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    // joins a thread with the main thread.
    // pauses the main thread until the specified thread is done exec.
    // 2nd arg is for return val
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("All threads executed.\n");
    return EXIT_SUCCESS;
}
