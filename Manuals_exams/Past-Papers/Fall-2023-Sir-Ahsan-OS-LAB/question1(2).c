#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_FILENAME_LEN 256
#define NUM_FILES 3  // For demonstration

// Helper function to read a null-terminated string from a pipe
ssize_t read_message(int fd, char *buffer, size_t max_len) {
    size_t i = 0;
    char ch;
    ssize_t n;

    while (i < max_len - 1) { // Leave space for null terminator
        n = read(fd, &ch, 1);
        if (n == -1) {
            perror("read");
            return -1;
        } else if (n == 0) {
            // EOF
            if (i == 0) {
                return 0;
            }
            break;
        }

        if (ch == '\0') {
            break;
        }

        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    return i;
}

int main() {
    int pipe_PV1_PV2[2], pipe_PV2_PV3[2], pipe_PV3_PV4[2];

    // Create pipes
    if (pipe(pipe_PV1_PV2) == -1 || pipe(pipe_PV2_PV3) == -1 || pipe(pipe_PV3_PV4) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork for PV1 (Input Process)
    pid_t pv1_pid = fork();
    if (pv1_pid < 0) {
        perror("fork PV1");
        exit(EXIT_FAILURE);
    }

    if (pv1_pid == 0) {
        // In PV1 process
        // Close unused pipe ends
        close(pipe_PV1_PV2[0]);   // PV1 writes to PV2
        close(pipe_PV2_PV3[0]); close(pipe_PV2_PV3[1]); // Unused by PV1
        close(pipe_PV3_PV4[0]); close(pipe_PV3_PV4[1]); // Unused by PV1

        // Simulate reading file names from a repository
        char *fileNames[NUM_FILES] = {"video1.mp4", "video2.mkv", "video3.avi"};
        for (int i = 0; i < NUM_FILES; i++) {
            write(pipe_PV1_PV2[1], fileNames[i], strlen(fileNames[i]) + 1); // Include null terminator
        }

        // Close write end after sending
        close(pipe_PV1_PV2[1]);
        exit(EXIT_SUCCESS);
    }

    // Fork for PV2 (Transcoding Process)
    pid_t pv2_pid = fork();
    if (pv2_pid < 0) {
        perror("fork PV2");
        exit(EXIT_FAILURE);
    }

    if (pv2_pid == 0) {
        // In PV2 process
        // Close unused pipe ends
        close(pipe_PV1_PV2[1]); // PV2 reads from PV1
        close(pipe_PV2_PV3[0]); // PV2 writes to PV3
        close(pipe_PV3_PV4[0]); close(pipe_PV3_PV4[1]); // Unused by PV2

        char filename[MAX_FILENAME_LEN];
        ssize_t n;
        while ((n = read_message(pipe_PV1_PV2[0], filename, MAX_FILENAME_LEN)) > 0) {
            // Transcode simulation: append "_transcoded"
            strcat(filename, "_transcoded");
            write(pipe_PV2_PV3[1], filename, strlen(filename) + 1); // Include null terminator
        }

        close(pipe_PV1_PV2[0]);
        close(pipe_PV2_PV3[1]);
        exit(EXIT_SUCCESS);
    }

    // Fork for PV3 (Quality Control Process)
    pid_t pv3_pid = fork();
    if (pv3_pid < 0) {
        perror("fork PV3");
        exit(EXIT_FAILURE);
    }

    if (pv3_pid == 0) {
        // In PV3 process
        // Close unused pipe ends
        close(pipe_PV1_PV2[0]); close(pipe_PV1_PV2[1]); // Unused by PV3
        close(pipe_PV2_PV3[1]); // PV3 reads from PV2
        close(pipe_PV3_PV4[0]); // PV3 writes to PV4

        char filename[MAX_FILENAME_LEN];
        ssize_t n;
        while ((n = read_message(pipe_PV2_PV3[0], filename, MAX_FILENAME_LEN)) > 0) {
            // QC simulation: append "_QC_Passed"
            strcat(filename, "_QC_Passed");
            write(pipe_PV3_PV4[1], filename, strlen(filename) + 1); // Include null terminator
        }

        close(pipe_PV2_PV3[0]);
        close(pipe_PV3_PV4[1]);
        exit(EXIT_SUCCESS);
    }

    // Fork for PV4 (Distribution Process)
    pid_t pv4_pid = fork();
    if (pv4_pid < 0) {
        perror("fork PV4");
        exit(EXIT_FAILURE);
    }

    if (pv4_pid == 0) {
        // In PV4 process
        // Close unused pipe ends
        close(pipe_PV1_PV2[0]); close(pipe_PV1_PV2[1]); // Unused by PV4
        close(pipe_PV2_PV3[0]); close(pipe_PV2_PV3[1]); // Unused by PV4
        close(pipe_PV3_PV4[1]); // PV4 reads from PV3

        char filename[MAX_FILENAME_LEN];
        ssize_t n;
        while ((n = read_message(pipe_PV3_PV4[0], filename, MAX_FILENAME_LEN)) > 0) {
            // Distribution simulation: print the file
            printf("Distributed: %s\n", filename);
        }

        close(pipe_PV3_PV4[0]);
        exit(EXIT_SUCCESS);
    }

    // In the parent process, close all ends of the pipes
    close(pipe_PV1_PV2[0]);
    close(pipe_PV1_PV2[1]);
    close(pipe_PV2_PV3[0]);
    close(pipe_PV2_PV3[1]);
    close(pipe_PV3_PV4[0]);
    close(pipe_PV3_PV4[1]);

    // Wait for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

