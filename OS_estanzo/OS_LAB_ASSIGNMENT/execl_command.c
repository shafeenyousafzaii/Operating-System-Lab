#include <unistd.h>

int main(void)
{
    char *binaryPath = "/bin/ls";
    char *arg1 = "-lh";
    char *arg2 = "/home";

    execl(binaryPath, binaryPath, arg1, arg2, NULL);

    return 0;
}
/**
 * execl command takes the binary executable file as a first argument, and next arguments
 * -lh /home will be passed as next arguements followed by NULL
 * execl command runs the command and prints to output
 * */