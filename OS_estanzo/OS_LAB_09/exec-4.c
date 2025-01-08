#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int pid;

void sigHandler(int sigNum)
{
    printf("\nSignals received \n");
    kill(pid, 9);
    sleep(20);
}

int main()
{

    pid = fork();
    if (pid != 0)
    {
        printf("Parent Id is : %d", getpid());
        signal(SIGINT, sigHandler);
        sleep(20);
    }
    else if (pid == 0)
    {
        printf("Child Id is : %d", getpid());
        kill(getppid(), 2);
        sleep(20);
    }
    return 0;
}