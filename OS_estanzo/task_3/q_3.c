#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int calculate_factorial(int number) {
    int s = number;
    for (int i = 1; i < s; i++) {
        number = number * i;
    }  
    return number;
}
int main(int argc, char * argv[]) {
    int number = 0;
    char * path = "factorial.txt";
    int fd[2];
    // pipe(fd);
    printf("Enter a Number: ");
    scanf("%d", &number);
    int fde = open(path, O_CREAT | O_RDWR, 0777);
    if (fde == -1) {
        printf("Error: File No Created \n");
        return 1;
    }
    write(fde, &number, sizeof(int));
    // close(fde);
    int pid = fork();
    if (pid == 0) {
        // child
        int fde = open(path, O_RDWR);
        int num = 0;
        read(fde, &num, sizeof(int));
        num = calculate_factorial(num);
        // printf("num => %d\n", num);
        write(fde, &num, sizeof(int));
        // printf("j=%d\n", num);
        close(fde);
    } else {
        // parent
        wait(NULL);
        int result;
        // int fde = open(path, O_RDONLY);
        read(fde, &result, sizeof(int)); 
        printf("The Result => %d\n", result);
        close(fde);
    }
    return 0;
    }