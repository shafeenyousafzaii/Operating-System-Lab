#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct fib {
    int num;
    int result;
} fib1;

int fib(int n) {
    if (n<=0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

void * find_fib(void * arg) {
    struct fib * fib2;
    fib2 = (struct fib *) arg;
    int result = fib(fib2->num);
    fib2->result = result;
}
int main() {
    pthread_t tid0;
    fib1.num = 40;
    fib1.result = 0;
    pthread_create(&tid0, NULL, find_fib, (void *) &fib1);
    pthread_join(tid0, NULL);
    printf("Fib=> %d\n", fib1.result);
    return 0;
}