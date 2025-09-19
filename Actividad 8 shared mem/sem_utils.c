// sem_utils.c
#include "sem_utils.h"
#include <sys/sem.h>
#include <stdio.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// Initialize semaphore
int sem_init(int semid, int val) {
    union semun arg;
    arg.val = val;
    return semctl(semid, 0, SETVAL, arg);
}

// P operation
int sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0};
    return semop(semid, &sb, 1);
}

// V operation
int sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0};
    return semop(semid, &sb, 1);
}

