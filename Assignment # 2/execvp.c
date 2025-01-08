// execvp_example.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("using grep to find texstudio and execute it\n");

    // Argument list for 'grep main execvp_example.c'
    char *args[] = { "texstudio", (char *)NULL,"USER=latex_user","PATH=/usr/bin:/bin","CUSTOM_VAR=HelloTeX","HOME=/home/latex_user","DISPLAY=:1"};


    if (execvp("grep", args) == -1) {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}
