##
# Project Title
#
# @file
# @version 0.1
CFLAGS = -g -Wall

.PHONY: clean tarefa1 tarefa2 tarefa3 tarefa4 

tarefa1: tarefa1.c
	gcc $(CFLAGS) tarefa1.c  -o tarefa1 -lsystemd -lcurl
	./tarefa1

tarefa2: tarefa2.c
	gcc $(CFLAGS) tarefa2.c  -o tarefa2 -lsystemd -lcurl
	./tarefa2

tarefa3: tarefa3.c
	gcc $(CFLAGS) tarefa3.c  -o tarefa3 -lsystemd -lm -lcurl
	./tarefa3

tarefa4: tarefa4.c
	gcc $(CFLAGS) tarefa4.c  -o tarefa4 -lsystemd -lcurl
	./tarefa4

clean:
	rm -f $(TARGET) *.a *.o *~ tarefa1 tarefa2 tarefa3 tarefa4 

