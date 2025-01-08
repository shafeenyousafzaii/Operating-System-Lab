#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Opening TeXstudio with a custom environment\n");
  
    pid_t pid;
    pid=fork();
    if(pid==0){
    printf("This is the parent process with pid : %d \n", getppid());
    printf("Calculating division of two numbers : \n");
    int x = 10;
    float y =  2;
    float div=x/2;
    printf("Answer : %f \n",div);
    }
    else{
    sleep(2);
    printf("Running the command with display variable set to 1");
    if (execlp("/usr/bin/texstudio", "texstudio","USER=latex_user","PATH=/usr/bin:/bin","CUSTOM_VAR=HelloTeX","HOME=/home/latex_user","DISPLAY=:1", (char *)NULL) == -1) {
        perror("execle failed");
        exit(EXIT_FAILURE);
    }

    printf("If you see this, execle failed\n");
    return 0;
}
}

