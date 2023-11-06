#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ 25

int main() {
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;

    // Locate the shared memory segment created by the server
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1) { // Attach segment to the database
        perror("shmat");
        exit(1);
    }

    // Read the message from the shared memory
    printf("Client reading data from Server:\n");
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    printf("\n");

    // Detach from the shared memory segment
    shmdt(shm);

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

