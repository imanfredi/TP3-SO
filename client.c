// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
#define ERROR_CHECK(x, msg)                                                                              \
    do {                                                                                                 \
        int retval = (x);                                                                                \
        if (retval == -1) {                                                                              \
            fprintf(stderr, "Runtime error: %s returned %d at %s:%d\n", #x, retval, __FILE__, __LINE__); \
            perror(msg);                                                                                 \
            exit(-1);                                                                                    \
        }                                                                                                \
    } while (0)

int main(int argc, char const *argv[]) {
    int socketFd = 0;
    struct sockaddr_in serv_addr;

    ERROR_CHECK((socketFd = socket(AF_INET, SOCK_STREAM, 0)), "Socket Failed");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        ERROR_CHECK(-1, "Invalid address/ Address not supported");

    ERROR_CHECK(connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)), "Connection Failed");


    int c;
    char sendbuff[300];
    int i = 0;
    while ((c = getchar()) != EOF) {
        sendbuff[i++] = c;
        if (c == '\n') {
            sendbuff[i] = 0;
            printf("%s", sendbuff);
            send(socketFd, sendbuff, strlen(sendbuff), 0);
            i = 0;
        }
    }

    return 0;
}
