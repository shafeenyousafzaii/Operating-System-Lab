#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct func_param {
    int numOne;
    int numTwo;
    int result;
};

void * Add(void * arg) {
    struct func_param *add;
    add = (struct func_param *) arg;
    int sum = add->numOne + add->numTwo;
    add->result = sum;
}

void * Sub(void * arg) {
    struct func_param * sub;
    sub = (struct func_param *) arg;
    int minus = sub->numOne - sub->numTwo;
    sub->result = minus;
}

void * Mul(void * arg) {
    struct func_param *mul;
    mul = (struct func_param *) arg;
    int result = mul->numOne * mul->numTwo;
    mul->result = result;
}

void * Div(void * arg) {
    struct func_param *div;
    div = (struct func_param *) arg;
    int result = div->numOne / div->numTwo;
    div->result = result;
}

int main() {
    struct func_param add;
    struct func_param sub;
    struct func_param mul;
    struct func_param div;

    add.numOne = 5;
    add.numTwo = 4;

    sub.numOne = 5;
    sub.numTwo = 15;

    mul.numOne = 5;
    mul.numTwo = 2;

    div.numOne = 6;
    div.numTwo = 2;

    pthread_t tid0, tid1, tid2, tid3;

    pthread_create(&tid0, NULL, Add, (void *) &add);
    pthread_create(&tid1, NULL, Sub, (void *) &sub);
    pthread_create(&tid2, NULL, Mul, (void *) &mul);
    pthread_create(&tid3, NULL, Div, (void *) &div);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);


    printf("The Add => %d\n", add.result);
    printf("The Sub => %d\n", sub.result);
    printf("The Mul => %d\n", mul.result);
    printf("The Div => %d\n", div.result);
    

    return 0;
}