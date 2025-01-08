#include <unistd.h>
#include <stdio.h>

int main() {
    int pid;
    pid = fork();
    printf("My Process ID = %d \n", getpid());
    if (pid == 0) {
        for (int i = 0; i < 2; i++) {
            printf("My Process ID = %d\n", getpid());
            pid = fork();
        }
        return 0;
    }
    pid = fork();
    if (pid == 0) {
        printf("My Process ID= %d\n", getpid());
        pid = fork();
        if (pid == 0) {
            printf("My Process ID= %d\n", getpid());
        }
    }
    
    return 0;
}

// Diagram of 7 Processes that Program Creating
//               *
//         *         *
//       *   *      *    * 
//         *   *  *  *  *  *

// At Leafs After the Program we have 7 seven processes created including paretn
