
BIN=gcc
CFLAGS=-g -Wall

all: basecon

basecon.o: basecon.c
	$(BIN) $(CFLAGS) -c $^

utils.o: utils.c utils.h
	$(BIN) $(CFLAGS) -c $^

basecon: basecon.o utils.o
	$(BIN) $(CFLAGS) $^ -o $@

clean:
	rm *.o *.gch basecon