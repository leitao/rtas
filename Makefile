CC=gcc
CFLAGS=-g

rtas: rtas.o
	$(CC) -o rtas rtas.o
