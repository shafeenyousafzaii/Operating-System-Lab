#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	fork();
	printf("He\n");
	fork();
	printf("Ha\n");
	fork();
	printf("Ho\n");
	return 0;
}
