#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main() {
int pid;
// Process ID for fork
int pfd[2];
// Pipe file descriptors
char aString[20]; // Buffer for the parent to store data from the pipe
pipe(pfd);// Create a pipe
pid = fork();// Fork a child process
if (pid == 0) {
// Child process
close(pfd[0]);
write(pfd[1], "Hello", 5); // Write "Hello" to the pipe
close(pfd[1]);
} else {
close(pfd[1]);
printf("Before read: %s\n", aString); // Print aString before reading
read(pfd[0], aString, 5); // Read from the pipe into aString
close(pfd[0]);
printf("After read: %s\n", aString); // Print aString after reading
}
}
