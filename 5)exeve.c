#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 20

int a[1000];

// Function to perform the bubble sort algorithm
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, n, ele, pid;
    char *str1[MAX];
    char str[5];

    // Input the size of the array
    printf("Enter size of Elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter %d Elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        printf("Error while creating a new process...!!!");
    } else if (pid > 0) {
        // Parent process

        // Sort the array using bubble sort
        bubble_sort(a, n);

        // Print the sorted array
        printf("\nAfter sorting:\t");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        // Prepare an array of strings from the sorted integers
        for (i = 0; i < MAX; i++) {
            str1[i] = NULL;
        }

        for (i = 0; i < n; i++) {
            sprintf(str, "%d", a[i]);
            str1[i] = strdup(str);
        }

        // Execute the "Reverse" program with the sorted string array
        execve("./Reverse", str1, NULL);

        // If execve fails, this code will not be reached
        printf("EXECVE not called..!!!");
    }
}

