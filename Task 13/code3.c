#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

sem_t semaphore;

void* thread1_function(void* arg) {
    printf("Thread 1: Waiting for signal...\n");
    sem_wait(&semaphore); // Wait until sem_post is called
    printf("Thread 1: Received signal, proceeding...\n");
    return NULL;
}

void* thread2_function(void* arg) {
    sleep(1); // Simulate some work before signaling
    printf("Thread 2: Sending signal...\n");
    sem_post(&semaphore); // Signal to thread 1
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    sem_init(&semaphore, 0, 0); // Initialize semaphore with value 0, shared between threads

    // Create threads
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}
