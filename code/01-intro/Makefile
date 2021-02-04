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
	xdg-open image-out.pgm

$(TARGET): main.c pgm.c
	$(CC) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) *.a *.o *~
