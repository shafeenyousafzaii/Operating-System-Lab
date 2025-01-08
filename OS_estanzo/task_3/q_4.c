#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int length = 0;
int main(int argc, char * argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        printf("Error Occured While Creating Pipe \n");
        return 1;
    }

    char * input_file = argv[1];            // file to be copied
    char * output_file = argv[2];           // destination

    char read_data[length];
    FILE *ptr;
    char ch;

   
    int pid = fork();
    if (pid == 0) {

        read(fd[0], read_data, 6 );
        ptr = fopen(output_file, "w");
        if (ptr == NULL) {
            printf("File Not Opened \n");
            return 2;
        }
        fprintf(ptr, "%s", read_data);
        fclose(ptr);
        return 3;

    } else {
        // All the content of input_file is written to the file
        ptr = fopen(input_file, "r");
            if (NULL == ptr) {
                printf("file can't be opened \n");
            }

            // Writing in a pipe
            do {
                ch = fgetc(ptr);
                write(fd[1], &ch, 1);
                length += 1;
            } while(ch != EOF);
            close(fd[0]);     // read
            close(fd[1]);     // write
            fclose(ptr);
    }

    return 0;
}