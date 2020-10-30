CC = gcc
CFLAGS = -pedantic -Wall -std=c99 -g
RM = rm -f

SOURCES_SERVER=server.c
SOURCES_CLIENT=client.c
SERVER=server
CLIENT=client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOURCES_SERVER)
	$(CC) $^ -o $@ $(CFLAGS)

$(CLIENT) : $(SOURCES_CLIENT) 
	$(CC) $^ -o $@ $(CFLAGS)

clean: 
	$(RM) $(SERVER) $(CLIENT) quine

.PHONY: all clean