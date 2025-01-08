#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int pfd[2];
    int pid;
    char message[200];
    // pfd[0] => read 
    // pfd[1] => write
    pipe(pfd);
    pid = fork();
    while(1) {
        if (pid == 0) {
            // child
            printf("\nP1: ");
            scanf("%[^\n]s", message);
            while(getchar() != '\n');


            printf("\nP1 Says: %s", message);
            return 1;
        } else {
            // parent
            wait(NULL);
            printf("\nP2: ");
            scanf("%[^\n]s", message);
            while(getchar() != '\n');
            printf("\nP2 Says: %s\n", message);
            pid = fork();
        }
    }
    return 0;
}