#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

sem_t semaphore;

void *thread_function(void *arg) {
    sem_wait(&semaphore); // Locks (or waits) for available access
    printf("Thread %ld is accessing the resource.\n", (long)arg);
    // Simulate some work
    sleep(2);
    printf("Thread %ld is done using the resource.\n", (long)arg);
    sem_post(&semaphore); // Unlocks, allowing another thread to access
    return NULL;
}

int main() {
    pthread_t threads[10000];
    sem_init(&semaphore, 0, 10000); // Allows up to 10000 threads at a time

    for (long i = 0; i < 10000; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *)i);
    }

    for (int i = 0; i < 10000; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); // Cleanup
    return 0;
}
