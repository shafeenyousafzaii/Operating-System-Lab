#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void anotherExit() {
	printf("Exit 2 \n");
	exit(1);
}
int main() {
	int num;
	printf("Enter a Number: ");
	scanf("%d",&num);
	if (num>25) {
		printf("exit 1\n");
		exit(1); 
	} else {
		anotherExit();
	}
}
