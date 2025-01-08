#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void anotherExit();
int main()
{
int num ;
void anotherExit();
printf("Enter a number " ) ;
scanf("%i",&num);
if(num>25)
{
printf("exit 1\n");
exit(1);
}
else
anotherExit();
}
void anotherExit()
{
printf("Exit 2\n");
exit(1);
}
