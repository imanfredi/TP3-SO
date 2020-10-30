// Server side C/C++ program to demonstrate Socket programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
#define CHALLENGES 12
#define ANSWER_SIZE 50

static void challenge0();
static void challenge1();
static void challenge2();
static void challenge3();
static void challenge4();
static void challenge5();
static void challenge6();
static void challenge7();
static void challenge8();
static void challenge9();
static void challenge10();
static void challenge11();

static void clearScreen();
static void challengeMessage();
static void researchMessage();
static int processAnswer(char *answer, char *received);

typedef struct {
    void (*message)();
    char answer[ANSWER_SIZE];
} challenge_t;

static challenge_t challenges[CHALLENGES] = {{&challenge0, "entendido\n"}, {&challenge1, "itba\n"}, {&challenge2, "M4GFKZ289aku\n"},
                                                             {&challenge3, "fk3wfLCm3QvS\n"},{&challenge4, "too_easy\n"}, {&challenge5, ".RUN_ME\n"}, 
                                                             {&challenge6, "K5n2UFfpFMUN\n"}, {&challenge7, "BUmyYq5XxXGt\n"}, {&challenge8, "u^v\n"}, 
                                                             {&challenge9, "chin_chu_lan_cha\n"}};

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    int current = 0;
    while (current < CHALLENGES) {
        challenge_t challenge = challenges[current];
        (challenge.message)();
        valread = read(new_socket, buffer, 1024);
        buffer[valread] = 0;
        printf("Recibi: %s", buffer);
        current += processAnswer(challenge.answer, buffer);
    }

    return 0;
}

static void challenge0() {
    challengeMessage();
    printf("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n");
    printf("En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n");
    printf("Además tendrán que investigar otras preguntas para responder durante la defensa.\n");
    printf("El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos.\n");
    printf("No basta con esperar la respuesta.\n");
    printf("Además, deberán implementar otro programa para comunicarse conmigo.\n\n");
    printf("Deberán estar atentos a los easter eggs\n\n");
    printf("Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n");
    researchMessage();
    printf("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n");
}


static void challenge1() {
    challengeMessage();
    printf("The Wire S1E5\n");
    printf("5295 888 6288\n\n");
    researchMessage();
    printf("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");
}

static void challenge2() {
    challengeMessage();
    printf("https://ibb.co/tc0Hb6w\n");
    researchMessage();
    printf("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");
}

static void challenge3() {
    challengeMessage();
    printf("EBADF...\n\n");
    printf("write: Bad file descriptor...\n\n");

    researchMessage();
    printf("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n");
}

static void challenge4() {
    challengeMessage();
    printf("respuesta = strings: 277\n\n");
    researchMessage();
    printf("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");
}

static void challenge5() {
    challengeMessage();
    printf(".data .bss .comment ? .shstrtab .symtab .strtab\n\n");
    researchMessage();
    printf("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n");
}

static void challenge6() {
    challengeMessage();
    printf("Filter error");
    printf("Mensaje filtrado\n\n");
    researchMessage();
    printf("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");
}

static void challenge7() {
    challengeMessage();
    printf("¿?\n\n");
    printf("La respuesta es BUmyYq5XxXGt\n\n");
    researchMessage();
    printf("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n");
}

static void challenge8() {
    challengeMessage();
    printf("Latexme\n\n");
    printf("Si\n \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u}) entonces\ny =");
    researchMessage();
    printf("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");
}

static void challenge9() {
    challengeMessage();
    printf("quine\n\n");
    researchMessage();
    printf("¿Cuáles son las características del protocolo SCTP?\n");
}

static void challengeMessage() {
    printf("\n------------- DESAFIO -------------\n");
}

static void researchMessage() {
    printf("\n----- PREGUNTA PARA INVESTIGAR -----\n");
}

static int processAnswer(char *answer, char *received) {
    int ans = 1;
    if (strcmp(answer, received) != 0) {
        printf("\nWrong answer: %s\n", received);
        sleep(2);
        ans = 0;
    }
    clearScreen();
    return ans;
}

static void clearScreen() {
    printf("\033{1;1H\033[2J");
}