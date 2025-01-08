#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main() 
{
for(int  i=10 ;i>=0 ; i--)
{
sleep(1);
printf("%d\n",i);
}
return 0;
}
