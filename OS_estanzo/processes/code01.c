#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()  { 
	int i;
	printf("Parent Process %d, Child Process Id %d\n", getpid(), getppid());
	for (i = 0; i < 5; i++) {
		if (fork() == 0) {
			printf("Parent Process Pid %d Child Process Id %d \n", getpid(), getppid());
		}
	}
	return 0;
}
