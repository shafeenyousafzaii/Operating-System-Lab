#include <unistd.h>

int main(void)
{
    char *programName = "ls";
    char *args[] = {programName, "-lh", "/home", NULL};

    execvp(programName, args);

    return 0;
}

/**
 * Works same as the execv but in this the full path of the binary file is not required
 * Becuase it stores the Environment Variable
 * */
