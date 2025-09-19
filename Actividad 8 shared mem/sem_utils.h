// sem_utils.h
#ifndef SEM_UTILS_H
#define SEM_UTILS_H

#include <sys/sem.h>

// Initialize semaphore to a given value
int sem_init(int semid, int val);

// P operation (wait)
int sem_wait(int semid);

// V operation (signal)
int sem_signal(int semid);

#endif

