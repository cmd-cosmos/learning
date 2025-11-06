// simulating the bounded buffer problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUM 8

sem_t semaphoreEmpty;
sem_t semaphoreFull;

pthread_mutex_t mutexBuffer;

int buffer[10];
int count = 0;

void* producer(void* args)
{
    while (1)
    {
        // produce
        int x = rand() % 100;
        sleep(1);

        sem_wait(&semaphoreEmpty);
        
        pthread_mutex_lock(&mutexBuffer);
        // critical section
        buffer[count] = x;
        count++;
        pthread_mutex_unlock(&mutexBuffer);
        
        sem_post(&semaphoreFull);
    }
}

void* consumer(void* args)
{
    while (1)
    {
        int y;

        sem_wait(&semaphoreFull);
        pthread_mutex_lock(&mutexBuffer);
        y = buffer[count - 1];
        count--;
        pthread_mutex_unlock(&mutexBuffer);

        sem_post(&semaphoreEmpty);

        printf("Consumed: %d\n", y);
        sleep(1);
    }
    
}

int main()
{
    srand(time(NULL));
    pthread_t th[THREAD_NUM];

    pthread_mutex_init(&mutexBuffer, NULL);
    sem_init(&semaphoreEmpty, 0, 10);
    sem_init(&semaphoreFull, 0, 0);
    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (i > 0)
        {
            if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
            {
                perror("failed to create thread.");
            }
            else
            {
                if (pthread_create(&th[i], NULL, &consumer, NULL) != 0)
                {
                    perror("failed to creatre thread.");
                }
            }
        }
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("failed to join thread.");
        }
    }
    sem_destroy(&semaphoreEmpty);
    sem_destroy(&semaphoreFull);
    pthread_mutex_destroy(&mutexBuffer);

    return 0;
}

