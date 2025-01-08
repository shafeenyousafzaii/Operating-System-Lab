
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    char msg[20];
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    while (1)
    {
        printf("P2:");
        scanf("%s", msg);
        printf("\nP2 Says: %s\n", msg);

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("\n Socket creation error \n");
            return -1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
            printf(
                "\nInvalid address/ Address not supported \n");
            return -1;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr,
                    sizeof(serv_addr)) < 0)
        {
            printf("\nConnection Failed \n");
            return -1;
        }
        send(sock, msg, strlen(msg), 0);
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
    }
    return 0;
}
