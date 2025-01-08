#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
int pfd[2]; // Pipe file descriptors
pipe(pfd);
// Create a pipe
if (fork() == 0) {
// Child process
close(pfd[1]);
// Close the write end
dup2(pfd[0], 0); // Redirect stdin to the read end of the pipe
close(pfd[0]);
// Close the read end after duplication
execlp("wc", "wc", (char *)0); // Replace process with ’wc’
} else {
// Parent process
close(pfd[0]);
// Close the read end
dup2(pfd[1], 1); // Redirect stdout to the write end of the pipe
close(pfd[1]);
// Close the write end after duplication
execlp("ls", "ls", (char *)0); // Replace process with ’ls’
}
return 0;
}
