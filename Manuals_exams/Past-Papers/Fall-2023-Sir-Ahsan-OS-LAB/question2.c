#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

// Mutex for synchronization
pthread_mutex_t lock;

// Total running time
int total_time = 0;

// Function to simulate device application
void *device_application(void *arg) {
    // Extract device name and update interval
    char **device_info = (char **)arg;
    char *device_name = device_info[0];
    int interval = atoi(device_info[1]);

    // Acknowledgment message
    pthread_mutex_lock(&lock);
    printf("%s started and running for %d seconds\n", device_name, interval);
    pthread_mutex_unlock(&lock);

    // Simulate device update
    sleep(interval);
    
    pthread_mutex_lock(&lock);
    printf("%s updated and took %d seconds\n", device_name, interval);
    total_time += interval; // Update total time
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        return EXIT_FAILURE;
    }

    printf("Initializing OS +++++++++++++\n");
    printf("Starting all the applications +++++++++++++\n");

    // Device applications and their update intervals
    char *devices[5][2] = {
        {"Heart Rate Monitor", "4"},
        {"Oxygen Monitor", "3"},
        {"Blood Pressure Monitor", "10"},
        {"Glucose Monitor", "3"},
        {"Respiratory Monitor", "5"}
    };

    // Create threads for each device
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        if (pthread_create(&threads[i], NULL, device_application, devices[i]) != 0) {
            perror("Thread creation failed");
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output total time
    printf("Total time taken by all applications: %d seconds\n", total_time);
    printf("Terminating Kernel Process +++++++++++++\n");

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
