##
# Project Title
#
# @file
# @version 0.1

CFLAGS = -g -Wall
.PHONY: clean tarefa1 tarefa2 tarefa3 tarefa4 tarefa5

tarefa1: tarefa1.c main.c
	gcc $(CFLAGS) -DSOLUTIONFILE=\"tarefa1.c\" pgm.c main.c  -o tarefa1 
	./tarefa1
	xdg-open image-out.pgm

tarefa2: tarefa2.c main.c
	gcc $(CFLAGS) -DSOLUTIONFILE=\"tarefa2.c\" pgm.c main.c  -o tarefa2 
	./tarefa2
	xdg-open image-out.pgm

tarefa3: tarefa3.c main.c
	gcc $(CFLAGS) -DSOLUTIONFILE=\"tarefa3.c\" pgm.c main.c  -o tarefa3 
	./tarefa3
	xdg-open image-out.pgm

tarefa4: tarefa4.c main.c
	gcc $(CFLAGS) -DSOLUTIONFILE=\"tarefa4.c\" pgm.c main.c  -o tarefa4 
	./tarefa4
	xdg-open image-out.pgm

tarefa5: tarefa5.c main.c
	gcc $(CFLAGS) -DSOLUTIONFILE=\"tarefa5.c\" pgm.c main.c  -o tarefa5
	./tarefa5
	xdg-open image-out.pgm

clean:
	rm -f $(TARGET) *.a *.o *~ tarefa1 tarefa2 tarefa3 tarefa4 tarefa5
