#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
    int p;
    p = fork();
    if (p == 0)
    {
        signal(9, SIG_IGN);
        printf("Hello In CHILD\n");
        while (1)
            ;
    }
    else
    {
        sleep(10);
        kill(p, 9);
        sleep(10);
    }
    return 0;
}