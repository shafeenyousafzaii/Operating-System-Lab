#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

// Kill the child
void killChild()
{
    kill(getpid(), 9);
}

int main()
{
    int p;
    p = fork();
    if (p == 0)
    {
        kill(getppid(), 2);
        while (1)
            ;
        printf("al\n");
    }
    else
    {
        signal(SIGINT, killChild);
    }
    return 0;
}