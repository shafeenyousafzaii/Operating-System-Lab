#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    char message[25] = "Hello How Are You.";
    char *filename = argv[1];
    int fd = open(filename, O_CREAT, 7777);
    if (fd == -1) {
        printf("Unable to Create A File\n");
        return 1;
    }
    printf("File Created With Descriptor %d\n", fd);
    return 0;
}