#include <unistd.h>
#include <stdio.h>
int main() {
    int pid;
    int pfd[2];
    pipe(pfd);
    char msg[50];
    pid = fork();
    if (pid == 0) {
        // child
        close(pfd[0]);
        write(pfd[1], "Hello", 5);
        close(pfd[1]);
    } else {
        close(pfd[1]);
        read(pfd[0], msg, 6);
        close(pfd[0]);
        printf("The msg => %s\n", msg);
        // parent with child pid
    }
}
