CC ?= gcc
CFLAGS = -g -Wall

# Executable names
EXECS = simple_pipe main reader_process writer_process

# Sources per executable
simple_pipe_SRCS   = simple_pipe.c
main_SRCS          = main.c processes.c
reader_process_SRCS = reader_process.c
writer_process_SRCS = writer_process.c

# Auto-generate object lists
simple_pipe_OBJS   = $(simple_pipe_SRCS:.c=.o)
main_OBJS          = $(main_SRCS:.c=.o)
reader_process_OBJS = $(reader_process_SRCS:.c=.o)
writer_process_OBJS = $(writer_process_SRCS:.c=.o)

# Default target
all: $(EXECS)

# Link rules (each exec gets its OBJS)
simple_pipe: $(simple_pipe_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

main: $(main_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

reader_process: $(reader_process_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

writer_process: $(writer_process_OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

# Generic compile rule for .c -> .o
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean everything
clean:
	rm -f *.o $(EXECS)

# Fresh build
fresh: clean all

