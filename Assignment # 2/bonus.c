// simple_mini_shell.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024    // Maximum length of the input line
#define MAX_ARG_COUNT 64       // Maximum number of arguments

int main() {
    char input[MAX_INPUT_SIZE];   
    char *args[MAX_ARG_COUNT];    
    pid_t pid;                     
    int status;                  
    printf("1 ) Enter ""texstudio"" to open texstudio\n");
    printf("2 ) Enter ""file"" to create a new file in current directory\n");
    printf("3 ) Enter ""-ls"" to perform ls -i in the mini shell\n");
    do{

        // 1. Read: Display prompt and get user input ; using Sir.Muhammad Nouman's given logic of read, eval , execute , loop. 
        printf("Shell >  ");
        fflush(stdout);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Skip empty input
        if (strlen(input) == 0) {
            continue;
        }

        // 2. Eval: Parse the input into command and arguments
        int arg_index = 0;
        args[arg_index] = strtok(input, " ");
        while (args[arg_index] != NULL && arg_index < MAX_ARG_COUNT - 1) {
            args[++arg_index] = strtok(NULL, " ");
        }
        args[arg_index] = NULL; 

        // Handle built-in 'exit' command
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting mini-shell.\n");
            break;
        }
        pid_t pid;
        pid=fork();
        if(pid==0){
        if (strcmp(args[0], "texstudio") == 0) {
            char *args[] = { "texstudio", (char *)NULL,"USER=latex_user","PATH=/usr/bin:/bin","CUSTOM_VAR=HelloTeX","HOME=/home/latex_user","DISPLAY=:1" };
            execv("/usr/bin/texstudio", args);
            break;
        }}
        sleep(2);
        
        pid_t pid2;
        pid2=fork();
                if(pid2==0){
        if (strcmp(args[0], "-ls") == 0) {
            execl("/bin/ls", "sudo ls", "-l", "/media/shafeenyousafzai/OLDERDRIVE/Semester 5/Operating-System-Lab/Assignment # 2", (char *)NULL);
            break;
        }
        }
        sleep(2);
	
	pid_t pid3;
        pid3=fork();
                if(pid3==0){
        if (strcmp(args[0], "file") == 0) {
            execl("/bin/touch", "touch", "/media/shafeenyousafzai/OLDERDRIVE/Semester 5/Operating-System-Lab/Assignment # 2/file.txt", (char *)NULL);
            break;
        }
        }
        sleep(2);
        // 3. Execute the command
        pid = fork(); 

        if (pid < 0) {
            perror("fork failed");
            continue;
        }

        if (pid == 0) {
            //  Execute the command
            if (execvp(args[0], args) == -1) {
                perror("exec failed");
            }
            exit(EXIT_FAILURE); 
        } else {
            // Wait for the child to finish
            do {
                if (waitpid(pid, &status, WUNTRACED) == -1) {
                    perror("waitpid failed");
                    break;
                }
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }while(1);

    return 0;
}

