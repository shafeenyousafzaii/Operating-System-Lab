#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
    int p;
    p = fork();
    char msg[20];
    while (1)
    {
        if (p == 0)
        {
            printf("P1:");
            scanf("%s", msg);
            printf("\nP1 Says: %s\n", msg);
            return 0;
        }
        else
        {
            wait(NULL);
            printf("P2:");
            scanf("%s", msg);
            printf("\nP2 Says: %s\n", msg);
            p = fork();
        }
    }
    return 0;
}