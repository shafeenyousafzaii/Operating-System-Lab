#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int p;
	p = fork();
	printf("Job Done\n"); 
	printf("Value of P is %d \n", p);
	return 0;
}
