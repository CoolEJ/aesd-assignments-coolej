# Compiler (supports cross-compilation)
CC := $(CROSS_COMPILE)gcc

# Compiler flags
CFLAGS := -Wall -Werror

# Target executable
TARGET := writer

# Default target
all: $(TARGET)

# Build writer
$(TARGET): writer.o
	$(CC) $(CFLAGS) writer.o -o $(TARGET)

# Compile object file
writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c

# Clean target
clean:
	rm -f $(TARGET) *.o
