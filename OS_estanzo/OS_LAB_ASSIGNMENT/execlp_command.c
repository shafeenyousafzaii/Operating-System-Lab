#include <unistd.h>

int main(void)
{
    char *programName = "ls";
    char *arg1 = "-lh";
    char *arg2 = "/home";

    execlp(programName, programName, arg1, arg2, NULL);

    return 0;
}
/**
 * execlp doesnot use PATH environment variable so not need to pass the complete path of it for the command execlp
 * not required, so if the executable file is available in path so complete path not needed for these commands
 *
 * */