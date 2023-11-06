#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#define MAX_BUFFER 1024

int main() {
    int fd, wr;
    char *avfifo = "avfifo";
    char buff[MAX_BUFFER], str[MAX_BUFFER];
    int words = 1, len = 0, i = 0, line = 1, c = 0;
    FILE *fp;
    int fd1;
    char *avfifo1 = "avfifo1";

    // Create two named pipes (FIFOs) with permissions 0666
    mkfifo(avfifo1, 0666);
    mkfifo(avfifo, 0666);

    // Open the first FIFO (avfifo) for reading and writing
    fd = open(avfifo, O_RDWR);

    printf("\n\nEnter a sentence ending with 0:\n");

    // Read characters from the user until '0' is entered
    while (str[i] != '0') {
        i++;
        scanf("%c", &str[i]);
    }

    // Write the sentence to the first FIFO
    write(fd, str, sizeof(str));

    // Reset variables
    i = 0;
    c = 0;

    // Read the response from the first FIFO
    read(fd, buff, MAX_BUFFER);
    printf("\nFirst Message received: %s\n", buff);

    // Count the number of characters, words, and lines in the received message
    while (buff[i] != '0') {
        if (buff[i] == ' ' || buff[i] == '\n') {
            words++;
            if (buff[i] == '\n') {
                line++;
            }
        } else {
            c++;
        }
        i++;
    }

    // Print the character, word, and line counts
    printf("\nTotal characters=%d\n", c);
    printf("\nTotal words=%d\n", words);
    printf("\nTotal lines=%d\n", line);

    // Open a file named "test.txt" for writing
    fp = fopen("test.txt", "w+");

    // Write the character, word, and line counts to the file
    fprintf(fp, "\nTotal characters=%d\n", c);
    fprintf(fp, "\nTotal words=%d\n", words);
    fprintf(fp, "\nTotal lines=%d\n", line);
    fputs("This is testing for fputs...\n", fp);

    // Close the file
    fclose(fp);

    // Close the first FIFO
    close(fd);

    // Open the second FIFO (avfifo1) for reading and writing
    fd1 = open(avfifo1, O_RDWR);

    // Write the character, word, and line counts to the second FIFO
    wr = write(fd1, &c, sizeof(c));
    wr = write(fd1, &words, sizeof(words));
    wr = write(fd1, &line, sizeof(line));

    if (wr == -1) {
        printf("\nError writing in the second pipe..!\n");
        return 0;
    } else {
        printf("\nSuccessful writing in the second pipe..!\n");
    }

    // Close the second FIFO
    close(fd1);

    return 0;
}

