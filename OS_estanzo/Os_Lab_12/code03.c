#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int *array = NULL;
    array = malloc(5*sizeof(*array));
    if (array == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    array[0] = array[1] = array[2] = array[3] = array[4] = 1;
    array = realloc(array, 10*sizeof(*array));
    printf("The Array%d\n", array[0]);
    if (array == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    array[5] = array[6] = array[7] = array[8] = array[9] = 0;
    free(array);
    array = NULL;
}