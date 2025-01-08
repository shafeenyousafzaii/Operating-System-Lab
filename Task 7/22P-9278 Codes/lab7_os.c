#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t  id,id1;
//sleep(3);
if(id=fork()&&fork())
{

  if(id==0){
print("child process");
fork();}
}
sleep(3);
return 0;
}
