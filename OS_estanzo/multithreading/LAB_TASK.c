#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int fac(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * fac(n - 1);
    }
}

void * find_fib(void * n) {
    int n1 = *((int *) n);
    int result = (int) fac(n1);
    return (void *) result;
}

int main() {
    pthread_t tid0;
    int n = 5;
    void * result;
    int ret = pthread_create(&tid0, NULL, find_fib, (void *) &n);
    pthread_join(tid0, &result);
    printf("Result => %ld\n", (intptr_t)result);
    return 0;
}