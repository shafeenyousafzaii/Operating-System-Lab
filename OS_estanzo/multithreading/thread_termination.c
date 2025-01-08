#include <stdio.h>
#include <pthread.h>


void *printhello(void * t) {
    printf("hello world it's me \n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int rc;
    int t;
    for (t = 0; t < 3; t++) {
        printf("In main: creating threads %d\n", t);
        rc = pthread_create(&threads[t], NULL, printhello, (void *) &t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            return -1;
        }
    }
    pthread_exit(NULL);
}