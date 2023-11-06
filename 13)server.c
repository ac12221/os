#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHMSZ 25

int main() {
    int shmid, cnt = 0;
    key_t key;
    char *shm, *s;
    char *str;
    str = (char *)malloc(sizeof(char) * 15);
    key = 5678;

    // Create or access the shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) { // Creating the segment
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1) { // Attaching segment to database
        perror("shmat");
        exit(1);
    }

    // s is a pointer for traversal, shm points to the start of the shared memory segment

    s = shm;

    // Writing a message to shared memory
    printf("\nEnter message from Server to Client: ");
    scanf("%[^\n]s", str);
    for (cnt = 0; str[cnt] != '\0'; cnt++) {
        *s++ = str[cnt];
    }

    // Put a null character at the end of the message
    *s = '\0';

    // Detach from the shared memory segment
    shmdt(shm);

    return 0;
}

