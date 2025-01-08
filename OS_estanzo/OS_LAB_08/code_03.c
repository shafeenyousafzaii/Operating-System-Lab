#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int pfd[2];
    pipe(pfd);
    if (fork() == 0)
    {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        execlp("wc", "wc", (char *)0);
    }
    /* By Default when we execute the command wc it takes input from file descriptor 0 but we have changed it's file descriptor from 0 to pipe
        so now it will take input from pipe
        In the Parent by default the output goes to the 1 that is Output but we have changed the output descriptor to pipe to data send to pipe
        the child pick data from 1 descriptor and that is pipe and the other parent send data to child and output produced on console
        */
    else
    {
        close(pfd[0]);
        dup2(pfd[1], 1); // output goes to pipe not to console the dup2 does this
        close(pfd[1]);
        execlp("ls", "ls", (char *)0);
    }
}