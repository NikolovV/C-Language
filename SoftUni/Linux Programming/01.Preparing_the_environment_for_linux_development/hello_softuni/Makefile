
CC=gcc
CFLAGS=-g -Wall

program: main.o samplefunc.o
	$(CC) $(CFLAGS) -o program obj/main.o obj/samplefunc.o

main.o: main.c
	mkdir -p obj
	mkdir -p inc
	$(CC) $(CFLAGS) -c main.c -o obj/main.o

samplefunc.o: samplefunc.c
	$(CC) $(CFLAGS) -c samplefunc.c -o obj/samplefunc.o
