#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	int counter;
	if (argc == 1) {
		printf("No Extra Command Passed to Be Executed\n");
		return 0;
	} 
	if (argc >= 2) {
			if (strcmp(argv[1], "showprocesses") == 0) {
				system("ps");
			} else if (strcmp(argv[1], "listfiles") == 0) {
				system("ls");
			} else if (strcmp(argv[1], "listfiles_withpermission") == 0) {
				system("ls -l");
			} else {
				printf("Hello \n%s", argv[counter]);
				printf("Wrong Command Entered \n");
			}
		}
	return 0;
}
