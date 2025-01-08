#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;

int main() {
    // key
    key_t key = ftok("shmfile", 65);

    // create the shared memeory
    int shmid;
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // attach process to shared memory
    char * str = (char *) shmat(shmid, (void *) 0, 0);
    cout << "Write data: ";
    cin.getline(str, 50);

    printf("Data Written is : %s\n", str);

    // detach to the shared memory
    shmdt(str);
    return 0;
}