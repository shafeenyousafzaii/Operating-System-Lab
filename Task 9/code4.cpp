    #include <unistd.h>
#include <stdio.h>
int main() {
int pid;
// Process ID for fork
int pfd[2];
// Pipe file descriptors
char aString[20]; // Buffer for the parent to store data from the pipe
pipe(pfd);// Create a pipe
pid = fork();// Fork a child process
if (pid == 0) {
// Child process\
write(pfd[1], "Hello", 5); // Write "Hello" to the pipe
} else {
// Parent process
read(pfd[0], aString, 5); // Read from the pipe into aString
}
}
