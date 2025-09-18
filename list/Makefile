# Makefile for Linked List Implementation


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Target executable name
TARGET = list

# Source files
SOURCES = list.c main.c

# Object files (automatically generated from SOURCES)
OBJECTS = $(SOURCES:.c=.o)

# Header files
HEADERS = list.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Force rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug version with additional flags
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release version with optimization
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove generated files"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with optimization"
	@echo "  memcheck - Run with valgrind (requires valgrind)"
	@echo "  help     - Show this help message"

# Declare phony targets
.PHONY: all clean rebuild run debug release memcheck help