
BIN=gcc
CFLAGS=-g -Wall

all: basecon

basecon.o: basecon.c
	$(BIN) $(CFLAGS) -c basecon.c

utils.o: utils.c utils.h
	$(BIN) $(CFLAGS) -c utils.c

basecon: basecon.o utils.o
	$(BIN) $(CFLAGS) basecon.o utils.o -o basecon

clean:
	rm *.o basecon