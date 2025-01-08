#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char user_input [30];

	while(1) {
		printf("Myshell#:~");
		// Complete Line Input
		scanf("%[^\n]s", user_input);
		while (getchar() != '\n');

		if (strcmp(user_input, "listfiles with") == 0) {
			system("ls -l");
		} else if (strcmp(user_input, "showprocesses all") == 0) {
			system("ps aux");
		} else if (strcmp(user_input, "listfiles withp") == 0) {
			system("ls -lh");
		} else if (strcmp(user_input, "exit") == 0) {
			break;
		} else {
			printf("\n Command Not Found \n");
		}
	}
	return 0;
}
