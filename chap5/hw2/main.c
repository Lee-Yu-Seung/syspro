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
    int i;

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

    for (i = row - 1; i >= 0; i--) {
        printf("%s\n", savedText[i]);
    }

    return 0;
}
