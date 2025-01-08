#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int length = 0;
    int pid = 1;
    int pfd[2];
    char fileContent[20];
    pipe(pfd);
    while (1)
    {
        if (pid == 0)
        {
            // Reading From pipe and writing to the output file
            read(pfd[0], fileContent, length - 1);
            FILE *out = fopen("output.txt", "w");
            fputs(fileContent, out);
            fclose(out);
            printf("Written From Input File To Output File\n");
            return 0;
        }
        else
        {
            if (pid != 1)
                return 0;
            FILE *ptr;
            char ch;
            // Reading The Input File
            ptr = fopen("input.txt", "r");

            if (NULL == ptr)
            {
                printf("file can't be opened \n");
            }
            // Parent Process is Writing To A PIPE
            do
            {
                ch = fgetc(ptr);
                write(pfd[1], &ch, 1);
                length += 1;
            } while (ch != EOF);
            fclose(ptr);
            pid = fork();
        }
    }
    return 0;
}