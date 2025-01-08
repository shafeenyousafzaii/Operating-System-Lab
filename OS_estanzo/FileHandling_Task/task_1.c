#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int fd = open("mymessage.txt", O_RDONLY | O_CREAT, 0666 );
	char buffer[200];
	buffer[0] = '?';
	read(fd, buffer, 200);
	if (buffer[0] == '?') {
		printf("File Empty/Created with Given File Permission\n");
		return 1;
	}
	printf("The content of the file => %s\n", buffer);
	close(fd);
	return 0;
}