#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 20

int a[MAX];

int main(int argc, char *argv[]) {
    int i;

    // Convert command line arguments to integers and store them in the 'a' array
    for (i = 0; i < argc; i++) {
        a[i] = atoi(argv[i]);
    }

    // Print the reversed array
    printf("Reversed Array:");
    for (int i = argc - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Print a message to indicate that EXECVE() was called
    printf("EXECVE() called");

    return 0;
}

