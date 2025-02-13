# Define directories
SRC_DIR := src
HEADER_DIR := header

# Source and header files
SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -I$(HEADER_DIR)

# Output executable
OUTPUT := tema1

# Default target
all: build

# Compilation rule
build: $(SOURCE_FILES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCE_FILES)

# Run program
run: build
	./$(OUTPUT)

# Cleanup rule
clean:
	rm -rf $(OUTPUT) tema1.in tema1.out 

# Check using checker script
check: build
	./checker.sh
