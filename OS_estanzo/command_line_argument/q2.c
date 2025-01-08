#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char user_choice[20];
	while(1) {
		printf("Myshell#:~");
		scanf("%s", user_choice);
		if (strcmp(user_choice, "showprocesses") == 0) {
			system("ps");
		} else if (strcmp(user_choice, "listfiles") == 0) {
			system("ls");
		} else if (strcmp(user_choice, "about_system") == 0) {
			system("neofetch");
		}else if (strcmp(user_choice, "exit") == 0) {
			break;
		} else {
			printf("Wrong Command Entered\n");
		}
		printf("\n");
	}
	return 0;
}
