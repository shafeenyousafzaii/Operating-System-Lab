#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Creating pipes for IPC
    int pfd[2];
    pipe(pfd);

    int pid;
    int sum = 0, average = 0, arr_size = 10;

    // Create The array of size 10
    int arr[arr_size];
    int r = 20;            

    // store the 10 Random Numbers from 20 to 70
    for (int i = 0; i < 10; i++) {
        r += i;
        arr[i] = r;
    }   
    // Creating the child process
    pid = fork();
    if (pid == 0) {
        // child
        for (int i = 0; i < 10; i++) {
            sum += arr[i];
            sleep(1);
        }
        average = sum/arr_size;

        close(pfd[0]);
        write(pfd[1], &average, sizeof(int));
        close(pfd[1]);

    } else {
        // parent with child pid
        sleep(5);
        if (average == 0) {
            printf("[CHILD] Let me finish my work first\n");
            wait(NULL);
        }   
        int t;
        close(pfd[1]);
        read(pfd[0], &t, sizeof(int));
        close(pfd[0]);
        printf("The Average By Child is=> %d\n", t);
    }


    return 0;
}