binaries=*.o exec exec_debug

all: release
release: main.o gol.o
	gcc main.o gol.o -o exec
debug: main.o gol.o
	gcc -g -ggdb main.o gol.o -o exec_debug
main.o: main.c
	gcc -c main.c
gol.o: gol.h gol.c
	gcc -c gol.c

.PHONY: clean
clean:
	rm $(binaries)