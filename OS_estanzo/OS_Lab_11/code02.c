// Thread Termination Cases
// 1: Function Completed It's execution 
// 2: Thread Makes the exit call pthread_exit()
// 3: exec() or exit() call then thread terminated
// 4: main thread exits then all the thread will be terminated
// 5: If you use the pthread_exit then the other threads that depend on the main thread will going to separate the threads from main that are runed in main to complete their execution
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_data {
    int x;
    int y;
    int z;
};


void *print(void *threadArg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadArg;
    printf("X: %d, Y: %d, Z: %d\n", my_data->x, my_data->y, my_data->z);
}

int main() {
    pthread_t tid;
    struct thread_data j;
    j.x = 1;
    j.y = 2;
    j.z = j.x + j.y;
    int return_value1;
    return_value1 = pthread_create(&tid, NULL, print, (void *) &j);

    pthread_join(tid, NULL);
    exit(0);
}