#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int main()
{
int pid;
int pfd[2];
char aString[20];

pipe(pfd);

pid=fork();
printf("Chat : ");
while(1)
{
scanf("%s",aString);
printf("P1:");
close(pfd[0]);
write(pfd[1],aString,10);
close(pfd[1]);
printf("%s\n", aString);
read(pfd[0], aString, 20);
close(pfd[0]);
printf("P2 Says:");
aString[20] = '\0';
scanf("%s",aString);
write(pfd[1],aString,10);
close(pfd[1]);
read(pfd[0],aString,20);
printf("%s\n",aString);
aString[20] = '\0';
close(pfd[0]);
}
}
