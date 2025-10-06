# Default to cross-compiler if environment is sourced, otherwise gcc
CC ?= gcc

# Executable names
EXECS = fill_screen fill_screen_fb

# Source files (assumes each executable has a same-name .c file)
SRCS = $(EXECS:%=%.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler/Linker flags
CFLAGS  = -Wall -g -I$(SDKTARGETSYSROOT)/usr/include/libdrm
LDFLAGS = -ldrm

# Default target: build all executables
all: $(EXECS)

# Pattern rule to build any executable from its .o
%: %.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Pattern rule to compile any .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean everything
clean:
	rm -f *.o $(EXECS)

# Fresh build
fresh: clean all
