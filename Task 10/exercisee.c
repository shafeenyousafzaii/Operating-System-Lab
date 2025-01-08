#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
printf("\nMuhammad Shafeen\n");
printf("22P-9278\n");
printf("BAI-5A\n");

int x=10;
int y=20;
int sum=x+y;
printf("Sum of %d and %d is : %d\n",x,y,sum);
pid_t pid;
pid=fork();
if(pid==0)
{
sleep(1);
pid_t pid2;
pid2=fork();
if(pid2==0)
{
printf("Showing processess before killing it\n");
execl("/bin/ps","ps -au",(char *)NULL);
perror("execl failed");
}
kill(getpid(),15); //9
// sleep(5);
}
else
{
sleep(2);
printf("Showing processess after killing it\n");
execl("/bin/ps","ps -au",(char *)NULL);
perror("execl failed");
exit(EXIT_FAILURE);
return 0;
}
}
