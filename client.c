#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
    int socketFd = 0;
    struct sockaddr_in serv_addr;
    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }

  //  send(socketFd, "entendido\n", strlen("entendido\n"), 0);
   /* send(socketFd, "itba\n", strlen("itba\n"), 0);                  //se decodifico la imagen
    send(socketFd, "M4GFKZ289aku\n", strlen("M4GFKZ289aku\n"), 0);  //se utilizo forensycs para analizar la image
    send(socketFd, "fk3wfLCm3QvS\n", strlen("fk3wfLCm3QvS\n"), 0);  //con ltrace nos fijamos las syscalls y ver en que momento se producia el error
    send(socketFd, "too_easy\n", strlen("too_easy\n"), 0);          //se utilizo el comando strings server > cat.txt
    send(socketFd, ".RUN_ME\n", strlen(".RUN_ME\n"), 0);            //se utilizo objdump -s server
    send(socketFd, "K5n2UFfpFMUN\n", strlen("K5n2UFfpFMUN\n"), 0);  //se utilizo objdump -s server
    send(socketFd, "BUmyYq5XxXGt\n", strlen("BUmyYq5XxXGt\n"), 0);  //estaba escrita ahi
    send(socketFd, "u^v\n", strlen("u^v\n"), 0);                    //se utilizo objdump -s server
    //creamos el archivo
    //copiamos el codigo correspondiente en quine.c
    send(socketFd, "chin_chu_lan_cha\n", strlen("chin_chu_lan_cha\n"), 0);  //se utilizo objdump -s server

*/
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


