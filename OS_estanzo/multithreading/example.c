#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * print_message(void * message) {
    char *msg = (char *) message;
    printf("Message => %s\n", msg); 
}

int main() {
    pthread_t tid0, tid1;
    const char * message = "Thread 1";
    const char * message2 = "Thread 2";
    pthread_create(&tid0, NULL, print_message,(void *) message);
    pthread_create(&tid1, NULL, print_message,(void *) message2);
    pthread_exit(NULL);
    return 0;
}