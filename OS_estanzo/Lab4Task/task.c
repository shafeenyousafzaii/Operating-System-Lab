#include <stdio.h>
#include <stdlib.h>
int main() {
	printf("Creating Directory test \n");
	system("mkdir test");

	printf("Listing Directory Contents \n");
	system("ls");

	printf("Erasing Directory \n");
	system("rmdir test");

	printf("Task Done \n");
	return 0;
}
