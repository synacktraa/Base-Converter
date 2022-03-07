basecon: basecon.o utils.o
	gcc basecon.c utils.o -o basecon

basecon.o: basecon.c
	gcc -c basecon.c

utils.o: utils.c
	gcc -c utils.c

clean: 
	rm *.o basecon