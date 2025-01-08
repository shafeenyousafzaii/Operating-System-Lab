// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
#define MAX 50
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
int main() {
    key_t key;
    int msgid;
    // ftok to generate unique key
    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Write Data : ");
    fgets(message.mesg_text,MAX,stdin);

    msgsnd(msgid, &message, sizeof(message), 0);

    
    return 0;
}