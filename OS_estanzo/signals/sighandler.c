#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int count = 0;
void sigHandler(int sigNum) {
    printf("The Signal Number %d\n", sigNum);
    ++count;
    printf("Signal called till now => %d\n", count);
}

int main() {
    signal(SIGINT, sigHandler);
    while(1) {
        printf("Hello Dear \n");
        sleep(1);
    }
    return 0;
}