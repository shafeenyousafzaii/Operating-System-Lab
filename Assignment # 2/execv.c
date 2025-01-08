// execv_example.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Running Execve to run texstudio app : ");

    char *args[] = { "texstudio", (char *)NULL,"USER=latex_user","PATH=/usr/bin:/bin","CUSTOM_VAR=HelloTeX","HOME=/home/latex_user","DISPLAY=:1" };


    pid_t pid;
	pid=fork();
    if(pid==0){
    // Replace the current process with the TeXstudio command
    if (execv("/usr/bin/texstudio", args) == -1) {
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    }
    else{
    sleep(3);
    printf("Running the command with display variable set to 1");
    if (execv("/usr/bin/texstudio", args) == -1) {
        perror("execv failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
}
