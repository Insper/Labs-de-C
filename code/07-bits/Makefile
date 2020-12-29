SHELL = /bin/bash
TARGET = exercicios
INFRA_DIR := ../infra/

CPPCHECK := 0

all: log run

run: $(TARGET)
	@./$(TARGET); exit "$$?"

$(TARGET): exercicios.o
	gcc -Wall -Og -std=c99 $^ -o $@
%.o : %.c
	gcc -g -Wall -I$(INFRA_DIR) -c $< -o $@

log:
	@git add exercicios.c > /dev/null
	@git commit -m "Tentativa de resolução: lab 7." > /dev/null

cppcheck:
	$(INFRA_DIR)check-cppcheck.sh .

clean:
	rm -f $(TARGET) *.a *.o *~
