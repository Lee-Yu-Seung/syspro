#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd;
    char savedText[10][100] = {0, };
    char buf;
    int row = 0, col = 0;
    
    int i, start, end, num; 
    char input[100];
    char *token;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("File open error\n");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
            savedText[row][col] = '\0';
            row++;
            col = 0;
        } else {
            savedText[row][col] = buf;
            col++;
        }
    }
    close(fd);

    printf("File read success\n");
    printf("Total Line : %d\n", row);
    printf("You can choose 1 ~ %d Line\n", row);
    printf("Pls 'Enter' the line to select : ");

    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    if (input[0] == '*') { 
        for (i = 0; i < row; i++) {
            printf("%s\n", savedText[i]);
        }
    } 
    else if (strchr(input, '-')) {
        sscanf(input, "%d-%d", &start, &end);
        for (i = start - 1; i < end && i < row; i++) {
            printf("%s\n", savedText[i]);
        }
    } 
    else if (strchr(input, ',')) {
        token = strtok(input, ", ");
        while (token != NULL) {
            num = atoi(token);
            if (num > 0 && num <= row) {
                printf("%s\n", savedText[num - 1]);
            }
            token = strtok(NULL, ", ");
        }
    } 
    else {
        num = atoi(input);
        if (num > 0 && num <= row) {
            printf("%s\n", savedText[num - 1]);
        }
    }

    return 0;
}
