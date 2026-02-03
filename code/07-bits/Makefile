SHELL = /bin/bash
TARGET = exercicios
INFRA_DIR := ../infra/

all: log astyle-check cpp-check run

run: $(TARGET)
	@./$(TARGET); exit "$$?"

$(TARGET): exercicios.o
	gcc -Wall -Og -std=c99 $^ -o $@
%.o : %.c
	gcc -g -Wall -I$(INFRA_DIR) -c $< -o $@

log:
	@git add exercicios.c > /dev/null
	@git commit -m "Tentativa de resolução: " $(basename $(PWD)) > /dev/null

cpp-check:
	$(INFRA_DIR)check-cppcheck.sh .

astyle-check: $(wildcard *.c)
	$(INFRA_DIR)check-astyle.sh $^

clean:
	rm -f $(TARGET) *.a *.o *~
