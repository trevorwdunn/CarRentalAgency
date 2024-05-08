# Compiler
CC := g++

# Compiler flags
CFLAGS := -Wall -Wextra -pedantic -std=c++11

# Source files
SRCS := main.cpp car.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable
TARGET := main

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)