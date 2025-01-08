// Independent Instructions are putted on different threads to make execution of our program fast
// The One Instruction will not going to the other instruction 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * print_message(char *ptr) {
    char *message;
    message = ptr;
    printf("%s\n", message);
}

int main() {
    // Struct for storing the information about the thread
    // Threadid, scheduling ... things get stored in the thread_struct from pthread.h library
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";

    int return_value1, return_value2;

    // Successfully created then return 0 and else return the error number in the return_value
    // Arguments 1: struct of thread, 2: Take Arguments, NULL mean it will be created by default arguments
    // 3: Function that we want to execute it expects the void * type function so type cast it
    // 4: Function Arguments
    return_value1 = pthread_create(&thread1, NULL, (void *) &print_message, message1);
    return_value2 = pthread_create(&thread2, NULL, (void *) &print_message, message2);

    // main thread termination sub threads also terminates if not join
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    exit(0);

}