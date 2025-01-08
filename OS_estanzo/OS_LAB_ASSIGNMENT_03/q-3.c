#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int findFactorial(int num)
{
    int i, f = 1;

    for (i = 1; i <= num; i++)
        f = f * i;

    return f;
}
int main()
{
    int pid = 1;
    int number;
    int num;
    FILE *fptr;

    int flg = 0;

    fptr = fopen("fac.txt", "w");

    if (fptr == NULL)
    {
        printf("Error!");
        return 0;
    }

    printf("Enter Number=> ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);
    pid = fork();
    if (pid == 0)
    {
        // Child
        num = findFactorial(num);
        fptr = fopen("fac.txt", "w");
        fprintf(fptr, "%d", num);
        fclose(fptr);
    }
    else
    {
        wait(NULL);
        FILE *ptr;
        char ch;

        // Opening file in reading mode
        ptr = fopen("fac.txt", "r");

        if (NULL == ptr)
        {
            printf("file can't be opened \n");
        }

        printf("Factorial OF the num => ");

        do
        {
            ch = fgetc(ptr);
            printf("%c", ch);

        } while (ch != EOF);
        printf("\n");
        fclose(ptr);
    }
    return 0;
}