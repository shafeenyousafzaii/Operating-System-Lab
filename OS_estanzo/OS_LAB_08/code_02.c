#include <unistd.h>
#include <stdio.h>
int main()
{
    int pid;
    int pfd[2];
    char aString[20];
    pipe(pfd);
    pid = fork();
    if (pid == 0)
    {
        write(pfd[1], "Hello", 5); // Write onto pipe
        sleep(10);
        printf("Hello from child\n"); // When Parent Exited then return 0 parent is executed by terminal when parent exits terminal guess that my process exits
    }
    else
    {
        read(pfd[0], aString, 5); // Read from pipe
        printf("%s\n", aString);
    }
    close(pfd[0]);
    close(pfd[1]);
    return 0;
}