CC ?= gcc

# Executable names
EXECS = sync_reading sync_writing

# Common helper
HELPER = sem_utils.o

# Source files (assumes each executable has a same-name .c file)
SRCS = $(EXECS:%=%.c) sem_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target: build all executables
all: $(EXECS)

# Rule to build each executable with the helper object
sync_reading: sync_reading.o $(HELPER)
	$(CC) $^ -o $@

sync_writing: sync_writing.o $(HELPER)
	$(CC) $^ -o $@

# Pattern rule to compile any .c to .o
%.o: %.c
	$(CC) -c $< -o $@ -g -Wall

# Clean everything
clean:
	rm -f *.o $(EXECS)

# Fresh build
fresh: clean all

