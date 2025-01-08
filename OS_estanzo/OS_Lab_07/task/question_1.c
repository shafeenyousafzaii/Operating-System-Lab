#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Run like this: ");
        printf("%6s name-of-existing-file\n",
               argv[0]);

        return 1;
    }
    char *path = argv[1];
    mode_t old_mask = umask(0);
    int fd = open(path, O_EXCL);
    if (fd > 2)
    {
        char buffer[200];
        read(fd, buffer, sizeof(buffer) - 1);
        printf("Contents of File are:\n");
        printf("%s\n", buffer);
        close(fd);
    }
    if (fd == -1)
    {
        int fd = open(path, O_WRONLY | O_CREAT);
        printf("Created! Descriptor is %d\n", fd);
        close(fd);
    }

    return 0;
}