#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int fd = open("mymessage.txt", O_WRONLY);
    if (fd == -1) {
        printf("Error Occured\n");
        return 1;
    }
    char usr_txt[200];
    int length;

    printf("Enter the Data: ");
    scanf("%[^\n]s", usr_txt);
	while (getchar() != '\n') {
        length++;
    }

    write(fd, usr_txt, length);
    printf("Data Written Successfully\n");
    close(fd);
    return 0;
}  