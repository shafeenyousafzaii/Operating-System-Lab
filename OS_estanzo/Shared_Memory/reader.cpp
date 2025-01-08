#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;

int main() {
    key_t key = ftok("shmfile", 65);

    // shared memory
    int shmid;
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // attach 
    char * str = (char *) shmat(shmid, (void *) 0, 0);

    printf("Data Readed => %s\n", str); 

    // detach
    shmdt(str);

    // Delete the sahred memroy
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}