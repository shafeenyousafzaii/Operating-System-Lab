#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	int p;
	printf("Orignal Process pid= %d\n", getpid());
	p = fork();
	if (p == 0) {
		printf("Child Pid = %d, PPID = %d \n", getpid(), getppid() ); 
		sleep(200);
	} else {
		printf("Parent PID = %d, Child ID = %d \n", getpid(), p);
	}
	return 0;
}
