CC = gcc
CFLAGS = -pedantic -Wall -std=c99 -g
MATHLIB = -lm
RM = rm -f

SOURCES_SERVER=server.c
SOURCES_CLIENT=client.c
SERVER=server
CLIENT=client
CPP_SOURCES=$(shell find . -name '*.c')
CPP_OUT=$(CPP_SOURCES:.c=.cpp)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOURCES_SERVER)
	$(CC) $^ -o $@ $(CFLAGS) $(MATHLIB)

$(CLIENT) : $(SOURCES_CLIENT) 
	$(CC) $^ -o $@ $(CFLAGS)

clean: 
	$(RM) $(SERVER) $(CLIENT) quine

check: cpp pvs clean

cpp: $(CPP_OUT)

%.cpp: %.c
	cppcheck --quiet --enable=all --force --inconclusive  $< 2>> out.cppOut

pvs: $(CPP_OUT)  
	./pvs.sh

cleanCheck: 
	$(RM) $(CPP_OUT) *.valout report.tasks rm out.cppOut

.PHONY: all clean check cleanCheck