#include <stdio.h>
#include <stdlib.h>

int main() {
	void f1(void), f2(void), f3(void);
	atexit(f1);
	atexit(f2);
	atexit(f3);

	printf("Getting Ready to Exit \n");

	exit(0);
} 

void f1(void) {
	printf("In f1 \n"); 
	abort();
	exit(0);
}

void f2(void) {
	printf("In f2 \n");
	exit(0);
}

void f3(void) {
	printf("In f3 \n");
	exit(0);
}
