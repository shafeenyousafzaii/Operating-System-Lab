#include <stdio.h>
#include <unistd.h>
int main()
{
    for (int i = 10; i >= 0; i--)
    {
        printf("%d", i);
        sleep(1);
        printf("\n");
    }
    return 0;
}