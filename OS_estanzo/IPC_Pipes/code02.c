#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    int fd[2];
    // fd[0] - reading data
    // fd[1] - writing data

    // If Unable to Create the pipe
    if (pipe(fd) == -1) {   
        printf("Error Occured on during the creation of the pipe\n");
        return 1;
    }
    int pid = fork();
    if (pid == -1) {
        printf("An Error Occured During forking \n");
        return 4;
    }
    if (pid == 0) {
        // Child Process
        close(fd[0]);
        int x;  
        printf("Enter a Number=> ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1) {
            printf("An Error Occured During Writing\n");
            return 2;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) {
            printf("An Error Occurrend During Reading From Pipe\n");
            return 3;
        }
        close(fd[0]);
        printf("Go Y From Child %d\n ", y);
    }
    return 0;
}