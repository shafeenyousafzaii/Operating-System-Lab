#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    char * filename = argv[1];
    int fd = open(filename, O_RDONLY | O_CREAT);
    if (fd == -1) {
        printf("Unable to Open the File \n");
        return 1;
    }
    char buffer[40];
    read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    printf("%s\n", buffer);
    return 0;
}