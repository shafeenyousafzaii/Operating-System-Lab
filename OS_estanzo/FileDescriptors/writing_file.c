#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    char * filename = argv[1];
    int fd = open(filename, O_WRONLY | O_CREAT);
    if (fd == -1) {
        printf("Unable to Create/Open A file\n");
        return 1;
    }
    char data[20] = "My Name is Jawad";
    write(fd, data, 20);
    close(fd);
    return 0;
}