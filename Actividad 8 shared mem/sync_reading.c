#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "sem_utils.h"

int main() {
    char *buff;

    // Get shared memory
    int shm_id = shmget(SHM_KEY, MAX_LEN, 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(-1);
    }

    buff = shmat(shm_id, 0, 0);
    if (buff == (char *)-1) {
        perror("shmat");
        exit(-1);
    }

    // Get semaphore
    int sem_id = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        perror("semget");
        exit(-1);
    }

    printf("Reader waiting for updates...\n");

    while (1) {
        sem_wait(sem_id);                 // Wait for writer signal
        printf("Shared memory updated: %s\n", buff);
    }

    shmdt(buff);
    return 0;
}

