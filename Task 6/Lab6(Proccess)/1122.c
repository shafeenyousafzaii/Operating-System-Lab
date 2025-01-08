#include <unistd.h>
#include <stdio.h> // For printf()

int main() {
    int p;
    printf("Original Process, pid = %d\n", getpid());
    
    p = fork();
    
    if (p == 0) {
        // Child process
        printf("Child PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(120); // Child process sleeps for 120 seconds
    } else {
        // Parent process
        printf("Parent PID = %d, Child ID = %d\n", getpid(), p);
        sleep(120); // Parent process sleeps for 120 seconds
    }
    
    return 0;
}

