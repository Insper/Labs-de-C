##
# Project Title
#
# @file
# @version 0.1
CFLAGS = -g -Wall

.PHONY: clean main tarefa1 tarefa2 tarefa3 tarefa4 tarefa5

main: main.c
	gcc $(CFLAGS) main.c  -o main
	./main

tarefa1: tarefa1.c
	gcc $(CFLAGS) tarefa1.c  -o tarefa1 -lsystemd
	./tarefa1

tarefa2: tarefa2.c
	gcc $(CFLAGS) tarefa2.c  -o tarefa2 -lsystemd
	./tarefa2

tarefa3: tarefa3.c
	gcc $(CFLAGS) tarefa3.c  -o tarefa3 -lsystemd -lm
	./tarefa3

tarefa4: tarefa4.c
	gcc $(CFLAGS) tarefa4.c  -o tarefa4 -lsystemd
	./tarefa4

tarefa5: tarefa5.c
	gcc $(CFLAGS) tarefa5.c  -o tarefa5 -lsystemd
	./tarefa5

tarefa6: tarefa6.c
	gcc $(CFLAGS) tarefa6.c  -o tarefa6 -lsystemd
	./tarefa6

tarefa7: tarefa7.c
	gcc $(CFLAGS) tarefa7.c  -o tarefa7 -lsystemd
	./tarefa7

clean:
	rm -f $(TARGET) *.a *.o *~ tarefa1 tarefa2 tarefa3 tarefa4 tarefa5

