#include <unistd.h>
#include <stdio.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            pid = fork();
            printf("Child\n");
        }
        return 0;
    }
    pid = fork();
    if (pid != 0)
        printf("Parent\n");
    return 0;
}