#include <unistd.h>

int main(void)
{
    char *binaryPath = "/bin/bash";
    char *arg1 = "-c";
    char *arg2 = "echo " Visit $HOSTNAME : $PORT from your browser."";
    char *const env[] = {"HOSTNAME=www.linuxhint.com", "PORT=8080", NULL};

    execle(binaryPath, binaryPath, arg1, arg2, NULL, env);

    return 0;
}

/**
 * Works same as execl() but in this you can pass your own environment variable in it
 * */