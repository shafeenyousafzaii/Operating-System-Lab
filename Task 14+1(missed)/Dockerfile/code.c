#include<stdio.h>
int main()
{
int n=3;
int num=0;
for(int i=3;i<14;i++)
{
num=n*(i-3);
printf("%d x %d = %d\n",n,i-3,num);
}
return 0;
}

