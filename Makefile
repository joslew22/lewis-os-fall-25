# Makefile for main3.c
CC = gcc
CFLAGS = -Wall -g
TARGET = my3proc
SOURCE = main3.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run