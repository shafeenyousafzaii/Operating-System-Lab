#include <stdio.h>
#include <stdlib.h>
int main() {
	char name[20];
	printf("Enter Name: ");
	fgets(name, 20, stdin);
	printf("Hello \n %s", name);
	system("ls");
	return 0;
}
