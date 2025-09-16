#include "processes.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LEN 80

void parent_process(int fd) {
    char buff[MAX_LEN];
    int status;
    pid_t cpid;

    for (;;) {
        char *str = fgets(buff, MAX_LEN, stdin);
        if (str == NULL)
            break;
        int ret = write(fd, buff, MAX_LEN);
        if (ret == -1) {
            perror("write");
            break;
        }
    }

    close(fd);
    cpid = wait(&status);
}

void child_process(int fd) {
    char buff[MAX_LEN];
    int ret;

    for (;;) {
        ret = read(fd, buff, MAX_LEN);
        if (ret <= 0)  // EOF or error
            break;
        printf("C: received from parent: %s\n", buff);
    }

    close(fd);
}

