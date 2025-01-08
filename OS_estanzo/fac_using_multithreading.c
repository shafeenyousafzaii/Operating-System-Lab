#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct func_args {
    int num;
    int result;
} args;

int fac(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fac(n - 1);
    }
}

void * find_fac(void * args) {
    struct func_args *given_data;
    given_data = (struct func_args *) args;
    int result = fac(given_data->num);
    given_data->result = result;
    return NULL;
}
int main() {
    args.num = 5;
    args.result = 0;

    pthread_t tid0;
    pthread_create(&tid0, NULL, find_fac, (void *) & args);

    pthread_join(tid0, NULL);
    printf("The Fac => %d\n", args.result);

    return 0;
}