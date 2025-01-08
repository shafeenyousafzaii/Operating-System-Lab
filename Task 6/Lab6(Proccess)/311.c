#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

int main()  
{
    int pid = fork();  

    if(pid < 0)
    {
        printf("Child process is not created\n");
        return 1;  
    }
    else if(pid == 0)
    {
        printf("This is the child process: %d\n", getpid());  
    }
    else 
    {
        printf("This is the parent process: %d\n", getpid());  
    }
    
    return 0;  
}
