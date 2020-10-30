#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
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

    ERROR_CHECK((serverFd = socket(AF_INET, SOCK_STREAM, 0)), "Socket Failed");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        ERROR_CHECK(-1, "Invalid address/ Address not supported");

    ERROR_CHECK(connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)), "Connection Failed");

    send(socketFd, "entendido\n", strlen("entendido\n"), 0);
    send(socketFd, "itba\n", strlen("itba\n"), 0);                          //se decodifico la imagen
    send(socketFd, "M4GFKZ289aku\n", strlen("M4GFKZ289aku\n"), 0);          //se utilizo forensycs para analizar la image
    send(socketFd, "fk3wfLCm3QvS\n", strlen("fk3wfLCm3QvS\n"), 0);          //con ltrace nos fijamos las syscalls y ver en que momento se producia el error
    send(socketFd, "too_easy\n", strlen("too_easy\n"), 0);                  //se utilizo el comando strings server > cat.txt
    send(socketFd, ".RUN_ME\n", strlen(".RUN_ME\n"), 0);                    //se utilizo objdump -s server
    send(socketFd, "K5n2UFfpFMUN\n", strlen("K5n2UFfpFMUN\n"), 0);          //se utilizo objdump -s server
    send(socketFd, "BUmyYq5XxXGt\n", strlen("BUmyYq5XxXGt\n"), 0);          //estaba escrita ahi
    send(socketFd, "u^v\n", strlen("u^v\n"), 0);                            //se utilizo objdump -s server
    send(socketFd, "chin_chu_lan_cha\n", strlen("chin_chu_lan_cha\n"), 0);  //se utilizo objdump -s server
    send(socketFd, "gdb_rules\n", strlen("gdb_rules\n"), 0);                //se utilizo el edb

    char c;
    char sendbuff[300];
    int i = 0;
    while ((c = getchar()) != '\t') {
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
