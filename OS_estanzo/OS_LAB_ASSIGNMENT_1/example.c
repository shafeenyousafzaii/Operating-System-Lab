#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("PID of example.c = %d\n", getpid());
    char *args[] = {"Hello", "C", "Programming", NULL};
    execv("./hello", args);
    printf("Back to example.c");
    return 0;
}

/*
 *In this program we have used the execv call that takes the path of the program or process that will be replaced with
 *the current runnning process and the list of arguments in the second parameter. When the execv is executed the example.c
 *will be replaced with hello.c and the control will never come back to the example.c and output of the last line "Back example.c"
 *will never be seen.
 */