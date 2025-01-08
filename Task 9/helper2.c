#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
void to_uppercase(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
}
int pfd1[2]; // Pipe for Parent to Child communication
int pfd2[2]; // Pipe for Child to Parent communication

// Create Pipe pfd1
if (pipe(pfd1) == -1) {
    perror("pipe pfd1");
    exit(EXIT_FAILURE);
}

// Create Pipe pfd2
if (pipe(pfd2) == -1) {
    perror("pipe pfd2");
    exit(EXIT_FAILURE);
}
pid_t pid = fork();

if (pid < 0) {
    // Fork failed
    perror("fork");
    exit(EXIT_FAILURE);
}
if (pid > 0) {
    // Parent Process

    // Close unused ends of the pipes
    close(pfd1[0]); // Close reading end of pfd1
    close(pfd2[1]); // Close writing end of pfd2

    char parent_msg[100];
    char child_response[100];

    while (1) {
        // Prompt user for input
        printf("Parent: Enter message (or 'exit' to quit): ");
        fflush(stdout); // Ensure the prompt is displayed

        // Read input from user
        if (fgets(parent_msg, sizeof(parent_msg), stdin) == NULL) {
            perror("fgets");
            break;
        }

        // Remove newline character from input
        parent_msg[strcspn(parent_msg, "\n")] = '\0';

        // Check for exit condition
        if (strcmp(parent_msg, "exit") == 0) {
            // Inform child to exit
            write(pfd1[1], parent_msg, strlen(parent_msg) + 1);
            break;
        }

        // Write message to child
        if (write(pfd1[1], parent_msg, strlen(parent_msg) + 1) == -1) {
            perror("write to pfd1");
            break;
        }

        // Read response from child
        ssize_t n = read(pfd2[0], child_response, sizeof(child_response));
        if (n > 0) {
            printf("Child: %s\n", child_response);
        } else if (n == 0) {
            // No more data; child has closed the pipe
            printf("Child has closed the connection.\n");
            break;
        } else {
            perror("read from pfd2");
            break;
        }
    }

    // Close remaining pipe ends
    close(pfd1[1]);
    close(pfd2[0]);

    // Wait for child process to finish
    wait(NULL);
    printf("Parent: Exiting.\n");
}
