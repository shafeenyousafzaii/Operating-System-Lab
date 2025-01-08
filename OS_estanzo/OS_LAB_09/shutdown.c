#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    kill(1, SIGTERM);
    return 0;
}