CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test debug release clean

all: debug

release : CFLAGS += -O3
release : gol

debug : CFLAGS += -g -O0
debug : gol

gol: main.o gol.o
	$(CC) main.o gol.o -o gol

main.o: main.c gol.h
	$(CC) -c main.c

gol.o: gol.c gol.h
	$(CC) -c gol.c

clean:
	rm *.o
	rm gol