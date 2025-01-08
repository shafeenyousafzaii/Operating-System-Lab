#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <signal.h>
int main()
{
printf("Hello");
kill(getpid(), 9);
printf("Goodbye");
}
