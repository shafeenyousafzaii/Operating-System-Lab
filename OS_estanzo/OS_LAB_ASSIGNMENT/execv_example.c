#include <unistd.h>

int main(void)
{
    char *binaryPath = "/bin/ls";
    char *args[] = {binaryPath, "-lh", "/home", NULL};

    execv(binaryPath, args);

    return 0;
}

/**
 * In a execv you can pass all the parameters in a NULL terminated array argv
 * First element of the array should be the path of the binary file
 * Otherwise the execv function works as the execl function
 * */