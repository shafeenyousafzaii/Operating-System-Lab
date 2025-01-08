#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int pid;
	int process_created=0;
	int counter = 0;
	pid = fork();
	if (counter == 0 && pid == 0) {
		pid = fork();
		counter++;
		process_created += 1;
	} else {
		for (int i = 0; i < 2; i++) {
			pid = fork();
			process_created += 1;
		}
	}
	printf("Number of Process Created %d\n", process_created); 
	return 0;
}
