#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
if (argc != 2)
{
printf("Error: Run like this: ");
printf("%6s name-of-new-file\n", argv[0]);
return 1;
}
char *path = argv[1];
int i = 0;
while(i<2)
{
int fd = open(path, O_WRONLY | O_CREAT);
printf("Created! Descriptor is %d\n", fd);
//close(fd);
i++;
}
return 0;
}
