CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -std=c99

.PHONY: all test debug release clean test

all: debug

release : CFLAGS += -O3
release : gol

debug : CFLAGS += -g -O0
debug : gol

test: CFLAGS += -g -O3
test: gol_test
	valgrind --leak-check=full ./gol_test

gol: main.o gol.o
	$(CC) main.o gol.o -o gol

gol_test: mem_test.o gol.o
	$(CC) mem_test.o gol.o -o gol_test

main.o: main.c gol.h
	$(CC) -c main.c
mem_test.o: mem_test.c gol.h
	$(CC) -c mem_test.c

gol.o: gol.c gol.h
	$(CC) -c gol.c

clean:
	rm *.o
	rm gol
	rm gol_test