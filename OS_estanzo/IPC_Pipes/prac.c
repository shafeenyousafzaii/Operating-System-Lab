#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    int pid = fork();
    if (pid == 0) {
        execlp("wc", "wc", (char *) 0);
    } else {
        
        execlp("ls", "ls", (char *) 0);
    }
    return 0;
}