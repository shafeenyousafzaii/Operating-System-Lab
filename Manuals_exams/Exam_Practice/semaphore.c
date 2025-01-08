#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>  // For sleep()

sem_t semaphore;

void* threadfunction(void* arg) {
    sem_wait(&semaphore); // "Locks" the semaphore, decreasing count by 1
    printf("Thread %ld is entering the critical section.\n", (long)arg);
    
    // Simulate some work
    sleep(1);

    printf("Thread %ld is leaving the critical section. \n", (long)arg);
    sem_post(&semaphore); // "Unlocks" the semaphore, increasing count by 1
    
    return NULL;
}

int main() {
    pthread_t threads[3];
    sem_init(&semaphore, 0, 1); // Initialize semaphore with 1 (binary semaphore)
    
    for(long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, threadfunction, (void*)i);
    }
    
    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore); // Cleanup
    return 0;
}

