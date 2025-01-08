#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Before execl: Listing directory contents\n");
    pid_t pid;
    pid=fork();
    if(pid==0)
{

    printf("Child with PID : %d  , running execl: \n",getpid());
    sleep(1);
    if (execl("/bin/ls", "sudo ls", "-l", "/media/shafeenyousafzai/OLDERDRIVE/Semester 5/Operating-System-Lab/Assignment # 2", (char *)NULL) == -1) {
        perror("execl failed");
        exit(EXIT_FAILURE);
    }

 }
 else{
 sleep(2);
 int x=0;
 int y=1;
 int sum=x+1;
 printf("Parent with PID : %d is printing the sum of %d and %d with answer : %d\n",getppid(),x,y,sum);    
 
 pid_t pid2;
 pid2=fork();
 if(pid2==0){
 sleep(1);
 printf("In the child code : " \n);
 execl("
    return 0;
}
}
