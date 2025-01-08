#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

int find_factorial(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * find_factorial(n - 1);
    }
}

void *factorial(int *n)
{
    int result = find_factorial(*n);
    return (void *)(intptr_t)result;
}

int main(void)
{
    pthread_t thread;
    void *result;
    int ret;
    int num = 5;

    pthread_create(&thread, NULL, (void * ) &factorial, &num);
    ret = pthread_join(thread, &result);

    if (ret) {
        fprintf(stderr, "pthread_join() failed\n");
        return -1;
    }
    printf("Factorial Of the Given Number Is=> %ld\n", (intptr_t)result);

    return 0;
}