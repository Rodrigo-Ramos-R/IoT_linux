CC ?= gcc

# Executable names
EXECS = stream_char_test stream_string_test fwrite_test fread_test

# Source files (assumes each executable has a same-name .c file)
SRCS = $(EXECS:%=%.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Library directories (if needed)
LIB_DIRS = .

# Default target: build all executables
all: $(EXECS)

# Pattern rule to build any executable from its .o
%: %.o
	$(CC) $^ -o $@ -L$(LIB_DIRS)

# Pattern rule to compile any .c to .o
%.o: %.c
	$(CC) -c $^ -o $@ -g -Wall

# Clean everything
clean:
	rm -f *.o $(EXECS)

# Fresh build
fresh: clean all
