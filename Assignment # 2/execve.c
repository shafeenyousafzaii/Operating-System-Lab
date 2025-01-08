// execve_example.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Before execve: Displaying environment variables using 'printenv'\n");


    char *args[] = { "texstudio", (char *)NULL,"USER=latex_user","PATH=/usr/bin:/bin","CUSTOM_VAR=HelloTeX","HOME=/home/latex_user","DISPLAY=:1" };
	 char *custom_env2[] = {
        "USER=latex_user",       
        "PATH=/usr/bin:/bin",   
        "CUSTOM_VAR=HelloTeX",  
        "HOME=/home/latex_user", 
        "DISPLAY=:1",           
	NULL
    };

    
    pid_t pid;
	pid=fork();
    if(pid==0){
    // Replace the current process with the TeXstudio command
    if (execve("/usr/bin/texstudio", args, custom_env2) == -1) {
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
    }
    else{
    sleep(3);
    printf("Running the command with display variable set to 1");
    if (execve("/usr/bin/texstudio", args, custom_env2) == -1) {
        perror("execve failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
}

