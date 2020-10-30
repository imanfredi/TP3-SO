CC = gcc
CFLAGS = -pedantic -Wall -std=c99 -g
RM = rm -f

SOURCES = $(wildcard *.c)
BINS = $(SOURCES:.c=.out)

all: $(BINS)

%.out: %.c
	$(CC) $^ -o $@ $(CFLAGS)

clean: 
	$(RM) $(BINS)

.PHONY: all clean