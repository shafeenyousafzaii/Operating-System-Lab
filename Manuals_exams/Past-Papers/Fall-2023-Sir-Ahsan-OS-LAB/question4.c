#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid2, pid3, pid4;
    
    printf("Executing P1 (PID: %d)\n", getpid());

    // Create P2
    pid2 = fork();
    if (pid2 < 0) {
        perror("Failed to fork P2");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
        // Inside P2
        printf("Executing P2 (PID: %d) created by P1 (PID: %d)\n", getpid(), getppid());

        pid_t pid5, pid6;

        // Create P5
        pid5 = fork();
        if (pid5 < 0) {
            perror("Failed to fork P5");
            exit(EXIT_FAILURE);
        }
        if (pid5 == 0) {
            // Inside P5
            printf("Executing P5 (PID: %d) created by P2 (PID: %d)\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }

        // Create P6
        pid6 = fork();
        if (pid6 < 0) {
            perror("Failed to fork P6");
            exit(EXIT_FAILURE);
        }
        if (pid6 == 0) {
            // Inside P6
            printf("Executing P6 (PID: %d) created by P2 (PID: %d)\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }

        // Wait for P5 and P6 to finish
        wait(NULL);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    // Create P3
    pid3 = fork();
    if (pid3 < 0) {
        perror("Failed to fork P3");
        exit(EXIT_FAILURE);
    }
    if (pid3 == 0) {
        // Inside P3
        printf("Executing P3 (PID: %d) created by P1 (PID: %d)\n", getpid(), getppid());

        pid_t pid7;

        // Create P7
        pid7 = fork();
        if (pid7 < 0) {
            perror("Failed to fork P7");
            exit(EXIT_FAILURE);
        }
        if (pid7 == 0) {
            // Inside P7
            printf("Executing P7 (PID: %d) created by P3 (PID: %d)\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }

        // Wait for P7 to finish
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    // Create P4
    pid4 = fork();
    if (pid4 < 0) {
        perror("Failed to fork P4");
        exit(EXIT_FAILURE);
    }
    if (pid4 == 0) {
        // Inside P4
        printf("Executing P4 (PID: %d) created by P1 (PID: %d)\n", getpid(), getppid());

        pid_t pid8;

        // Create P8
        pid8 = fork();
        if (pid8 < 0) {
            perror("Failed to fork P8");
            exit(EXIT_FAILURE);
        }
        if (pid8 == 0) {
            // Inside P8
            printf("Executing P8 (PID: %d) created by P4 (PID: %d)\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }

        // Wait for P8 to finish
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    // Parent process P1 waits for P2, P3, and P4 to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("P1 (PID: %d) is terminating.\n", getpid());
    return 0;
}

