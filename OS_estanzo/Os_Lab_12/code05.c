#include <stdio.h>
#include <stdlib.h>

void f(void) {
    void* s;
    s = malloc(50);
    return;
}

int main(void) {
    while (1)
    f();
    return 0;
}