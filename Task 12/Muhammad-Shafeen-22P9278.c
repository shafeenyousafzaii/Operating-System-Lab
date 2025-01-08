#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int answer=0;
int x=0;
void *Fib(void *arg)
{
 if(x<0)
    answer= 0;
  else if(x==1)
  answer= 1;
else{
int temp_n=0;
int a=x;
int b=x;
for (int i = 0; i <= x; i++) {
  	    a=a-1;
  	    b=b-2;	
            temp_n = a + b;
          }
        answer = b;
}

printf("answer : %d",answer);
}
int main()
{
printf("Enter a number to find its FIB");
scanf("%d",&x);
 pthread_t myThread;
 int i;
int code; 
//(int *)&x
code=pthread_create(&myThread,NULL,Fib,NULL);

 if(code)
{
printf("Error");
} 

printf("Fib of num : %d is %d",x,answer);
//pthread_join(myThread,NULL);
}
