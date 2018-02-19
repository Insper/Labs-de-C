CFLAGS = -Wall -pedantic -Og -std=c99

main.o: main.c modulo1.h
	gcc -c $(CFLAGS) main.c

modulo1.o: modulo1.c modulo1.h
	gcc -c $(CFLAGS) modulo1.c

executavel: main.o modulo1.o
	gcc main.o modulo1.o -o exemplo1-make

