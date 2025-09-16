#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"
#define MAX_LEN 80

int main(int argc, char *argv[]) {
    char buff[MAX_LEN];

    // create FIFO (ignore error if it exists)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
    }

    int fifo = open(FIFO_NAME, O_RDONLY);
    if (fifo == -1) {
        perror("open");
        return 1;
    }

    printf("Pipe is open for read\n");

    for (;;) {
        int ret = read(fifo, buff, MAX_LEN - 1);
        if (ret <= 0)  // EOF or error
            break;

        buff[ret] = '\0';
        printf("Received from Parent: %s", buff);
        fflush(stdout);
    }

    close(fifo);
    return 0;
}

