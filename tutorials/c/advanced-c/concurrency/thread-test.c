#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* worker(void* arg)
{
    int id = *(int *)arg;
    printf("Response from Thread -> %d\n", id);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("All threads executed.\n");
    return EXIT_SUCCESS;
}
