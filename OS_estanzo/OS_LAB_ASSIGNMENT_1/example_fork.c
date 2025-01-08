#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("PID of example.c = %d\n", getpid());
    pid_t p;
    p = fork();
    if (p == -1)
    {
        printf("There is an error while calling fork()");
    }
    if (p == 0)
    {
        printf("We are in the child process\n");
        printf("Calling hello.c from child process\n");
        char *args[] = {"Hello", "C", "Programming", NULL};
        execv("./example_exec", args);
    }
    else
    {
        printf("We are in the parent process\n");
    }
    return 0;
}

/**
 * In the example we have used the fork call now fork call create the clone of the current running process. The fork call returns
 * us 0 if child has a turn and -1 if any error and other will be parent has a control with return value of child pid
 * Now we have replaced the child process with the new process now parent will not be replaced else the child will be replaced
 * In this way we got two process running at a time. Otherwise the execv call completely destroys the current running process.
 * */
