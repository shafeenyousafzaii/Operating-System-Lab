#include<stdio.h>
#include<stdlib.h>
void f1(void);
void f2(void);
void f3(void);
int main(void) {
void f1(void), f2(void), f3(void);
atexit(f1);
atexit(f2);
atexit(f3);
printf("Getting ready to exit\n");
exit(0);
}

void f1(void) {
printf("In f1\n");
}
void f2(void) {
printf("In f2\n");
}
void f3(void) {
abort();
printf("In f3\n");
}
