# Variables
CC = clang
LD = lld
CFLAGS = -Wall -Wextra -O2 -g
LDFLAGS = -fuse-ld=lld
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/main

# Source files
SRCS = main.c board.c

# Object files
OBJS = $(addprefix $(BIN_DIR)/, $(SRCS:.c=.o))

# Default target
all: $(TARGET)

# Create the bin directory if it doesn't exist and link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files to object files, create the bin directory if it doesn't exist
$(BIN_DIR)/%.o: %.c defs.h
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: all clean
