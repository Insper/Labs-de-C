##
# Project Title
#
# @file
# @version 0.1

TARGET = main
CFLAGS = -g -Wall

build: run

run: $(TARGET)
	./$(TARGET)

$(TARGET): main.c
	$(CC) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) *.a *.o *~
