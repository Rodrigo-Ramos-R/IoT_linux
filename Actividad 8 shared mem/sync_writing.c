#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "sem_utils.h"

int main() {
    char *buff;

    // Create shared memory
    int shm_id = shmget(SHM_KEY, MAX_LEN, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget");
        exit(-1);
    }

    buff = shmat(shm_id, 0, 0);
    if (buff == (char *)-1) {
        perror("shmat");
        exit(-1);
    }

    // Create semaphore
    int sem_id = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        perror("semget");
        exit(-1);
    }

    // Initialize semaphore to 0 (nothing to read yet)
    sem_init(sem_id, 0);

    printf("Writer ready. Type messages to send:\n");

    char input[MAX_LEN];
    while (fgets(input, MAX_LEN, stdin) != NULL) {
        input[strcspn(input, "\n")] = 0; // strip newline
        strncpy(buff, input, MAX_LEN);
        sem_signal(sem_id);             // Notify reader
    }

    shmdt(buff);
    return 0;
}

