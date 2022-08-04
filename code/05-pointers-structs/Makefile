##
# Project Title
#
# @file
# @version 0.1
CFLAGS = -g -Wall

.PHONY: clean tarefa3 tarefa6


tarefa3: tarefa3.c
	gcc $(CFLAGS) tarefa3.c  -o tarefa3 -lsystemd -lm -lcurl
	./tarefa3

tarefa6: tarefa6.c
	gcc $(CFLAGS) tarefa6.c  -o tarefa6 -lsystemd -lcurl
	./tarefa6

clean:
	rm -f $(TARGET) *.a *.o *~ tarefa3 tarefa6

