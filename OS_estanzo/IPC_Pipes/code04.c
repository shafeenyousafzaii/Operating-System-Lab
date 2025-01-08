#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    int pfd[2];
    pipe(pfd);
    if (fork() == 0) {
        close(pfd[1]);          // Closing the write side of pipe becuase we are not going to use it
        dup2(pfd[0], 0);        // Standard input of pfd[0] is now pointing to file descriptor  0 which is standard input now what we are going to input will go the pfd[0]
        close(pfd[0]);
        execlp("wc", "wc", (char *) 0);
    } else {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execlp("ls", "ls", (char *) 0);
    }
    return 0;
}