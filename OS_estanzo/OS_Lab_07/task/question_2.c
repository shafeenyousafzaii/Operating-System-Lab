#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    char *filename = argv[1];
    char *msg = argv[2];
    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
    size_t length = strlen(msg);
    write(fd, msg, length);
    close(fd);
    return 0;
}