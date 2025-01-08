#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int sigCounter = 0;

void sigHandler(int sigNum)
{
    printf("Signal Recieved %d\n", sigNum);
    ++sigCounter;
    printf("Signal Recieved %d\n", sigCounter);
}

int main()
{
    signal(SIGINT, SIG_IGN);
    while (1)
    {
        printf("Hello Dears\n");
        sleep(1);
    }
    return 0;
}