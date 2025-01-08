#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct thread_data {
    int x;
    int y;
    int z;
};

void * print(void * threadArg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadArg;
    printf("X: %d, Y: %d, Z: %d \n", my_data->x, my_data->y, my_data->z);
}
int main() {
     struct thread_data omar;
     pthread_t tid;
     omar.x = 1;
     omar.y = 2;
     omar.z = omar.x + omar.y;
     pthread_create(&tid, NULL, print, (void *) &omar);
     pthread_join(tid, NULL);
     return 0;

}