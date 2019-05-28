all: main.o gol.o
	gcc main.o gol.o -o exec
main: main.c
	gcc -c main.c
gol: gol.h gol.c
	gcc -c gol.c
clean: exec
	rm main.o gol.o