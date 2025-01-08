#include <stdio.h>

int main(int argc, char * argv[]) {
	int counter;
	printf("The Name of the Program is %s", argv[0]);
	if (argc == 1) {
		printf("\n No Extra command line arguments passed just only the program is runed");
	}
	if (argc >= 2) {
		for (counter = 0; counter < argc; counter++) {
			printf("\n Arugument No [%d], %s", counter, argv[counter]);
		}
	}
	return 0;
}
