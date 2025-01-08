#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
int main()
{
printf("\nMuhammad Shafeen\n");
printf("22P-9278\n");
printf("BAI-5A\n");

int x=10;
int y=20;
int sum=x+y;
printf("Sum of %d and %d is : %d\n",x,y,sum);

kill(getpid(),15); //9

printf("The program has been killed\n");
return 0;
}
