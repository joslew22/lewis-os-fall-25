# Makefile for signal handling programs
CC = gcc
CFLAGS = -Wall

# Build all signal programs
all: signals signal1 signal2 timer

# Original signal program
signals: signal.c
	$(CC) $(CFLAGS) -o signals signal.c

# Problem 1: signal1
signal1: signal1.c
	$(CC) $(CFLAGS) -o signal1 signal1.c

# Problem 2: signal2
signal2: signal2.c
	$(CC) $(CFLAGS) -o signal2 signal2.c

# Problem 3: timer
timer: timer.c
	$(CC) $(CFLAGS) -o timer timer.c

# Clean all executables
clean:
	rm -f signals signal1 signal2 timer

# Run each program
run-signals: signals
	./signals

run-signal1: signal1
	./signal1

run-signal2: signal2
	./signal2

run-timer: timer
	./timer

.PHONY: all clean run-signals run-signal1 run-signal2 run-timer