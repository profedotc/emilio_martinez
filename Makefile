binaries=*.o exec

all: main.o gol.o
	gcc main.o gol.o -o exec
main.o: main.c
	gcc -c main.c
gol.o: gol.h gol.c
	gcc -c gol.c

.PHONY: clean
clean:
	rm $(binaries)