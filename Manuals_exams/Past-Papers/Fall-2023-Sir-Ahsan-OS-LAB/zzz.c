#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_FILENAME_LEN 256
#define NUM_FILES 3  // Number of files to process

// Function to write a null-terminated string to a pipe
void write_string(int fd, const char *str) {
    if (write(fd, str, strlen(str) + 1) == -1) { // Include null terminator
        perror("write_string: write");
        exit(EXIT_FAILURE);
    }
}

// Function to read a null-terminated string from a pipe
int read_string(int fd, char *buffer, size_t max_len) {
    size_t i = 0;
    char ch;
    ssize_t n;

    while (i < max_len - 1) { // Reserve space for null terminator
        n = read(fd, &ch, 1);
        if (n == 0) {
            // EOF
            if (i == 0)
                return 0;
            break;
        } else if (n < 0) {
            perror("read_string: read");
            return -1;
        }

        if (ch == '\0') {
            break;
        }

        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    return 1;
}

// PV1: Input Process
void PV1_Process(int write_fd) {
    // Filenames to process
    char *fileNames[NUM_FILES] = {"video1.mp4", "video2.mkv", "video3.avi"};

    // Send each filename to PV2
    for (int i = 0; i < NUM_FILES; i++) {
        write_string(write_fd, fileNames[i]);
    }

    // Close write end and exit
    close(write_fd);
    exit(EXIT_SUCCESS);
}

// PV2: Transcoding Process
void PV2_Process(int read_fd, int write_fd) {
    char buffer[MAX_FILENAME_LEN];

    // Read filenames from PV1, process, and send to PV3
    while (read_string(read_fd, buffer, MAX_FILENAME_LEN) > 0) {
        strcat(buffer, "_transcoded");
        write_string(write_fd, buffer);
    }

    // Close remaining pipe ends and exit
    close(read_fd);
    close(write_fd);
    exit(EXIT_SUCCESS);
}

// PV3: Quality Control Process
void PV3_Process(int read_fd, int write_fd) {
    char buffer[MAX_FILENAME_LEN];

    // Read filenames from PV2, process, and send to PV4
    while (read_string(read_fd, buffer, MAX_FILENAME_LEN) > 0) {
        strcat(buffer, "_QC_Passed");
        write_string(write_fd, buffer);
    }

    // Close remaining pipe ends and exit
    close(read_fd);
    close(write_fd);
    exit(EXIT_SUCCESS);
}

// PV4: Distribution Process
void PV4_Process(int read_fd) {
    char buffer[MAX_FILENAME_LEN];

    // Read filenames from PV3 and distribute (print)
    while (read_string(read_fd, buffer, MAX_FILENAME_LEN) > 0) {
        printf("Distributed: %s\n", buffer);
    }

    // Close remaining pipe ends and exit
    close(read_fd);
    exit(EXIT_SUCCESS);
}

int main() {
    int pipe_PV1_PV2[2], pipe_PV2_PV3[2], pipe_PV3_PV4[2];

    // Create the necessary pipes
    if (pipe(pipe_PV1_PV2) == -1 || pipe(pipe_PV2_PV3) == -1 || pipe(pipe_PV3_PV4) == -1) {
        perror("main: pipe");
        exit(EXIT_FAILURE);
    }

    // Fork PV1 (Input Process)
    pid_t pv1_pid = fork();
    if (pv1_pid < 0) {
        perror("main: fork PV1");
        exit(EXIT_FAILURE);
    }

    if (pv1_pid == 0) {
        // PV1 Process
        // Close unused pipe ends
        close(pipe_PV1_PV2[0]); // Close read end
        close(pipe_PV2_PV3[0]); close(pipe_PV2_PV3[1]); // Not used
        close(pipe_PV3_PV4[0]); close(pipe_PV3_PV4[1]); // Not used

        PV1_Process(pipe_PV1_PV2[1]);
    }

    // Fork PV2 (Transcoding Process)
    pid_t pv2_pid = fork();
    if (pv2_pid < 0) {
        perror("main: fork PV2");
        exit(EXIT_FAILURE);
    }

    if (pv2_pid == 0) {
        // PV2 Process
        // Close unused pipe ends
        close(pipe_PV1_PV2[1]); // Close write end
        close(pipe_PV2_PV3[0]); // Close read end
        close(pipe_PV3_PV4[0]); close(pipe_PV3_PV4[1]); // Not used

        PV2_Process(pipe_PV1_PV2[0], pipe_PV2_PV3[1]);
    }

    // Fork PV3 (Quality Control Process)
    pid_t pv3_pid = fork();
    if (pv3_pid < 0) {
        perror("main: fork PV3");
        exit(EXIT_FAILURE);
    }

    if (pv3_pid == 0) {
        // PV3 Process
        // Close unused pipe ends
        close(pipe_PV1_PV2[0]); close(pipe_PV1_PV2[1]); // Not used
        close(pipe_PV2_PV3[1]); // Close write end
        close(pipe_PV3_PV4[0]); // Close read end

        PV3_Process(pipe_PV2_PV3[0], pipe_PV3_PV4[1]);
    }

    // Fork PV4 (Distribution Process)
    pid_t pv4_pid = fork();
    if (pv4_pid < 0) {
        perror("main: fork PV4");
        exit(EXIT_FAILURE);
    }

    if (pv4_pid == 0) {
        // PV4 Process
        // Close unused pipe ends
        close(pipe_PV1_PV2[0]); close(pipe_PV1_PV2[1]); // Not used
        close(pipe_PV2_PV3[0]); close(pipe_PV2_PV3[1]); // Not used
        close(pipe_PV3_PV4[1]); // Close write end

        PV4_Process(pipe_PV3_PV4[0]);
    }

    // Parent Process
    // Close all pipe ends as parent doesn't use them
    close(pipe_PV1_PV2[0]); close(pipe_PV1_PV2[1]);
    close(pipe_PV2_PV3[0]); close(pipe_PV2_PV3[1]);
    close(pipe_PV3_PV4[0]); close(pipe_PV3_PV4[1]);

    // Wait for all child processes to finish
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}

