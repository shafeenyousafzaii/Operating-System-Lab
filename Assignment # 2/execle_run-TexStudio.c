#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Opening TeXstudio with a custom environment\n");
  
    pid_t pid;
    char *custom_env[] = {
        "USER=latex_user",       // another user for latex
        "PATH=/usr/bin:/bin",    // the path where installed application can be found
        "CUSTOM_VAR=HelloTeX",   // custom variable
        "HOME=/home/latex_user", // Custom home directory
        "DISPLAY=:0",            // Set the display to :1 so that the opened application is opened on the current screen
	NULL
    };
      char *custom_env2[] = {
        "USER=latex_user",       // another user for latex
        "PATH=/usr/bin:/bin",    // the path where installed application can be found
        "CUSTOM_VAR=HelloTeX",   // custom variable
        "HOME=/home/latex_user", // Custom home directory
        "DISPLAY=:1",            // Set the display to :1 so that the opened application is opened on the current screen
	NULL
    };
    pid=fork();
    if(pid==0){
    // Replace the current process with the TeXstudio command
    if (execle("/usr/bin/texstudio", "texstudio", (char *)NULL, custom_env) == -1) {
    	
        perror("execle failed for display variable 0");
        sleep(1);
        exit(EXIT_FAILURE);
    }
    }
    else{
    sleep(2);
    printf("Running the command with display variable set to 1");
    if (execle("/usr/bin/texstudio", "texstudio", (char *)NULL, custom_env2) == -1) {
        perror("execle failed");
        exit(EXIT_FAILURE);
    }

    // This line will not be executed if execle is successful
    printf("If you see this, execle failed\n");
    return 0;
}
}

