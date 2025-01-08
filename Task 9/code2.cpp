#include <unistd.h>
#include <stdio.h>
int main() {
int pfd[2]; // file descriptors array
pipe(pfd); // create pipe
printf("pfd[0] = %d, pfd[1] = %d\n", pfd[0], pfd[1]);
// Print pipe file descriptors
}
