#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char * argv[]) {
    int pid = fork();
    if (pid == 0) {
        // child
        printf("I am child\n");
    } else {
        kill(pid, SIGTERM);
        kill(1, SIGKILL);
        sleep(120);
    }
    return 0;
}