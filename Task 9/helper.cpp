#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pfd1[2]; 
    int pfd2[2]; 
    char aString[100];
    char bString[100];
    pipe(pfd1); 
    pipe(pfd2);
    int pid = fork();

    if (pid > 0) {
        
        close(pfd1[0]);
        close(pfd2[1]);

        while (1) {
            printf("P1: ");
            fgets(aString, sizeof(aString), stdin);
            write(pfd1[1], aString, strlen(aString) + 1);
            read(pfd2[0], bString, sizeof(bString));
            printf("P2: %s\n", bString);
        }
    } else if (pid == 0) {
        close(pfd1[1]); 
        close(pfd2[0]); 

        while (1) {
            read(pfd1[0], aString, sizeof(aString));
            printf("P1: %s\n", aString);
            printf("P2: ");
            fgets(bString, sizeof(bString), stdin);
            write(pfd2[1], bString, strlen(bString) + 1);
        }
    }
    
    return 0;
}
